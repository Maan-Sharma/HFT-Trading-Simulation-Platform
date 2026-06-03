#include "../../include/matching/MatchingEngine.hpp"

OrderBook &MatchingEngine::book()
{
    return book_;
}

std::vector<Trade>
MatchingEngine::process(Order *incoming)
{
    std::vector<Trade> trades;

    // BUY ORDER
    if (incoming->side == Side::BUY)
    {
        while (incoming->quantity > 0)
        {
            auto *level =
                book_.asks().bestLevel();

            if (!level)
                break;

            if (incoming->price < level->price)
                break;

            auto *resting =
                level->head;

            if (!resting)
                break;

            Quantity traded =
                std::min(
                    incoming->quantity,
                    resting->quantity);

            trades.push_back(
                {incoming->orderId,
                 resting->orderId,
                 level->price,
                 traded,
                 incoming->timestamp});

            incoming->quantity -= traded;
            resting->quantity -= traded;
            level->totalQuantity -= traded;

            if (resting->quantity == 0)
            {
                level->head =
                    resting->next;

                if (level->head)
                    level->head->prev = nullptr;
            }
        }

        if (incoming->quantity > 0)
        {
            book_.addOrder(incoming);
        }
    }

    // SELL ORDER
    else
    {
        while (incoming->quantity > 0)
        {
            auto *level =
                book_.bids().bestLevel();

            if (!level)
                break;

            if (incoming->price > level->price)
                break;

            auto *resting =
                level->head;

            if (!resting)
                break;

            Quantity traded =
                std::min(
                    incoming->quantity,
                    resting->quantity);

            trades.push_back(
                {resting->orderId,
                 incoming->orderId,
                 level->price,
                 traded,
                 incoming->timestamp});

            incoming->quantity -= traded;
            resting->quantity -= traded;
            level->totalQuantity -= traded;

            if (resting->quantity == 0)
            {
                level->head =
                    resting->next;

                if (level->head)
                    level->head->prev = nullptr;
            }
        }

        if (incoming->quantity > 0)
        {
            book_.addOrder(incoming);
        }
    }

    return trades;
}