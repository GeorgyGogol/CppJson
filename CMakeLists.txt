cmake_minimum_required(VERSION 3.15)

#
# Project
#
project(
    CppJson
    VERSION 0.1.1
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

message (STATUS "Runing configure CppJson")

#
#
#
option(TESTING "Build unit test project" ON)
option(BUILD_STATIC_LIB "Buid as static lib" OFF)

#
# Set sources
#
set(
    SHARED_INCLUDE_PATH
    include
    include/CppJson
)

set(
    SHARED_H_FILES
    include/CppJson.h
    include/CppJson/JsonArray.h
    include/CppJson/JsonBase.h
    include/CppJson/JsonFuncs.h
    include/CppJson/JsonObject.h
    include/CppJson/ObjectValueType.h
)

set(
    INCULDE_PATH
    sources
    sources/support
)

set(
    H_FILES
    sources/support/JsonParser.h
)

set(
    SRC_FILES
    sources/JsonArray.cpp
    sources/JsonFuncs.cpp
    sources/JsonObject.cpp
    sources/ObjectValueType.cpp
    sources/support/JsonParser.cpp
)

#
# target creating
#
if (BUILD_STATIC_LIB)
    message (STATUS "Project configured as static library")
    add_library(CppJson STATIC)
else()
    message (STATUS "Project configured as shared library (default)")
    add_library(CppJson SHARED)
endif(BUILD_STATIC_LIB)

add_library(modules::CppJson ALIAS CppJson)

target_include_directories(CppJson PUBLIC ${SHARED_INCLUDE_PATH})
target_sources(CppJson PUBLIC ${SHARED_H_FILES})

target_include_directories(CppJson PRIVATE ${INCULDE_PATH})
target_sources(CppJson PRIVATE ${H_FILES})
target_sources(CppJson PRIVATE ${SRC_FILES})

set_target_properties(CppJson PROPERTIES
    POSITION_INDEPENDENT_CODE ${BUILD_STATIC_LIB}
)


# 
include(GenerateExportHeader)
generate_export_header(CppJson)
target_include_directories(CppJson PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

if(TESTING)
    message(WARNING "Unit test project is not remaded to CMake")
    # add_subdirectory(tests)
endif(TESTING)

