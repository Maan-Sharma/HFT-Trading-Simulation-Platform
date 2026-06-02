#pragma once

#include "../common/Types.hpp"

struct Trade
{
    OrderId buyOrderId;

    OrderId sellOrderId;

    Price price;

    Quantity quantity;

    Timestamp timestamp;
};