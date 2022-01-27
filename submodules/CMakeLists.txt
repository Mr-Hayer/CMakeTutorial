add_library(services ${SUBMODULESDIR}/services/services_interfaces.cpp)

target_compile_definitions(
    services
    PRIVATE
    RAW_INTERFACE_SERVICES
)

# auto update submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # GIT FOUND
    option(GIT_SUBMODULES "Enable auto update and init for git submodules" ON)
    if(GIT_SUBMODULES)
        message(STATUS "Updating all submodules...")
        execute_process(
            COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_RESULT
        )
        if (NOT GIT_RESULT EQUAL "0")
            message(FATAL_ERROR "Git submodule update failed with error!!")
        else()
            message(STATUS "Update succeeded...")
        endif()
    endif()
else()
    message(STATUS "Git not found!!")
endif()

add_subdirectory(${SUBMODULESDIR}/ext/glfw)