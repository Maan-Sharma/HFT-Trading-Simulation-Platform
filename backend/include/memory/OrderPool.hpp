#pragma once

#include <array>

#include "../order/Order.hpp"

class OrderPool
{
public:
    static constexpr size_t MAX_ORDERS = 1'000'000;

    Order *allocate();

private:
    std::array<Order, MAX_ORDERS> pool_;

    size_t next_{0};
};