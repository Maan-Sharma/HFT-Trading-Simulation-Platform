#pragma once

#include "Types.hpp"
#include <chrono>
#include <iostream>

inline Timestamp getTimestamp()
{
    return static_cast<Timestamp>(
        std::chrono::high_resolution_clock::now()
            .time_since_epoch()
            .count());
}