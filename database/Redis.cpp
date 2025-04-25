//
// Created by W9080764 on 25-4-18.
//

#include "Redis.h"
#include <iostream>
Redis* Redis::m_ptrInstance = nullptr;
Redis::Redis():m_objConnection(m_ioContext){
}

Redis::~Redis(){
}

Redis* Redis::instance(){
    if(m_ptrInstance == nullptr){
        m_ptrInstance = new Redis();
    }
    return m_ptrInstance;
}

void Redis::Initialize(const std::string& strIp, unsigned short usPort){
    m_linkConfig.addr.host = strIp;
    m_linkConfig.addr.port = std::to_string(usPort);
    m_objConnection.async_run(m_linkConfig, {}, boost::asio::detached);
}

void Redis::set(const std::string& strKey, const std::string& strValue){
    if (m_linkConfig.addr.host.empty() || m_linkConfig.addr.port.empty()){
        return;
    }
    boost::redis::request set_req;
    set_req.push("SET", strKey, strValue);
    boost::redis::response<std::string> set_resp;
    m_objConnection.async_exec(set_req, set_resp, [&](const auto& errCode, auto) {
        if (!errCode)
        {
            // TODO
        }
        m_objConnection.cancel();
    });
}
