#include "../../include/book/BookSide.hpp"

BookSide::BookSide(bool isBid)
    : isBid_(isBid)
{
}

void BookSide::add(Order *order)
{
    auto &level = levels_[order->price];

    level.price = order->price;

    if (level.tail == nullptr)
    {
        level.head = order;
        level.tail = order;
    }
    else
    {
        level.tail->next = order;
        order->prev = level.tail;
        level.tail = order;
    }

    level.totalQuantity += order->quantity;
}

Price BookSide::bestPrice() const
{
    if (levels_.empty())
        return 0;

    if (isBid_)
        return levels_.rbegin()->first;

    return levels_.begin()->first;
}