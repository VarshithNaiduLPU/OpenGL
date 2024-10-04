#pragma once

#include "../Headers.h"

namespace Logger
{
    template<typename... Args>
    static void msg(const Args&... args) {
        std::ostringstream oss;
        ((oss << args), ...);
        std::cout << oss.str() << std::endl;
    }
}
