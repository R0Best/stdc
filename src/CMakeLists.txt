add_library(stdc STATIC
    stdc/core/core.c

    stdc/type/base.c
    stdc/type/category.c
    stdc/type/type.c
    stdc/type/bool.c
    stdc/type/byte.c
    stdc/type/char.c
    stdc/type/uinteger.c
    stdc/type/sinteger.c
    stdc/type/float.c
    stdc/type/none.c
    stdc/type/any.c
)

target_include_directories(stdc
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)

set(STDC_DIAGNOSTICS
    -Weverything
    -Werror
    -Wno-padded
    -Wno-covered-switch-default
    -Wno-unsafe-buffer-usage
)

set(STDC_SAFETY_FLAGS
    -ftrivial-auto-var-init=zero
    -fno-common
    -Wvla
    -Wcast-align
)

set(STDC_SANITIZER_TRAPS
    -fsanitize=undefined
    -fno-sanitize=function
    -fsanitize=kcfi
    -fsanitize=undefined
    -fsanitize-trap=all
)

set(STDC_HARDENING
    -fcf-protection=full
    -fsanitize=kcfi
)

target_compile_options(stdc PRIVATE
    ${COMPILER_FLAGS_FREESTANDING}
    ${STDC_DIAGNOSTICS}
    ${STDC_SAFETY_FLAGS}
    ${STDC_SANITIZER_TRAPS}
    ${STDC_HARDENING}
)

target_link_options(stdc PRIVATE
    ${LINKER_FLAGS_FREESTANDING}
    "-fno-builtin"
)
