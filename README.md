# About

Standard C++ looks like it is going to be getting coroutines eventually. But eventually is not **RIGHT NOW**.

With enough preprocessor abuse: **M**acros, **L**ambdas, and **S**witch-statements can be used to get something that looks a bit like coroutines.

Copy the header file, `"mls_coroutines.hpp"`, into your project and start writing coroutines!

## mls_coroutines.hpp
```C++
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
```

## Sample Code
```C++
#include <iostream>
#include "mls_coroutines.hpp"

auto count_up_from(int start)
{
    return MLS_CO_BEGIN(int, start)
    {
        while (true) {
            MLS_CO_YIELD(start);
            start += 1;
        }
    } MLS_CO_END;
}

int main(int argc, char** argv)
{
    auto next = count_up_from(42);
    for (int i = 0; i < 10; i++) {
        std::cout << next() << std::endl;
    }
    return 0;
}
```
## Sample Code Output
```
42
43
44
45
46
47
48
49
50
51
```

# Inspiration

Much of the macro machinery comes from here: [Simon Tatham's Coroutines in C](https://www.chiark.greenend.org.uk/~sgtatham/coroutines.html)


# Building This Repo

    mkdir build && cd build && cmake .. -G "Visual Studio 16 2019" -A x64 && cmake --build .
