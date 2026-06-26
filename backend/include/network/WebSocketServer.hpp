#pragma once

#include <boost/beast/websocket.hpp>
#include <boost/asio.hpp>

#include <memory>
#include <set>
#include <mutex>
#include <string>

namespace beast = boost::beast;
namespace websocket = beast::websocket;
namespace asio = boost::asio;
using tcp = asio::ip::tcp;

class WebSocketServer
{
public:
    explicit WebSocketServer(
        unsigned short port);

    void start();

    void broadcast(
        const std::string &message);

private:
    asio::io_context ioc_;
    tcp::acceptor acceptor_;

    std::mutex clientsMutex_;

    std::set<
        std::shared_ptr<
            websocket::stream<tcp::socket>>>
        clients_;

    void acceptConnection();
};