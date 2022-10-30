find_program(GLSLC
    glslc
    HINTS ${ANDROID_NDK}/shader-tools/*/
    ${CMAKE_ANDROID_NDK}/shader-tools/*/
    #NO_CACHE
)

find_program(GLSLANG_VALIDATOR
    glslangValidator
    #NO_CACHE
)

set(SHADER_COMPILER "NO-SHADER-COMPILER")
if(GLSLANG_VALIDATOR)
    message("Found glslangValidator: ${GLSLANG_VALIDATOR}")
    set(SHADER_COMPILER ${GLSLANG_VALIDATOR} -V)
endif()

if(GLSLC)
    message("Found glslc: ${GLSLC}")
    set(SHADER_COMPILER ${GLSLC})
endif()

if(NOT GLSLANG_VALIDATOR AND NOT GLSLC)
    message(FATAL_ERROR "Unable to find glslangValidator or glslc shader compiler")
endif()


message("Using shader compiler: ${SHADER_COMPILER}")

set(SHADER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/shaders/)
FILE(GLOB_RECURSE SHADER_FILES RELATIVE ${SHADER_DIR}
    ${SHADER_DIR}/*.vert
    ${SHADER_DIR}/*.frag
    ${SHADER_DIR}/*.tesc
    ${SHADER_DIR}/*.tese
    ${SHADER_DIR}/*.comp
)

add_custom_target(spirv-shaders)

foreach(SHADER_FILE ${SHADER_FILES})
    string(REPLACE "/" "_" SHADER_NAME ${SHADER_FILE})
    string(REPLACE "\\" "_" SHADER_NAME ${SHADER_NAME})

    set(SHADER_INPUT ${SHADER_DIR}/${SHADER_FILE})
    set(SHADER_OUTPUT ${SHADER_DIR}/${SHADER_FILE}.spv)

    add_custom_command(OUTPUT ${SHADER_OUTPUT}
        DEPENDS ${SHADER_INPUT}
        COMMAND ${SHADER_COMPILER} ${SHADER_INPUT} -o ${SHADER_OUTPUT}
    )

    set(SHADER_TARGET shader_${SHADER_NAME})
    add_custom_target(${SHADER_TARGET} DEPENDS ${SHADER_OUTPUT})

    add_dependencies(spirv-shaders ${SHADER_TARGET})
endforeach()

add_dependencies(mobius spirv-shaders)
