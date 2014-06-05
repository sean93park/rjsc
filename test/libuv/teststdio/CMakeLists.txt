cmake_minimum_required (VERSION 2.8) 
project (teststdio) 
set (EXEC_NAME "teststdio")

enable_language (C)
enable_language (CXX)

add_definitions (-D__STDC_LIMIT_MACROS)

set (MY_FLAGS "-Wno-invalid-offsetof")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_FLAGS}")

set (LIBUV_PATH_LIB "${CMAKE_SOURCE_DIR}/../../../out/libuv/.libs")
set (LIBUV_PATH_INC "${CMAKE_SOURCE_DIR}/../../../lib/libuv/include")
set (LIBUV_LIBS "${LIBUV_PATH_LIB}/libuv.a")

include_directories (
	${LIBUV_PATH_INC}
)

set (SOURCE_FILES
	./src/teststdio.cpp
)

set (EXTRA_LIBS
	-lrt -lpthread -lnsl -ldl ${LIBUV_LIBS}
)

add_executable (${EXEC_NAME} ${SOURCE_FILES})
target_link_libraries (${EXEC_NAME} ${EXTRA_LIBS})
