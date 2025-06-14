//
// Created by 乔益金 on 25-6-14.
//

#ifndef CSESSION_H
#define CSESSION_H

#include <boost/asio.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include "CServer.h"
using boost::asio::ip::tcp;

class CServer;
class CSession :public std::enable_shared_from_this<CSession>{
public:
    CSession(boost::asio::io_context& io_context,CServer *server);
    tcp::socket &GetSocket();
    std::string GetUuid();
    void Start();
private:
    boost::asio::io_context& _io_context;
    CServer *_server;
    tcp::socket _socket;
    std::string _uuid;
};



#endif //CSESSION_H
