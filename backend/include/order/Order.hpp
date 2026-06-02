#pragma once

#include "../common/Types.hpp"
#include "Side.hpp"
#include "OrderType.hpp"

struct Order
{
    OrderId orderId;

    Price price;

    Quantity quantity;

    Timestamp timestamp;

    Side side;

    OrderType type;

    Order *next{nullptr};

    Order *prev{nullptr};
};