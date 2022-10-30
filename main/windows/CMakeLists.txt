cmake_minimum_required(VERSION 3.20)
project(mobius_windows)

include(${CMAKE_CURRENT_SOURCE_DIR}/../CMakeLists.txt)

set(BUILD_WINDOWS TRUE)
set(BUILD_DEBUG FALSE)

if (${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(BUILD_DEBUG TRUE)
endif()

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++")

IF(${BUILD_DEBUG})
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDEBUG")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DENABLE_DEBUG_LOG")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DENABLE_ASSERTIONS")

    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDEBUG")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DENABLE_DEBUG_LOG")
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DENABLE_ASSERTIONS")
ENDIF()

SET(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
SET(BUILD_SHARED_LIBS TRUE)
SET_PROPERTY(GLOBAL PROPERTY USE_FOLDERS ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPLATFORM_WINDOW")


add_definitions(-DASSET_PATH="${PROJECT_ROOT}/assets")

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DNOMINMAX -D_USE_MATH_DEFINES")

GetDependencies()

add_subdirectory(${PROJECT_ROOT}/external ./external)
add_subdirectory(${PROJECT_ROOT}/mobius ./mobius)

add_subdirectory(${PROJECT_ROOT}/assets ./assets)

FILE(GLOB_RECURSE SOURCE_LIST
    ${PROJECT_ROOT}/mobius/*.cpp
    ${PROJECT_ROOT}/mobius/*.h
)
SOURCE_GROUP(TREE ${PROJECT_ROOT} FILES ${SOURCE_LIST})

add_executable(mobius_windows
    WIN32
    ${SOURCE_LIST}
    main.cpp
)

target_include_directories(mobius_windows INTERFACE
    ${PROJECT_ROOT}/mobius
)

target_compile_definitions(mobius_windows
    PRIVATE
    VK_USE_PLATFORM_WIN32_KHR
)

target_link_libraries(mobius_windows PUBLIC
    mobius
    external
)
