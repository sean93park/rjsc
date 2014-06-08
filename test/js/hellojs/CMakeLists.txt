cmake_minimum_required (VERSION 2.8) 
project (hellojs) 
set (EXEC_NAME "hellojs")

enable_language (C)
enable_language (CXX)

add_definitions (-D__STDC_LIMIT_MACROS)

set (MY_FLAGS "-Wno-invalid-offsetof")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_FLAGS}")

set (LIBJS_PATH_LIB "${CMAKE_SOURCE_DIR}/../../../out/mozjs24/dist/lib")
set (LIBJS_PATH_INC "${CMAKE_SOURCE_DIR}/../../../out/mozjs24/dist/include")
set (LIBJS_LIBS "${LIBJS_PATH_LIB}/libjs_static.a")
set (NSPRPUB_PATH_LIB "${CMAKE_SOURCE_DIR}/../../../out/nsprpub/dist/lib")
set (NSPRPUB_PATH_INC "${CMAKE_SOURCE_DIR}/../../../out/nsprpub/dist/include")
set (NSPRPUB_LIBS "${NSPRPUB_PATH_LIB}/libnspr4.a")

include_directories (
	${LIBJS_PATH_INC} ${NSPRPUB_PATH_INC}
)

set (EXTRA_LIBS
	-lrt -lpthread -lnsl -ldl ${LIBJS_LIBS} ${NSPRPUB_LIBS}
)

set (SOURCE_FILES
	./src/hellojs.cpp
)
add_executable (${EXEC_NAME} ${SOURCE_FILES})
target_link_libraries (${EXEC_NAME} ${EXTRA_LIBS})
