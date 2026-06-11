# Implementation Plan: Type System Discriminant, Naming, & Registry Refinement

This plan details the implementation of design decisions made regarding the type system's naming conventions, discriminant naming, category checking, and dynamic type registration.

---

## 1. Summary of Approved Changes

1. **Discriminant Renaming:**
   - Rename the `type` field in `Any`, `ValAny`, `RefAny`, and all sub-generic structs (`BoolVal`, `ByteVal`, `CharVal`, `FloatVal`, `UIntVal`, `IntVal`, `NoneVal`) to `kind`.
   - Update all references in the library (e.g., `unwrap(Op)` macro) and tests.

2. **Explicit Reference Bitmask:**
   - Define `STDC_TYPE_CATEGORY_IS_REF` in [category.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/category.h).
   - Update `Any_is_val` and `Any_is_ref` in [any.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/any.h) to use this bitmask.

3. **Standardized Enum Prefixes (`Type_`):**
   - Update enum naming to follow the `Type_Category_Name` pattern for category-prefixed types (e.g., `Type_Bool_B8`, `Type_Int_I32`, `Type_None_None`).
   - Update bare names to follow the `Type_Name` pattern (e.g., `Type_B8`, `Type_I32`, `Type_None`, `Type_Byte`).
   - Rename `TypeInvalid` to `Type_Invalid`.

4. **Dynamic Type Registry:**
   - Create a runtime type registration system allowing dynamic allocation of custom type IDs with the reference bit set.

---

## 2. Proposed Changes

### Component: `core` & `type`

#### [MODIFY] [category.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/category.h)
- Define the explicit reference bitmask:
  ```c
  static constexpr unsigned _BitInt(32) STDC_TYPE_CATEGORY_IS_REF = 0x8000U;
  ```

#### [MODIFY] [base.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/base.h)
- Update macros to prefix enum constants with `Type_`:
  ```c
  #define STDC_TYPE_ENUM_MEMBER(category, name, type, member, index)             \
    Type_##category##_##name = ((unsigned _BitInt(32))STDC_TYPE_CATEGORY_##category << 16U) | \
                           (unsigned _BitInt(32))(index),

  #define STDC_TYPE_ENUM_MEMBER_BARE(category, name, type, member, index) \
    Type_##name = ((unsigned _BitInt(32))STDC_TYPE_CATEGORY_##category << 16U) |    \
                 (unsigned _BitInt(32))(index),
  ```

#### [MODIFY] [type.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/type.h)
- Rename `TypeInvalid` to `Type_Invalid`.

#### [MODIFY] [any.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/any.h)
- Rename struct fields `type` to `kind`.
- Update `Any_is_val` and `Any_is_ref` to check for `Type_Invalid` and perform the bitwise mask check against `STDC_TYPE_CATEGORY_IS_REF`.

#### [MODIFY] [bool.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/bool.h)
- Rename struct member `type` in `BoolVal` to `kind`.

#### [MODIFY] [byte.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/byte.h)
- Rename struct member `type` in `ByteVal` to `kind`.

#### [MODIFY] [char.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/char.h)
- Rename struct member `type` in `CharVal` to `kind`.

#### [MODIFY] [float.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/float.h)
- Rename struct member `type` in `FloatVal` to `kind`.

#### [MODIFY] [integer.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/integer.h)
- Rename struct member `type` in `UIntVal` and `IntVal` to `kind`.

#### [MODIFY] [none.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/none.h)
- Rename `TypeNoneNone` to `Type_None_None`.
- Rename struct member `type` in `NoneVal` to `kind`.

#### [NEW] [registry.h](file:///home/robert/Personal/Projects/stdc/include/stdc/type/registry.h)
- Create a header for the compile-time and runtime dynamic type registration.
- Define a lightweight runtime function interface:
  ```c
  #ifndef STDC_TYPE_REGISTRY_H
  #define STDC_TYPE_REGISTRY_H
  
  #include "stdc/type/type.h"
  
  Type stdc_register_type(const char* name);
  const char* stdc_get_type_name(Type kind);
  
  #endif /* STDC_TYPE_REGISTRY_H */
  ```

#### [NEW] [registry.c](file:///home/robert/Personal/Projects/stdc/src/stdc/type/registry.c)
- Implement dynamic type registration storing a mapping of registered dynamic types (allocating dynamic IDs with `STDC_TYPE_CATEGORY_IS_REF` set).

---

### Component: `result`

#### [MODIFY] [result.h](file:///home/robert/Personal/Projects/stdc/include/stdc/result/result.h)
- Update `unwrap(Op)` macro to use `.kind` instead of `.type`.

---

### Component: `tests`

#### [MODIFY] [type_enum_test.c](file:///home/robert/Personal/Projects/stdc/tests/type_enum_test.c)
- Update all enum assertion usages to the new prefixed names (e.g., `Type_Bool_B8`, `Type_B8`, etc.) and the field names to `.kind`.

---

## 3. Verification Plan

### Automated Tests
- Run `cmake --build --preset debug` to compile all targets.
- Execute `./build/debug-strict/tests/type_enum_test` to verify alignment and size assertions.
