#ifndef STDC_TYPE_CATEGORY_H
#define STDC_TYPE_CATEGORY_H

/* Category IDs for the upper 16 bits of Type enum values.
 * 0x0000 is reserved as invalid/sentinel.
 *
 * The Most Significant Bit (MSB, 0x8000) of the category ID is reserved to
 * specify whether the category represents a stack-allocated primitive (0) or
 * a heap-allocated object (1).
 */
static constexpr unsigned _BitInt(32) STDC_TYPE_CATEGORY_None = 0x0001;
static constexpr unsigned _BitInt(32) STDC_TYPE_CATEGORY_Byte = 0x0002;
static constexpr unsigned _BitInt(32) STDC_TYPE_CATEGORY_Bool = 0x0003;
static constexpr unsigned _BitInt(32) STDC_TYPE_CATEGORY_Char = 0x0004;
static constexpr unsigned _BitInt(32) STDC_TYPE_CATEGORY_UInt = 0x0005;
static constexpr unsigned _BitInt(32) STDC_TYPE_CATEGORY_SInt = 0x0006;
static constexpr unsigned _BitInt(32) STDC_TYPE_CATEGORY_Float = 0x0007;

#endif /* STDC_TYPE_CATEGORY_H */
