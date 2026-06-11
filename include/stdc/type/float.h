#ifndef STDC_TYPE_FLOAT_H
#define STDC_TYPE_FLOAT_H

#include "stdc/core/core.h"
#include "stdc/type/base.h"

/* --- Floating-point types --- */
#if defined(__GNUC__) || defined(__clang__)

typedef _Float16 F16;
typedef float F32;
typedef double F64;

#elif defined(_MSC_VER)

#error "MSVC support is not implemented yet"

#else

#error "Unsupported compiler"

#endif

/* --- Special values --- */

/* --- Limits --- */
static constexpr F16 F16_max = 0x1.ffcp15f16;
static constexpr F16 F16_min = -F16_max;
static constexpr F16 F16_epsilon = 0x1.0p-10f16;

static constexpr F32 F32_max = 0x1.fffffep127f;
static constexpr F32 F32_min = -F32_max;
static constexpr F32 F32_epsilon = 0x1.0p-23f;

static constexpr F64 F64_max = 0x1.fffffffffffffp1023;
static constexpr F64 F64_min = -F64_max;
static constexpr F64 F64_epsilon = 0x1.0p-52;

typedef enum : __UINT32_TYPE__ {
#define V(category, name, type, member, index) \
  STDC_TYPE_ENUM_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/float.def"
#undef V
} FloatType;

typedef struct {
  FloatType type;
  unsigned _BitInt(32) flags;
  union {
#define V(category, name, type, member, index) \
  STDC_TYPE_UNION_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/float.def"
#undef V
  };
} STDC_MAY_ALIAS FloatVal;

#endif /* STDC_TYPE_FLOAT_H */
