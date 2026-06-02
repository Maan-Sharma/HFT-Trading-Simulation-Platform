#include <iostream>
#include <thread>
#include <chrono>
#include <random>

#include "../../include/feed/MarketDataFeed.hpp"
#include "../../include/matching/MatchingEngine.hpp"

int main()
{
    MatchingEngine engine;

    MarketDataFeed feed;

    while (true)
    {
        Order *order =
            feed.nextOrder();

        auto trades =
            engine.process(order);

        std::cout
            << (order->side == Side::BUY
                    ? "BUY "
                    : "SELL ")
            << order->quantity
            << " @ "
            << order->price
            << '\n';

        for (const auto &trade : trades)
        {
            std::cout
                << "TRADE "
                << trade.quantity
                << " @ "
                << trade.price
                << '\n';
        }

        std::cout
            << "BID="
            << engine.book().bestBid()
            << " ASK="
            << engine.book().bestAsk()
            << "\n\n";

        std::this_t::sleep_for(
            std::chrono::milliseconds(100));
    }
}