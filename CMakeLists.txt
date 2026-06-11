cmake_minimum_required(VERSION 4.3)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_EXTENSIONS OFF)

project(
  stdc
  VERSION 0.1.0
  LANGUAGES C
)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds are prohibited.")
endif()

option(STDC_ENABLE_LTO "Enable LLVM ThinLTO" ON)
option(STDC_STRICT_ALIASING "Enforce strict aliasing rules for optimization" ON)
option(STDC_STACK_PROTECTOR "Enable stack smashing protection" OFF)
option(STDC_POSITION_INDEPENDENT "Generate Position Independent Code" ON)

set(COMPILER_FLAGS_FREESTANDING
    "-ffreestanding"
    "-nostdlibinc"
    "-fno-builtin"
)

set(LINKER_FLAGS_FREESTANDING
    "-nostdlib"
    "-fuse-ld=lld"
)

set(WARNING_FLAGS_STRICT
    "-Wall"
    "-Wextra"
    "-Wpedantic"
    "-Werror"
    "-Wno-pre-c23-compat"
    "-Wno-c++98-compat"
    "-Wcast-align"
    "-Wconversion"
    "-Wshadow-all"
    "-Wundef"
    "-Wdouble-promotion"
)

add_compile_options(${WARNING_FLAGS_STRICT})

if(STDC_ENABLE_LTO)
  include(CheckIPOSupported)
  check_ipo_supported(RESULT lto_supported)
  if(lto_supported)
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
    add_compile_options("-flto=thin")
  else()
    message(WARNING "LTO requested but not supported.")
  endif()
endif()

if(STDC_STRICT_ALIASING)
  add_compile_options("-fstrict-aliasing" "-Wstrict-aliasing=2")
else()
  add_compile_options("-fno-strict-aliasing")
endif()

if(STDC_STACK_PROTECTOR)
  add_compile_options("-fstack-protector-strong")
else()
  add_compile_options("-fno-stack-protector")
endif()

if(STDC_POSITION_INDEPENDENT)
  set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()

add_subdirectory(src)
enable_testing()
add_subdirectory(tests)
