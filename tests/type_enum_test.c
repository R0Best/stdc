#include "stdc/type/any.h"

/* --- Sentinel value --- */
_Static_assert(
    TypeInvalid == 0,
    "TypeInvalid must be 0x00000000"
);

/* --- Category extraction --- */
_Static_assert(
    (TypeNoneNone >> 16U) == STDC_TYPE_CATEGORY_None,
    "TypeNoneNone category bits must equal STDC_TYPE_CATEGORY_None"
);
_Static_assert(
    (TypeBoolB8 >> 16U) == STDC_TYPE_CATEGORY_Bool,
    "TypeBoolB8 category bits must equal STDC_TYPE_CATEGORY_Bool"
);
_Static_assert(
    (TypeByteByte >> 16U) == STDC_TYPE_CATEGORY_Byte,
    "TypeByteByte category bits must equal STDC_TYPE_CATEGORY_Byte"
);
_Static_assert(
    (TypeCharC8 >> 16U) == STDC_TYPE_CATEGORY_Char,
    "TypeCharC8 category bits must equal STDC_TYPE_CATEGORY_Char"
);
_Static_assert(
    ((U32)TypeUIntU8 >> 16U) == STDC_TYPE_CATEGORY_UInt,
    "TypeUIntU8 category bits must equal STDC_TYPE_CATEGORY_UInt"
);
_Static_assert(
    ((U32)TypeIntI8 >> 16U) == STDC_TYPE_CATEGORY_Int,
    "TypeIntI8 category bits must equal STDC_TYPE_CATEGORY_Int"
);
_Static_assert(
    ((U32)TypeFloatF32 >> 16U) == STDC_TYPE_CATEGORY_Float,
    "TypeFloatF32 category bits must equal STDC_TYPE_CATEGORY_Float"
);

/* --- Exact enum values --- */
_Static_assert(
    (U32)TypeNoneNone == ((0x0001U << 16U) | 1U),
    "TypeNoneNone must be (None_cat << 16) | 1"
);
_Static_assert(
    (U32)TypeBoolB8 == ((0x0003U << 16U) | 1U),
    "TypeBoolB8 must be (Bool_cat << 16) | 1"
);
_Static_assert(
    (U32)TypeBoolB64 == ((0x0003U << 16U) | 4U),
    "TypeBoolB64 must be (Bool_cat << 16) | 4"
);
_Static_assert(
    (U32)TypeIntI8 == ((0x0006U << 16U) | 3U),
    "TypeIntI8 must be (Int_cat << 16) | 3"
);
_Static_assert(
    (U32)TypeIntI64 == ((0x0006U << 16U) | 6U),
    "TypeIntI64 must be (Int_cat << 16) | 6"
);
_Static_assert(
    (U32)TypeUIntU64 == ((0x0005U << 16U) | 6U),
    "TypeUIntU64 must be (UInt_cat << 16) | 6"
);
_Static_assert(
    (U32)TypeFloatF16 == ((0x0007U << 16U) | 1U),
    "TypeFloatF16 must be (Float_cat << 16) | 1"
);
_Static_assert(
    (U32)TypeFloatF64 == ((0x0007U << 16U) | 3U),
    "TypeFloatF64 must be (Float_cat << 16) | 3"
);

