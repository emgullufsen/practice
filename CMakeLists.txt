cmake_minimum_required(VERSION 3.22.2 FATAL_ERROR)

project(practice)

set(CMAKE_CXX_STANDARD 20)

set(practice_COMPILER_OPTIONS_CLANG -g -fcolor-diagnostics -Wall -Werror
-std=c++20)

set(practice_COMPILER_OPTIONS_GNU -Wall -g -fdiagnostic-color=always -Werror -std=c++2a)

# executable is called practiceUT (Unit Test)
add_executable(practiceUT
	${CMAKE_CURRENT_SOURCE_DIR}/src/ch1.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/ch2.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/ch1_test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/ch2_test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/main_test.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/src/gtest-all.cc)

target_include_directories(practiceUT PRIVATE SYSTEM
	${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest
	${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include
	${CMAKE_CURRENT_SOURCE_DIR}/include)

set(executables practiceUT)

target_compile_options(practiceUT PRIVATE
	"$<$<CXX_COMPILER_ID:Clang>:${practice_COMPILER_OPTIONS_CLANG}>")

if(UNIX)
	target_link_libraries(practiceUT PRIVATE pthread)
endif()
