set(CURRENT_DIR ${CMAKE_CURRENT_SOURCE_DIR})

target_sources(mobius INTERFACE
    ${CURRENT_DIR}/window.cpp
)

target_include_directories(mobius INTERFACE ${CURRENT_DIR}

)
