cmake_minimum_required(VERSION 4.0)
project(LinMSTest)

set(CMAKE_CXX_STANDARD 23)

option("MSVC_TESTING_FRAMEWORK_BUILD_TEST_APP" "Whether to build the test app for the framework" ON)

set("${PROJECT_NAME}_INTERNAL_LIB_NAME" "__${PROJECT_NAME}_msvctest")
add_library("${${PROJECT_NAME}_INTERNAL_LIB_NAME}" STATIC)
add_subdirectory("${CMAKE_SOURCE_DIR}/src")
add_subdirectory("${CMAKE_SOURCE_DIR}/include")

add_library(msvctest::msvctest ALIAS "${${PROJECT_NAME}_INTERNAL_LIB_NAME}")

if (MSVC_TESTING_FRAMEWORK_BUILD_TEST_APP)
    add_subdirectory(${PROJECT_SOURCE_DIR}/testApp)
endif()