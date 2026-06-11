#ifndef STDC_TYPE_COMPILETIME_BASE_H
#define STDC_TYPE_COMPILETIME_BASE_H

#include "stdc/core/core.h"
#include "stdc/type/category.h"

/* For example in the case of u64 it would be (UInt, U64, U64, u64, 6) */
#define STDC_TYPE_ENUM_NAME(category, name, type, member, index) category##Type
#define STDC_TYPE_ENUM_MEMBER(category, name, type, member, index)   \
  Type##category##name =                                             \
      ((unsigned _BitInt(32))STDC_TYPE_CATEGORY_##category << 16U) | \
      (unsigned _BitInt(32))(index),

/* Visitor for the global Type enum — produces bare names (TypeB8, TypeI8) */
#define STDC_TYPE_ENUM_MEMBER_BARE(category, name, type, member, index)       \
  Type##name = ((unsigned _BitInt(32))STDC_TYPE_CATEGORY_##category << 16U) | \
               (unsigned _BitInt(32))(index),

#define STDC_TYPE_UNION_NAME(category, name, type, member, index)
#define STDC_TYPE_UNION_MEMBER(category, name, type, member, index) type member;

#define STDC_DEFINE_PRIMITIVE_TYPE(type, name, limit) \
  typedef type name;                                  \
  limit

#define STDC_DEF_UNSIGNED_LIMITS(type) \
  static const type type##_min = 0;    \
  static const type type##_max = (type)(~(type)0);

#define STDC_DEF_SIGNED_LIMITS(type, unsigned_type)          \
  static const type type##_min =                             \
      (type)(-((unsigned_type)1 << (sizeof(type) * 8 - 1))); \
  static const type type##_max =                             \
      (type)(((unsigned_type)1 << (sizeof(type) * 8 - 1)) - 1);

#endif /* STDC_TYPE_COMPILETIME_BASE_H */
