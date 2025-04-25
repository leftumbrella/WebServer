#ifndef WEBSERVER_REQUEST_HANDLER_H
#define WEBSERVER_REQUEST_HANDLER_H

#include <boost/asio.hpp>
#include <boost/beast.hpp>

class RequestHandler{
public:
    RequestHandler();
    ~RequestHandler();
    void run(short sPort);
private:
    void ProcessRequest(boost::asio::ip::tcp::socket& socket);
    boost::asio::io_context m_ioContext;
};



#endif //WEBSERVER_REQUEST_HANDLER_H
