#pragma once

#include "../order/Order.hpp"

struct PriceLevel
{
    Price price;

    Quantity totalQuantity{0};

    Order *head{nullptr};

    Order *tail{nullptr};
};