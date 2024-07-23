cmake_minimum_required (VERSION 3.22)
project(Matrix VERSION 1.0 LANGUAGES CXX)

# set required C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# build 64-bit with optimization (Windows)
# cmake -S . -B build_windows_x64 -A x64
# cmake --build build_windows_x64 --config Release

# build 64-bit without optimization (Windows)
# cmake -S . -B build_windows_x64 -A x64
# cmake --build build_windows_x64 --config Debug

# should make these find_package calls required
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(SWIG 4.0 REQUIRED COMPONENTS python)

include(UseSWIG)
set(UseSWIG_TARGET_NAME_PREFERENCE STANDARD)

set_property(SOURCE Matrix.i PROPERTY CPLUSPLUS ON)
set_property(SOURCE Matrix.i PROPERTY SWIG_MODULE_NAME pyMatrix)
swig_add_library(Matrix
  TYPE MODULE
  LANGUAGE python
  SOURCES Matrix.i
  # forgot OUTPUT_DIR; the generated pyMatrix.py is in top-level build dir
  OUTPUT_DIR ${CMAKE_BINARY_DIR}/$<CONFIG>)

target_include_directories(Matrix
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
	${Python3_INCLUDE_DIRS})

# forgot target_link_libraries call
target_link_libraries(Matrix PRIVATE Python3::Module)

# add test program
add_executable(WF2.t WF2.t.cpp)

