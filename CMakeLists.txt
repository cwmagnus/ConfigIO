cmake_minimum_required (VERSION 3.8)

set (CMAKE_CXX_STANDARD 11)

project(ConfigIO)

option(BUILD_STATIC_LIBS "Build the static library" ON)
option(BUILD_SHARED_LIBS "Build the shared library" ON)
option(BUILD_TESTS "Build library tests" OFF)

file(GLOB CONFIG_IO_HEADERS "include/ConfigIO/*.h")
file(GLOB CONFIG_IO_SOURCE "src/ConfigIO/*.cpp")

# Add source to this project's executable.
add_library(ConfigIO ${CONFIG_IO_HEADERS} ${CONFIG_IO_SOURCE})
target_include_directories(ConfigIO PRIVATE ${CMAKE_SOURCE_DIR}/include)

# TODO: Add tests and install targets if needed.
install(TARGETS ConfigIO DESTINATION lib)
install(FILES ${CONFIG_IO_HEADERS} DESTINATION include/ConfigIO)