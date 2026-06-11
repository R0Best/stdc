#ifndef STDC_TYPE_CHAR_H
#define STDC_TYPE_CHAR_H

#include "stdc/core/core.h"
#include "stdc/type/base.h"
/* --- Character type --- */
#if defined(__GNUC__) || defined(__clang__)

/* C8 */
#if __INTMAX_WIDTH__ >= 8
#define STDC_DEFINED_C8
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(8),
    C8,
    STDC_DEF_UNSIGNED_LIMITS(C8)
)
#endif

/* C16 */
#if __INTMAX_WIDTH__ >= 16
#define STDC_DEFINED_C16
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(16),
    C16,
    STDC_DEF_UNSIGNED_LIMITS(C16)
)
#endif

/* C32 */
#if __INTMAX_WIDTH__ >= 32
#define STDC_DEFINED_C32
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(32),
    C32,
    STDC_DEF_UNSIGNED_LIMITS(C32)
)
#endif

/* Char */
#if __INTMAX_WIDTH__ >= 8
#define STDC_DEFINED_CHAR
STDC_DEFINE_PRIMITIVE_TYPE(
    C8,
    Char,
    STDC_DEF_UNSIGNED_LIMITS(Char)
)
#endif

#elif defined(_MSC_VER)

#error "MSVC support is not implemented yet"

#else

#error "Unsupported compiler"

#endif

typedef enum : __UINT32_TYPE__ {
#define V(category, name, type, member, index) STDC_TYPE_ENUM_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/char.def"
#undef V
} CharType;

typedef struct {
  CharType type;
  unsigned _BitInt(32) flags;
  union {
#define V(category, name, type, member, index) STDC_TYPE_UNION_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/char.def"
#undef V
  };
} STDC_MAY_ALIAS CharVal;

#endif /* STDC_TYPE_CHAR_H */
