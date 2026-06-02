#pragma once
#include "../common/type.h"

enum class Side
{
    BUY,
    SELL
};

enum class OrderType
{
    Limit,
    Market
};

struct orderbook
{
    OrderId _orderid;

    Side _side;

    Price price;

    Quantity quantity;

    Timestamp timestamp;

    OrderType type;
};
