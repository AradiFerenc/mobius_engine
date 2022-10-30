cmake_minimum_required(VERSION 3.20)
project(mobius_linux)

include(${CMAKE_CURRENT_SOURCE_DIR}/../CMakeLists.txt)

set(BUILD_LINUX TRUE)
set(BUILD_DEBUG FALSE)

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(BUILD_DEBUG TRUE)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

GetDependencies()

add_subdirectory(${PROJECT_ROOT}/external ./external)
add_subdirectory(${PROJECT_ROOT}/mobius ./mobius)

add_subdirectory(${PROJECT_ROOT}/assets ./assets)

add_executable(mobius_linux main.cpp)

target_include_directories(mobius_linux INTERFACE
    ${PROJECT_ROOT}/mobius
)

if (${BUILD_DEBUG})
    target_compile_definitions(mobius_linux
    PRIVATE
    DEBUG
    ENABLE_DEBUG_LOG
    )
endif ()

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

target_link_libraries(mobius_linux PUBLIC
    mobius
    external
    ${OPENGL_LIBRARIES}
)
