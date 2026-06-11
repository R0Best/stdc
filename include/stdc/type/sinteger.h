#ifndef STDC_TYPE_SINTEGER_H
#define STDC_TYPE_SINTEGER_H

#include "stdc/core/core.h"
#include "stdc/type/base.h"

/* --- Signed integer types --- */
#if defined(__GNUC__) || defined(__clang__)

/* SSize */
#if __INTMAX_WIDTH__ >= __SIZE_WIDTH__
#define STDC_DEFINED_SSIZE
STDC_DEFINE_PRIMITIVE_TYPE(
    signed _BitInt(__SIZE_WIDTH__),
    SSize,
    STDC_DEF_SIGNED_LIMITS(
        SSize,
        unsigned _BitInt(__SIZE_WIDTH__)
    )
)
#endif

/* SPtr */
#if __INTMAX_WIDTH__ >= __INTPTR_WIDTH__
#define STDC_DEFINED_SPTR
STDC_DEFINE_PRIMITIVE_TYPE(
    signed _BitInt(__INTPTR_WIDTH__),
    SPtr,
    STDC_DEF_SIGNED_LIMITS(
        SPtr,
        unsigned _BitInt(__INTPTR_WIDTH__)
    )
)
#endif

/* SMax */
#if __INTMAX_WIDTH__ >= __INTMAX_WIDTH__
#define STDC_DEFINED_SMAX
STDC_DEFINE_PRIMITIVE_TYPE(
    signed _BitInt(__INTMAX_WIDTH__),
    SMax,
    STDC_DEF_SIGNED_LIMITS(
        SMax,
        unsigned _BitInt(__INTMAX_WIDTH__)
    )
)
#endif

/* S8 */
#if __INTMAX_WIDTH__ >= 8
#define STDC_DEFINED_S8
STDC_DEFINE_PRIMITIVE_TYPE(
    signed _BitInt(8),
    S8,
    STDC_DEF_SIGNED_LIMITS(
        S8,
        unsigned _BitInt(8)
    )
)
#endif

/* S16 */
#if __INTMAX_WIDTH__ >= 16
#define STDC_DEFINED_S16
STDC_DEFINE_PRIMITIVE_TYPE(
    signed _BitInt(16),
    S16,
    STDC_DEF_SIGNED_LIMITS(
        S16,
        unsigned _BitInt(16)
    )
)
#endif

/* S32 */
#if __INTMAX_WIDTH__ >= 32
#define STDC_DEFINED_S32
STDC_DEFINE_PRIMITIVE_TYPE(
    signed _BitInt(32),
    S32,
    STDC_DEF_SIGNED_LIMITS(
        S32,
        unsigned _BitInt(32)
    )
)
#endif

/* S64 */
#if __INTMAX_WIDTH__ >= 64
#define STDC_DEFINED_S64
STDC_DEFINE_PRIMITIVE_TYPE(
    signed _BitInt(64),
    S64,
    STDC_DEF_SIGNED_LIMITS(
        S64,
        unsigned _BitInt(64)
    )
)
#endif

/* S128 */
#if __INTMAX_WIDTH__ >= 128
#define STDC_DEFINED_S128
STDC_DEFINE_PRIMITIVE_TYPE(
    signed _BitInt(128),
    S128,
    STDC_DEF_SIGNED_LIMITS(
        S128,
        unsigned _BitInt(128)
    )
)
#endif

/* S256 */
#if __INTMAX_WIDTH__ >= 256
#define STDC_DEFINED_S256
STDC_DEFINE_PRIMITIVE_TYPE(
    signed _BitInt(256),
    S256,
    STDC_DEF_SIGNED_LIMITS(
        S256,
        unsigned _BitInt(256)
    )
)
#endif

/* S512 */
#if __INTMAX_WIDTH__ >= 512
#define STDC_DEFINED_S512
STDC_DEFINE_PRIMITIVE_TYPE(
    signed _BitInt(512),
    S512,
    STDC_DEF_SIGNED_LIMITS(
        S512,
        unsigned _BitInt(512)
    )
)
#endif

/* S1024 */
#if __INTMAX_WIDTH__ >= 1024
#define STDC_DEFINED_S1024
STDC_DEFINE_PRIMITIVE_TYPE(
    signed _BitInt(1024),
    S1024,
    STDC_DEF_SIGNED_LIMITS(
        S1024,
        unsigned _BitInt(1024)
    )
)
#endif

#elif defined(_MSC_VER)

#error "MSVC support is not implemented yet"

#else

#error "Unsupported compiler"

#endif

/* --- Special values --- */

typedef enum : __UINT32_TYPE__ {
#define V(category, name, type, member, index) \
  STDC_TYPE_ENUM_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/sinteger.def"
#undef V
} SType;

typedef struct {
  SType type;
  unsigned _BitInt(32) flags;
  union {
#define V(category, name, type, member, index) \
  STDC_TYPE_UNION_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/sinteger.def"
#undef V
  };
} STDC_MAY_ALIAS SVal;

#endif /* STDC_TYPE_COMPILETIME_SINTEGER_H */
