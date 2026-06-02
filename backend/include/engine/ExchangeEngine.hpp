#pragma once

#include "../matching/MatchingEngine.hpp"
#include <iostream>
class ExchangeEngine
{
public:
    void submit(Order *order);

private:
    MatchingEngine matcher_;
};
void ExchangeEngine::submit(Order *order)
{
    auto trades = matcher_.process(order);

    for (const auto &trade : trades)
    {
        std::cout
            << "TRADE "
            << trade.quantity
            << " @ "
            << trade.price
            << '\n';
    }
}