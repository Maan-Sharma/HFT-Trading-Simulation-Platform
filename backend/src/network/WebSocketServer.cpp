#include "../../include/network/WebSocketServer.hpp"

#include <iostream>
#include <thread>

WebSocketServer::WebSocketServer(
    unsigned short port)
    : acceptor_(
          ioc_,
          tcp::endpoint(
              tcp::v4(),
              port))
{
}

void WebSocketServer::start()
{
    acceptConnection();

    std::thread(
        [this]()
        {
            ioc_.run();
        })
        .detach();

    std::cout
        << "WebSocket Server Started\n";
}

void WebSocketServer::acceptConnection()
{
    auto socket =
        std::make_shared<tcp::socket>(
            ioc_);

    acceptor_.async_accept(
        *socket,
        [this, socket](
            boost::system::error_code ec)
        {
            if (!ec)
            {
                auto ws =
                    std::make_shared<
                        websocket::stream<
                            tcp::socket>>(
                        std::move(*socket));

                ws->accept();

                clients_.insert(ws);

                std::cout
                    << "Client Connected\n";
            }

            acceptConnection();
        });
}

void WebSocketServer::broadcast(
    const std::string &message)
{
    for (auto &client : clients_)
    {
        boost::system::error_code ec;

        client->write(
            asio::buffer(message),
            ec);

        if (ec)
        {
            std::cout
                << "Send Error: "
                << ec.message()
                << '\n';
        }
    }
}