
#pragma once

#define MLS_CO_BEGIN(return_type, ...)                                \
    [mls_co_context = 0, __VA_ARGS__]() mutable -> return_type {      \
        constexpr static auto kCoAnchor = (__COUNTER__, __COUNTER__); \
        static_assert(kCoAnchor % 2, "kCoAnchor must be odd!");       \
        switch (mls_co_context) {                                     \
        case 0:

#define MLS_CO_END }}

#define MLS_CO_YIELD(result)            \
    mls_co_context = (__COUNTER__ / 2); \
    return result;                      \
    case (__COUNTER__ - 1) / 2:
