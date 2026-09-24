cmake_minimum_required(VERSION 3.10)

#------------------------------------------------------------------------------#

project("PROTON_RECRUITMENT_CPP" LANGUAGES C CXX)

#------------------------------------------------------------------------------#

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#------------------------------------------------------------------------------#

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

#------------------------------------------------------------------------------#

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/3rdparty/googletest)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/tests)

#------------------------------------------------------------------------------#
