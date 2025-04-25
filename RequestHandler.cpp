//
// Created by W9080764 on 25-4-17.
//

#include "RequestHandler.h"

#include <iostream>
#include <boost/lexical_cast.hpp>

RequestHandler::RequestHandler(){
}


RequestHandler::~RequestHandler(){
}

void RequestHandler::run(short sPort){
    boost::asio::ip::tcp::acceptor objAcceptor{m_ioContext
        , {boost::asio::ip::tcp::v4(), boost::lexical_cast< boost::asio::ip::port_type>(sPort)}};
    objAcceptor.async_accept([&objAcceptor, this](
        const boost::beast::error_code& errCode, boost::asio::ip::tcp::socket socket) {
        if (!errCode){
            ProcessRequest(socket);
        }
        objAcceptor.async_accept();
    });

    m_ioContext.run();
}

void RequestHandler::ProcessRequest(boost::asio::ip::tcp::socket& socket){
    boost::beast::flat_buffer buffer;
    boost::beast::http::request<boost::beast::http::string_body> req;

    // 异步读取请求
    boost::beast::http::async_read(socket, buffer, req
        , [&socket, req](const boost::beast::error_code& errCode, std::size_t) {
        if (!errCode) {
            // 构建响应
            boost::beast::http::response<boost::beast::http::string_body> res{boost::beast::http::status::ok, req.version()};
            res.set(boost::beast::http::field::server, "Boost.Beast");
            res.set(boost::beast::http::field::content_type, "text/plain");
            res.body() = "Hello, World!";
            res.prepare_payload();

            // 异步写入响应
            boost::beast::http::async_write(socket, res, [&socket](boost::beast::error_code ec, std::size_t) {
                socket.shutdown(boost::asio::ip::tcp::socket::shutdown_send, ec);
            });
        }
    });
}
