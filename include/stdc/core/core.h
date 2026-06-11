#ifndef STDC_CORE_CORE_H
#define STDC_CORE_CORE_H

#if defined(__GNUC__) || defined(__clang__)
#define STDC_MAY_ALIAS __attribute__((may_alias))
#else
#define STDC_MAY_ALIAS
#endif

typedef void dummy;

#endif /* STDC_CORE_CORE_H */
