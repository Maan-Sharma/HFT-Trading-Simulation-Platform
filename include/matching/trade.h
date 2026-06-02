#pragma once

#include "../common/type.h"

struct trade
{
    OrderId BuyOrderId;

    OrderId SellOrderId;

    Price price;

    Quantity quantity;

    Timestamp timestamp;
};
