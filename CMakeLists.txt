cmake_minimum_required(VERSION 3.16)

project(TinyTensor VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(tinytensor
    src/matrix.cpp
)

target_include_directories(tinytensor
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_compile_features(tinytensor PUBLIC cxx_std_17)

if(MSVC)
    target_compile_options(tinytensor PRIVATE /W4)
else()
    target_compile_options(tinytensor PRIVATE -Wall -Wextra -Wpedantic)
endif()

enable_testing()

add_subdirectory(tests)
add_subdirectory(examples)
