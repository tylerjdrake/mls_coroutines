
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
