#include "../../include/network/MarketPublisher.hpp"

#include <boost/json.hpp>

namespace json = boost::json;

MarketPublisher::MarketPublisher(
    WebSocketServer &server)
    : server_(server)
{
}

void MarketPublisher::PublishTrade(
    const Trade &trade)
{
    json::object obj;

    obj["type"] = "trade";
    obj["buyOrderId"] = trade.buyOrderId;
    obj["sellOrderId"] = trade.sellOrderId;
    obj["price"] = trade.price;
    obj["quantity"] = trade.quantity;
    obj["timestamp"] = trade.timestamp;

    server_.broadcast(
        json::serialize(obj));
}
