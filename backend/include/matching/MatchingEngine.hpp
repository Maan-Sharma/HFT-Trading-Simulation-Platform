#pragma once

#include <vector>

#include "../book/OrderBook.hpp"
#include "../order/Trade.hpp"

class MatchingEngine
{
public:
    std::vector<Trade> process(Order *order);

    OrderBook &book();

private:
    OrderBook book_;
};