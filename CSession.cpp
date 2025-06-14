//
// Created by 乔益金 on 25-6-14.
//

#include "CSession.h"

CSession::CSession(boost::asio::io_context& io_context, CServer *server):
    _io_context(io_context),_server(server),_socket(io_context){
    boost::uuids::uuid a_uuid=boost::uuids::random_generator()();
    _uuid=boost::uuids::to_string(a_uuid);
}

tcp::socket &CSession::GetSocket() {
    return _socket;
}

std::string CSession::GetUuid() {
    return _uuid;
}

void CSession::Start() {

}



