#pragma once

#include "../order/Trade.hpp"
#include "../../include/network/WebSocketServer.hpp"

class MarketPublisher
{
public:
    explicit MarketPublisher(WebSocketServer &server);

    void PublishTrade(const Trade &trade);

private:
    WebSocketServer &server_;
};