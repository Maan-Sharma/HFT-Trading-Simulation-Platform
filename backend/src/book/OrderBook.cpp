#include "../../include/book/OrderBook.hpp"

OrderBook::OrderBook()
    : bids_(true),
      asks_(false)
{
}

void OrderBook::addOrder(Order *order)
{
    if (order->side == Side::BUY)
        bids_.add(order);
    else
        asks_.add(order);
}

Price OrderBook::bestBid() const
{
    return bids_.bestPrice();
}

Price OrderBook::bestAsk() const
{
    return asks_.bestPrice();
}

BookSide &OrderBook::bids()
{
    return bids_;
}

BookSide &OrderBook::asks()
{
    return asks_;
}