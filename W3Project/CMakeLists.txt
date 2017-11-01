cmake_minimum_required (VERSION 2.6)
project (Neuron)

set(CMAKE_CXX_FLAGS " -W -Wall -pedantic -std=c++11")

enable_testing()
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${googletest_SOURCE_DIR})

add_executable (Neuron Neuron.cpp NeuronMain.cpp)
add_executable (UNITTEST Neuron.cpp UNITTEST.cpp)

target_link_libraries(UNITTEST gtest gtest_main)
add_test(UNITTEST UNITTEST)
