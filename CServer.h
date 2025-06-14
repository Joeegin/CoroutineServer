//
// Created by 乔益金 on 25-6-14.
//

#ifndef CSERVER_H
#define CSERVER_H

#include<memory.h>
#include<map>
#include<mutex>
#include<boost/asio.hpp>
#include"CSession.h"
using boost::asio::ip::tcp;
using namespace std;

class CSession;
class CServer {
public:
    CServer(boost::asio::io_context& io_context,short port);
    ~CServer();
    void ClearSession(std::string);
private:
    void HandleAccept(shared_ptr<CSession>,const boost::system::error_code& error);
    void StartAccept();
    boost::asio::io_context& _io_context;
    short _port;
    tcp::acceptor _acceptor;
    std::map<std::string,shared_ptr<CSession>> _sessions;
    std::mutex _mutex;
};



#endif //CSERVER_H
