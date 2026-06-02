#pragma once

#include <map>
#include "PriceLevel.hpp"

class BookSide
{
public:
    explicit BookSide(bool isBid);

    void add(Order *order);

    Price bestPrice() const;

    PriceLevel *bestLevel();

    void removeBestOrder();

private:
    bool isBid_;

    std::map<Price, PriceLevel> levels_;
};