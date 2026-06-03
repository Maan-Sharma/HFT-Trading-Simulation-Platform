#pragma once

#include "BookSide.hpp"
#include "../market/BookSnapshot.hpp"

class OrderBook
{
public:
    BookSnapshot snapshot() const;
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
