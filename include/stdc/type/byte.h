#ifndef STDC_TYPE_BYTE_H
#define STDC_TYPE_BYTE_H

#include "stdc/core/core.h"
#include "stdc/type/base.h"
/* --- Byte type --- */
#if defined(__GNUC__) || defined(__clang__)

/* Byte */
#if __INTMAX_WIDTH__ >= 8
#define STDC_DEFINED_BYTE
STDC_DEFINE_PRIMITIVE_TYPE(
    unsigned _BitInt(8),
    Byte,
    STDC_DEF_UNSIGNED_LIMITS(Byte)
)
#endif

#elif defined(_MSC_VER)

#error "MSVC support is not implemented yet"

#else

#error "Unsupported compiler"

#endif

typedef enum : __UINT32_TYPE__ {
#define V(category, name, type, member, index) \
  STDC_TYPE_ENUM_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/byte.def"
#undef V
} ByteType;

typedef struct {
  ByteType type;
  unsigned _BitInt(32) flags;
  union {
#define V(category, name, type, member, index) \
  STDC_TYPE_UNION_MEMBER(category, name, type, member, index)
#include "stdc/type/lists/byte.def"
#undef V
  };
} STDC_MAY_ALIAS ByteVal;

#endif /* STDC_TYPE_BYTE_H */
