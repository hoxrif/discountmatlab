cmake_minimum_required(VERSION 3.0.0)
project(test_discountmatlab VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

file(GLOB matrix_files "headers/matrix_array.hpp","headers/matrix_shape.hpp")

add_executable(test_discountmatlab 
example/main.cpp 
src/matlabdiscount.cpp
${matrix_files}
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
