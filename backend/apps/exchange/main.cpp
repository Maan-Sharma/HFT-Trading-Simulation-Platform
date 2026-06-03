#include <iostream>
#include <thread>
#include <chrono>

#include "../../include/feed/MarketDataFeed.hpp"
#include "../../include/matching/MatchingEngine.hpp"
#include "../../include/network/WebSocketServer.hpp"

int main()
{
    WebSocketServer ws(9002);

    ws.start();
    MatchingEngine engine;
    MarketDataFeed feed;

    uint64_t orderCount = 0;
    uint64_t tradeCount = 0;

    while (true)
    {
        Order *order = feed.nextOrder();

        auto trades = engine.process(order);

        ++orderCount;
        tradeCount += trades.size();

        std::cout
            << "--------------------------------------------------\n"
            << "ORDER #" << order->orderId
            << " | "
            << (order->side == Side::BUY ? "BUY " : "SELL ")
            << order->quantity
            << " @ "
            << order->price
            << '\n';

        for (const auto &trade : trades)
        {
            std::cout
                << "TRADE  "
                << trade.quantity
                << " @ "
                << trade.price
                << '\n';
        }

        Price bid = engine.book().bestBid();
        Price ask = engine.book().bestAsk();

        std::cout
            << "BOOK   | "
            << "BID: " << bid
            << " | ASK: " << ask;

        if (bid > 0 && ask > 0)
        {
            std::cout
                << " | SPREAD: "
                << (ask - bid);
        }

        std::cout << '\n';

        std::cout
            << "STATS  | Orders: "
            << orderCount
            << " | Trades: "
            << tradeCount
            << '\n';

        std::this_thread::sleep_for(
            std::chrono::milliseconds(50));
    }

    return 0;
}