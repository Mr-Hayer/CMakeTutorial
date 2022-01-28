cmake_minimum_required(VERSION 3.10...3.18)

# project
project(CMakeTutorial VERSION 1.0.0)

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
add_executable(${PROJECT_NAME} ${SRCDIR}/main.cpp)

# add precompiled headers
target_precompile_headers(
    foo
    PUBLIC ${HEADERDIR0}/pch.h
)
target_precompile_headers(
    dbgUtils
    PUBLIC ${HEADERDIR0}/pch.h
)
target_precompile_headers(
    ${PROJECT_NAME} 
    PUBLIC ${HEADERDIR0}/pch.h
)

# activate any preprocessor on target
target_compile_definitions(
    ${PROJECT_NAME}
    PRIVATE RAW_INTERFACE_SERVICES
)

# add compiler flags on target
set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Versioning
configure_file(CMakeTutorialVersioning.h.in CMakeTutorialVersioning.h)
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${PROJECT_BINARY_DIR}
)

# link
target_link_libraries(
    ${PROJECT_NAME}
    foo
    dbgUtils
    services
    glfw
)