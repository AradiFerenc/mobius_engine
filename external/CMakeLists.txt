add_library(external INTERFACE)

set(GLFW_BUILD_DOCS OFF)

add_subdirectory(glfw)

target_include_directories(
    external INTERFACE glfw/include
)

target_link_directories(
    external INTERFACE glfw/src
)

target_link_libraries(
    external INTERFACE opengl32 glfw
)