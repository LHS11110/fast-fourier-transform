cmake_minimum_required(VERSION 3.10)
project(FastFourierTransform VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(fft src/fft.cpp)
target_include_directories(fft PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Enable testing
enable_testing()

# Add test executable
add_executable(test_fft tests/test_fft.cpp)
target_link_libraries(test_fft PRIVATE fft)

# Register test with CTest
add_test(NAME test_fft COMMAND test_fft)
