cmake_minimum_required(VERSION 3.0...3.18)

project(hello_world VERSION 1.0.0)

message(STATUS "Project name: ${PROJECT_NAME}")
message(STATUS "Project source dir: ${PROJECT_SOURCE_DIR}")
message(STATUS "CMake bin dir: ${CMAKE_BINARY_DIR}")
message(STATUS "Project ver: ${PROJECT_VERSION}")

set(SRCDIR
    "/home/harvinder/CMakeTutorial/Src/" 
    CACHE PATH "Location of current project source files"
    FORCE
)

set(HEADERDIR 
 #[[0]] "/home/harvinder/CMakeTutorial/Include"
 #[[1]] "${PROJECT_SOURCE_DIR}/submodule/services" 
        CACHE PATH "Location of current projet's header files" 
        FORCE
)

list(GET HEADERDIR 0 HEADERDIR0)
list(GET HEADERDIR 1 HEADERDIR1)
message(STATUS  "Src dircetory: ${SRCDIR}")
message(STATUS  "Include dircetory: ${HEADERDIR}")

# include dir
include_directories(${HEADERDIR})

# build libs
add_library(foo ${SRCDIR}/foo.cpp)
add_library(dbgUtils ${SRCDIR}/dbgUtils.cpp)

# submodules
add_subdirectory(${PROJECT_SOURCE_DIR}/submodule)

# build app
add_executable(app ${SRCDIR}/main.cpp)

# add precompiled headers
target_precompile_headers(foo PUBLIC ${HEADERDIR0}/pch.h)
target_precompile_headers(dbgUtils PUBLIC ${HEADERDIR0}/pch.h)
target_precompile_headers(app PUBLIC ${HEADERDIR0}/pch.h)

target_compile_definitions(
    services
    PRIVATE
    RAW_INTERFACE_SERVICES
)

target_compile_definitions(
    app
    PRIVATE
    RAW_INTERFACE_SERVICES
)

# linking directories

# link
target_link_libraries(app foo dbgUtils services)