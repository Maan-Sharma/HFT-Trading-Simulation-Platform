#pragma once

#include "../order/Order.hpp"

class MarketDataFeed
{
public:
    MarketDataFeed();

    Order *nextOrder();

private:
    OrderId nextOrderId_;

    Price midPrice_;
};