//
// Created by W9080764 on 25-4-18.
//

#ifndef REDIS_H
#define REDIS_H

#include <boost/redis/connection.hpp>
#include <boost/asio/detached.hpp>
#include <boost/redis/src.hpp>
#include <string>

class Redis {
public:
    static Redis* instance();
    void Initialize(const std::string& strIp,unsigned short usPort=6379);
    void set(const std::string& strKey,const std::string& strValue);
private:
    Redis();
    ~Redis();
    static Redis* m_ptrInstance;
    boost::asio::io_context m_ioContext;
    boost::redis::connection m_objConnection;
    boost::redis::config m_linkConfig;

};



#endif //REDIS_H
