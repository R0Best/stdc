#ifndef STDC_RESULT_RESULT_H
#define STDC_RESULT_RESULT_H

#define Result(Type) Result##Type

#define unwrap(Op)                                                 \
  __extension__({                                                  \
    auto __result = Op;                                            \
    if (__result.type != ResultSuccess) {                          \
      return (typeof(Op)){.type = __result.type, .value = {0}};    \
    }                                                              \
    __result.value;                                                \
  })

#endif /* STDC_RESULT_RESULT_H */
