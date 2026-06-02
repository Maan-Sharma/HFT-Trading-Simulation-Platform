#pragma once

#include "BookSide.hpp"

class OrderBook
{
public:
    OrderBook();

    void addOrder(Order *order);

    Price bestBid() const;

    Price bestAsk() const;

    BookSide &bids();
    BookSide &asks();

private:
    BookSide bids_;

    BookSide asks_;
};