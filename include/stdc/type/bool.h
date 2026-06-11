#ifndef STDC_TYPE_BOOL_H
#define STDC_TYPE_BOOL_H

#include "stdc/core/core.h"
#include "stdc/type/base.h"

/* --- Boolean type --- */
#if defined(__GNUC__) || defined(__clang__)

#define STDC_DEF_BOOL_LIMITS(type)      \
  static constexpr type type##_min = 0; \
  static constexpr type type##_max = 1;

/* B8 */
#if __INTMAX_WIDTH__ >= 8
#define STDC_DEFINED_B8
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(8),
    B8,
    STDC_DEF_BOOL_LIMITS(B8)
)
#endif

/* B16 */
#if __INTMAX_WIDTH__ >= 16
#define STDC_DEFINED_B16
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(16),
    B16,
    STDC_DEF_BOOL_LIMITS(B16)
)
#endif

/* B32 */
#if __INTMAX_WIDTH__ >= 32
#define STDC_DEFINED_B32
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(32),
    B32,
    STDC_DEF_BOOL_LIMITS(B32)
)
#endif

/* B64 */
#if __INTMAX_WIDTH__ >= 64
#define STDC_DEFINED_B64
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(64),
    B64,
    STDC_DEF_BOOL_LIMITS(B64)
)
#endif

/* B128 */
#if __INTMAX_WIDTH__ >= 128
#define STDC_DEFINED_B128
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(128),
    B128,
    STDC_DEF_BOOL_LIMITS(B128)
)
#endif

/* B256 */
#if __INTMAX_WIDTH__ >= 256
#define STDC_DEFINED_B256
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(256),
    B256,
    STDC_DEF_BOOL_LIMITS(B256)
)
#endif

/* B512 */
#if __INTMAX_WIDTH__ >= 512
#define STDC_DEFINED_B512
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(512),
    B512,
    STDC_DEF_BOOL_LIMITS(B512)
)
#endif

/* B1024 */
#if __INTMAX_WIDTH__ >= 1024
#define STDC_DEFINED_B1024
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(1024),
    B1024,
    STDC_DEF_BOOL_LIMITS(B1024)
)
#endif

/* Bool */
#if __INTMAX_WIDTH__ >= 8
#define STDC_DEFINED_BOOL
STDC_DEFINE_PRIMITIVE_TYPE(
    B8,
    Bool,
    STDC_DEF_BOOL_LIMITS(Bool)
)
#endif

#elif defined(_MSC_VER)

#error "MSVC support is not implemented yet"

#else

#error "Unsupported compiler"

#endif

/* --- Special values --- */
static constexpr Bool False = 0;
static constexpr Bool True = 1;

typedef enum : __UINT32_TYPE__ {
#define V(category, name, type, member, index) \
  STDC_TYPE_ENUM_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/bool.def"
#undef V
} BoolType;

typedef struct {
  BoolType type;
  unsigned _BitInt(32) flags;
  union {
#define V(category, name, type, member, index) \
  STDC_TYPE_UNION_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/bool.def"
#undef V
  };
} STDC_MAY_ALIAS BoolVal;

#endif /* STDC_TYPE_BOOL_H */
