#ifndef STDC_TYPE_NONE_H
#define STDC_TYPE_NONE_H

#include "stdc/core/core.h"
#include "stdc/type/base.h"

/* --- Special types --- */
#if defined(__GNUC__) || defined(__clang__)

typedef void None;

#elif defined(_MSC_VER)

#error "MSVC support is not implemented yet"

#else

#error "Unsupported compiler"

#endif

static constexpr typeof(nullptr) NullPtr = nullptr;

/* None is special: void cannot be a union member, so we hand-write
 * the enum and struct. */
typedef enum : __UINT32_TYPE__ {
  TypeNoneNone = ((__UINT32_TYPE__)STDC_TYPE_CATEGORY_None << 16U) | (__UINT32_TYPE__)(1),
} NoneType;

typedef struct {
  NoneType type;
  unsigned _BitInt(32) flags;
} STDC_MAY_ALIAS NoneVal;

#endif /* STDC_TYPE_NONE_H */
