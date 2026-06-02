#pragma once

#include "type.h"
#include <chrono>
#include <iostream>

inline Timestamp getTimestamp()
{
    return static_cast<Timestamp>(
        std::chrono::high_resolution_clock::now()
            .time_since_epoch()
            .count());
}