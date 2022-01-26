cmake_minimum_required(VERSION 3.0...3.18)

project(hello_world VERSION 1.0.0)

message(STATUS "Project name: ${PROJECT_NAME}")
message(STATUS "Project source dir: ${PROJECT_SOURCE_DIR}")
message(STATUS "CMake bin dir: ${CMAKE_BINARY_DIR}")
message(STATUS "Project ver: ${PROJECT_VERSION}")

set(SRCDIR
    ${PROJECT_SOURCE_DIR}/Src
    CACHE PATH "Location of current project source files"
    FORCE
)

set(HEADERDIR 
 #[[0]] ${PROJECT_SOURCE_DIR}/Include
        CACHE PATH "Location of current projet's header files" 
        FORCE
)

set(SUBMODULESDIR 
 #[[0]] ${PROJECT_SOURCE_DIR}/submodules
        CACHE PATH "Location of current projet's header files" 
        FORCE
)

list(GET HEADERDIR 0 HEADERDIR0)
message(STATUS  "Src dircetory: ${SRCDIR}")
message(STATUS  "Include dircetory: ${HEADERDIR}")
message(STATUS  "Submodules directory: ${SUBMODULESDIR}")

# include dir
include_directories(${HEADERDIR})
include_directories(${SUBMODULESDIR}/services)
include_directories(${SUBMODULESDIR}/ext/glfw/include)
include_directories(${SUBMODULESDIR}/ext/glfw/deps)

# build libs
add_library(foo ${SRCDIR}/foo.cpp)
add_library(dbgUtils ${SRCDIR}/dbgUtils.cpp)

# submodules
add_subdirectory(${SUBMODULESDIR})

# build app
add_executable(app ${SRCDIR}/main.cpp)

# add precompiled headers
target_precompile_headers(foo PUBLIC ${HEADERDIR0}/pch.h)
target_precompile_headers(dbgUtils PUBLIC ${HEADERDIR0}/pch.h)
target_precompile_headers(app PUBLIC ${HEADERDIR0}/pch.h)

target_compile_definitions(
    app
    PRIVATE
    RAW_INTERFACE_SERVICES
)

# link
target_link_libraries(app foo dbgUtils services glfw)