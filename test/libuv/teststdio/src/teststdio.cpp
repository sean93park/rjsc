#include <stdio.h>
#include <uv.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>

#define ASSERT(A) assert(A)

uv_loop_t*  loop;
uv_pipe_t   stdin_pipe;
uv_pipe_t   file_pipe;
uv_tty_t    tty_in;
uv_fs_t     close_req;
int         ttyin_fd;

void alloc_buffer (uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) 
{
  buf->base = (char*)malloc(suggested_size);
  buf->len  = suggested_size;
}

void read_stdin (uv_stream_t *stream, int nread, const uv_buf_t* buf) 
{
  if (nread < 0 ) {
    ASSERT(nread == UV_EOF);
    if (buf->base)
      free(buf->base);
    uv_close((uv_handle_t*)&stdin_pipe, NULL);
    uv_close((uv_handle_t*)&file_pipe, NULL);
    return;
  }
  if (nread == 0) {
    free(buf->base);
    return;
  }

  char  bb[1024];
  memcpy( bb, buf->base, nread );
  bb[nread] = 0;
  printf("> %d %d : %s\n", nread, *buf->base, bb );
  if ( *buf->base == 27 ) {
    if (buf->base)
      free(buf->base);
    uv_close((uv_handle_t*)&stdin_pipe, NULL);
    uv_close((uv_handle_t*)&file_pipe, NULL);
  }
}

int main (int argc, char **argv) 
{
  uv_fs_t file_req;
  int     r;
  int     ttyfd = 0;
  int     stdinfd = 0;

  printf( "=== press ESC to exit\n" );
  loop = uv_default_loop();
    
  ttyin_fd = open("/dev/tty", O_RDONLY, 0);
  r = uv_tty_init(loop, &tty_in, ttyin_fd, 1); // Readable
  r = uv_tty_set_mode(&tty_in, 1); // raw mode 

  ttyfd = uv_fs_open(loop, &file_req, "/dev/tty", O_RDONLY, 0400, NULL);

  uv_pipe_init(loop, &file_pipe, 0);
  uv_pipe_init(loop, &stdin_pipe, 0);
  uv_pipe_open(&file_pipe, ttyfd);
  uv_pipe_open(&stdin_pipe, stdinfd);
  uv_read_start((uv_stream_t*)&stdin_pipe, alloc_buffer, read_stdin);

  uv_run(loop, UV_RUN_DEFAULT);

  r = uv_fs_close(loop, &close_req, file_req.result, NULL);
  uv_fs_req_cleanup(&close_req);

  uv_tty_set_mode(&tty_in, 0);  // must turn off raw mode
  uv_close((uv_handle_t*)&tty_in, NULL);
  close( ttyin_fd );

  return 0;
}