/* --- Global Type enum bare names match per-category prefixed names --- */
_Static_assert(
    (U32)TypeB8 == (U32)TypeBoolB8,
    "TypeB8 must equal TypeBoolB8"
);
_Static_assert(
    (U32)TypeB16 == (U32)TypeBoolB16,
    "TypeB16 must equal TypeBoolB16"
);
_Static_assert(
    (U32)TypeB32 == (U32)TypeBoolB32,
    "TypeB32 must equal TypeBoolB32"
);
_Static_assert(
    (U32)TypeB64 == (U32)TypeBoolB64,
    "TypeB64 must equal TypeBoolB64"
);
_Static_assert(
    (U32)TypeC8 == (U32)TypeCharC8,
    "TypeC8 must equal TypeCharC8"
);
_Static_assert(
    (U32)TypeC16 == (U32)TypeCharC16,
    "TypeC16 must equal TypeCharC16"
);
_Static_assert(
    (U32)TypeC32 == (U32)TypeCharC32,
    "TypeC32 must equal TypeCharC32"
);
_Static_assert(
    (U32)TypeUSize == (U32)TypeUIntUSize,
    "TypeUSize must equal TypeUIntUSize"
);
_Static_assert(
    (U32)TypeUMax == (U32)TypeUIntUMax,
    "TypeUMax must equal TypeUIntUMax"
);
_Static_assert(
    (U32)TypeU8 == (U32)TypeUIntU8,
    "TypeU8 must equal TypeUIntU8"
);
_Static_assert(
    (U32)TypeU16 == (U32)TypeUIntU16,
    "TypeU16 must equal TypeUIntU16"
);
_Static_assert(
    (U32)TypeU32 == (U32)TypeUIntU32,
    "TypeU32 must equal TypeUIntU32"
);
_Static_assert(
    (U32)TypeU64 == (U32)TypeUIntU64,
    "TypeU64 must equal TypeUIntU64"
);
_Static_assert(
    (U32)TypeISize == (U32)TypeIntISize,
    "TypeISize must equal TypeIntISize"
);
_Static_assert(
    (U32)TypeIMax == (U32)TypeIntIMax,
    "TypeIMax must equal TypeIntIMax"
);
_Static_assert(
    (U32)TypeI8 == (U32)TypeIntI8,
    "TypeI8 must equal TypeIntI8"
);
_Static_assert(
    (U32)TypeI16 == (U32)TypeIntI16,
    "TypeI16 must equal TypeIntI16"
);
_Static_assert(
    (U32)TypeI32 == (U32)TypeIntI32,
    "TypeI32 must equal TypeIntI32"
);
_Static_assert(
    (U32)TypeI64 == (U32)TypeIntI64,
    "TypeI64 must equal TypeIntI64"
);
_Static_assert(
    (U32)TypeF16 == (U32)TypeFloatF16,
    "TypeF16 must equal TypeFloatF16"
);
_Static_assert(
    (U32)TypeF32 == (U32)TypeFloatF32,
    "TypeF32 must equal TypeFloatF32"
);
_Static_assert(
    (U32)TypeF64 == (U32)TypeFloatF64,
    "TypeF64 must equal TypeFloatF64"
);

/* --- Byte and None: bare names now available in global Type enum --- */
_Static_assert(
    (U32)TypeByte == (U32)TypeByteByte,
    "TypeByte must equal TypeByteByte"
);
_Static_assert(
    (U32)TypeNone == (U32)TypeNoneNone,
    "TypeNone must equal TypeNoneNone"
);

/* --- Uniqueness: different types must have different values --- */
_Static_assert((U32)TypeBoolB8 != (U32)TypeUIntU8,
               "Bool B8 and UInt U8 must have different values");
_Static_assert((U32)TypeIntI8 != (U32)TypeUIntU8,
               "Int I8 and UInt U8 must have different values");
_Static_assert((U32)TypeCharC8 != (U32)TypeBoolB8,
               "Char C8 and Bool B8 must have different values");
_Static_assert((U32)TypeNone != (U32)TypeInvalid,
               "TypeNone must differ from TypeInvalid");

/* --- Any Memory Bounds and Compatibility --- */
_Static_assert(sizeof(ValAny) <= 16, "ValAny must not exceed 16 bytes");
_Static_assert(sizeof(RefAny) <= 16, "RefAny must not exceed 16 bytes");
_Static_assert(sizeof(Any) <= 16, "Any must not exceed 16 bytes");
_Static_assert(sizeof(ValAny) == sizeof(Any), "ValAny must match Any size");
_Static_assert(sizeof(RefAny) == sizeof(Any), "RefAny must match Any size");

/* All assertions are compile-time. If this file compiles, the tests pass. */
int main(void) {
  return 0;
}
