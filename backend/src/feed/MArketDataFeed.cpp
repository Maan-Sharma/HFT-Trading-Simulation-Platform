#include "../../include/feed/MarketDataFeed.hpp"
#include "../../include/common/TimeStamp.hpp"
#include <random>

MarketDataFeed::MarketDataFeed()
    : nextOrderId_(1),
      midPrice_(250)
{
}

Order *MarketDataFeed::nextOrder()
{
    static std::mt19937 rng(
        std::random_device{}());

    std::uniform_int_distribution<int>
        moveDist(-1, 1);

    std::uniform_int_distribution<int>
        qtyDist(1, 100);

    std::uniform_int_distribution<int>
        sideDist(0, 1);

    midPrice_ += moveDist(rng);

    Price bidPrice =
        midPrice_ - 1;

    Price askPrice =
        midPrice_ + 1;

    auto *order =
        new Order;

    order->orderId =
        nextOrderId_++;

    order->quantity =
        qtyDist(rng);

    order->timestamp =
        Timestamp();

    order->type =
        OrderType::LIMIT;

    if (sideDist(rng) == 0)
    {
        order->side =
            Side::BUY;

        order->price =
            bidPrice;
    }
    else
    {
        order->side =
            Side::SELL;

        order->price =
            askPrice;
    }

    return order;
}