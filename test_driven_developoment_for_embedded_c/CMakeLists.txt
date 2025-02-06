cmake_minimum_required(VERSION 3.14)
project(Tdd)

set(CMAKE_CXX_STANDARD 17)

set(TARGET_GROUP production CACHE STRING "Group to build")

include(FetchContent)

add_subdirectory(src)

if(TARGET_GROUP STREQUAL production) 
  # do nothing
elseif(TARGET_GROUP STREQUAL test) 
  FetchContent_Declare(
    CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG v4.0
  )
  FetchContent_MakeAvailable(CppUTest)
  add_subdirectory(test)
  include(CTest)
else()
  message(FATAL_ERROR "Given TARGET_GROUP unknown")
endif()

