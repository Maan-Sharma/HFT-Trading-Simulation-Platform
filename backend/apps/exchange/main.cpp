#include <iostream>
#include <random>
#include <thread>
#include <chrono>

#include "../../include/network/WebSocketServer.hpp"
#include "../../include/network/MarketPublisher.hpp"
#include "../../include/matching/MatchingEngine.hpp"
#include "../../include/common/Timestamp.hpp"

int main()
{
    WebSocketServer wsServer(8080);
    wsServer.start();

    MarketPublisher publisher(wsServer);
    MatchingEngine engine;

    std::mt19937 rng(std::random_device{}());

    Price currentPrice = 250;

    OrderId nextOrderId = 1;

    std::uniform_int_distribution<int>
        moveDist(-1, 1);

    std::uniform_int_distribution<int>
        qtyDist(1, 50);

    std::uniform_int_distribution<int>
        sideDist(0, 1);

    while (true)
    {
        currentPrice += moveDist(rng);

        if (currentPrice < 200)
            currentPrice = 200;

        if (currentPrice > 300)
            currentPrice = 300;

        Order *order = new Order{
            nextOrderId++,
            currentPrice,
            qtyDist(rng),
            getTimestamp(),
            sideDist(rng) == 0
                ? Side::BUY
                : Side::SELL,
            OrderType::LIMIT};

        std::vector<Trade> trades =
            engine.process(order);

        std::cout
            << "ORDER "
            << order->orderId
            << " "
            << (order->side == Side::BUY ? "BUY " : "SELL ")
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

            publisher.PublishTrade(trade);
        }

        std::cout
            << "BID="
            << engine.book().bestBid()
            << " ASK="
            << engine.book().bestAsk()
            << "\n\n";

        std::this_thread::sleep_for(
            std::chrono::milliseconds(100));
    }

    return 0;
}