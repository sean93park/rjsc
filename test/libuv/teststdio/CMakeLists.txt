cmake_minimum_required (VERSION 2.8) 
project (teststdio) 
set (EXEC_NAME "teststdio")

enable_language (C)
enable_language (CXX)

add_definitions (-D__STDC_LIMIT_MACROS)

set (MY_FLAGS "-Wno-invalid-offsetof")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_FLAGS}")

include_directories (
	/opt/js/include
)

set (SOURCE_FILES
	./src/teststdio.cpp
)

set (EXTRA_LIBS
	-lrt -lpthread -lnsl -ldl
	/opt/js/lib/libuv.a
)

add_executable (${EXEC_NAME} ${SOURCE_FILES})
target_link_libraries (${EXEC_NAME} ${EXTRA_LIBS})
