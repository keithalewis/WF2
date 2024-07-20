cmake_minimum_required(VERSION 3.15...3.27)
project(Matrix VERSION 1.0 LANGUAGES CXX)

if (CMAKE_VERSION VERSION_LESS 3.18)
  set(DEV_MODULE Development)
else()
  set(DEV_MODULE Development.Module)
endif()

find_package(Python 3.8 COMPONENTS Interpreter ${DEV_MODULE} REQUIRED)

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

find_package(SWIG 4.0 COMPONENTS python)
if(SWIG_FOUND)
  message("SWIG found: ${SWIG_EXECUTABLE}")
endif()
include(UseSWIG)
set(UseSWIG_TARGET_NAME_PREFERENCE STANDARD)


set_property(SOURCE Matrix.i PROPERTY CPLUSPLUS ON)
set_property(SOURCE Matrix.i PROPERTY SWIG_MODULE_NAME pyMatrix)
swig_add_library(Matrix
  TYPE MODULE
  LANGUAGE python
  SOURCES Matrix.i)

target_include_directories(Matrix
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
	${Python3_INCLUDE_DIRS})

if(FALSE)
target_link_libraries(pyMatrix PRIVATE ${PROJECT_NAMESPACE}::Matrix)

target_include_directories(pyMatrix
	PRIVATE ${PYTHON_INCLUDE_DIRS})
set_property(TARGET pyMatrix PROPERTY SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON)

target_link_libraries(pyMatrix PRIVATE ${PROJECT_NAMESPACE}::Matrix)


target_include_directories(pyMatrix
	PUBLIC${Python3_INCLUDE_DIRS})
set_property(TARGET pyMatrix PROPERTY SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON)

endif()
