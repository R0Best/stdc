#ifndef STD_TYPE_COMPILETIME_UINTEGER_H
#define STD_TYPE_COMPILETIME_UINTEGER_H

#include "stdc/core/core.h"
#include "stdc/type/base.h"

/* --- Unsigned integer types --- */
#if defined(__GNUC__) || defined(__clang__)

/* USize */
#if __INTMAX_WIDTH__ >= __SIZE_WIDTH__
#define STDC_DEFINED_USIZE
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(__SIZE_WIDTH__),
    USize,
    STDC_DEF_UNSIGNED_LIMITS(USize)
)
#endif

/* UPtr */
#if __INTMAX_WIDTH__ >= __INTPTR_WIDTH__
#define STDC_DEFINED_UPTR
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(__INTPTR_WIDTH__),
    UPtr,
    STDC_DEF_UNSIGNED_LIMITS(UPtr)
)
#endif

/* UMax */
#if __INTMAX_WIDTH__ >= __INTMAX_WIDTH__
#define STDC_DEFINED_UMAX
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(__INTMAX_WIDTH__),
    UMax,
    STDC_DEF_UNSIGNED_LIMITS(UMax)
)
#endif

/* U8 */
#if __INTMAX_WIDTH__ >= 8
#define STDC_DEFINED_U8
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(8),
    U8,
    STDC_DEF_UNSIGNED_LIMITS(U8)
)
#endif

/* U16 */
#if __INTMAX_WIDTH__ >= 16
#define STDC_DEFINED_U16
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(16),
    U16,
    STDC_DEF_UNSIGNED_LIMITS(U16)
)
#endif

/* U32 */
#if __INTMAX_WIDTH__ >= 32
#define STDC_DEFINED_U32
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(32),
    U32,
    STDC_DEF_UNSIGNED_LIMITS(U32)
)
#endif

/* U64 */
#if __INTMAX_WIDTH__ >= 64
#define STDC_DEFINED_U64
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(64),
    U64,
    STDC_DEF_UNSIGNED_LIMITS(U64)
)
#endif

/* U128 */
#if __INTMAX_WIDTH__ >= 128
#define STDC_DEFINED_U128
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(128),
    U128,
    STDC_DEF_UNSIGNED_LIMITS(U128)
)
#endif

/* U256 */
#if __INTMAX_WIDTH__ >= 256
#define STDC_DEFINED_U256
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(256),
    U256,
    STDC_DEF_UNSIGNED_LIMITS(U256)
)
#endif

/* U512 */
#if __INTMAX_WIDTH__ >= 512
#define STDC_DEFINED_U512
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(512),
    U512,
    STDC_DEF_UNSIGNED_LIMITS(U512)
)
#endif

/* U1024 */
#if __INTMAX_WIDTH__ >= 1024
#define STDC_DEFINED_U1024
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(1024),
    U1024,
    STDC_DEF_UNSIGNED_LIMITS(U1024)
)
#endif

#elif defined(_MSC_VER)

#error "MSVC support is not implemented yet"

#else

#error "Unsupported compiler"

#endif

/* --- Special types --- */

/* --- Special values --- */

/* --- Special macros --- */
#define U(bits) unsigned _BitInt(bits)

typedef enum : __UINT32_TYPE__ {
#define V(category, name, type, member, index) \
  STDC_TYPE_ENUM_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/uinteger.def"
#undef V
} UIntType;

typedef struct {
  UIntType type;
  unsigned _BitInt(32) flags;
  union {
#define V(category, name, type, member, index) \
  STDC_TYPE_UNION_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/uinteger.def"
#undef V
  };
} STDC_MAY_ALIAS UVal;

#endif /* STD_TYPE_COMPILETIME_UINTEGER_H */
