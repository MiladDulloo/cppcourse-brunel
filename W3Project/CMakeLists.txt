cmake_minimum_required (Version 2.6)
project (Complex)

set(CMAKE_CXX_FLAGS "-03 -W -Wall -pedantic -std=c++11")
add_executable (complex complex.cpp test_complex.cpp)
