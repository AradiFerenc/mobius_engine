set(PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../../)

function(GetDependencies)
    find_package(Git QUIET)
    if (GIT_FOUND AND EXISTS "${PROJECT_ROOT}/.git")
        option(GIT_SUBMODULE "Check submodules during build" ON)
        if (GIT_SUBMODULE)
            message(STATUS "Submodule update")
            execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
            if (NOT GIT_SUBMOD_RESULT EQUAL "0")
                message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, aborting build!")
            endif ()
        endif ()
    endif ()
endfunction()