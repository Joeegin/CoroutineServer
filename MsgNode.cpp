//
// Created by 乔益金 on 25-6-14.
//

#include "MsgNode.h"

#include "const.h"

RecvNode::RecvNode(short max_len, short msg_id):
    MsgNode(max_len),
    _msg_id(msg_id) {

}

SendNode::SendNode(const char *msg, short max_len, short msg_id) :
    MsgNode(max_len+HEAD_TOTAL_LEN),
    _msg_id(msg_id){
    //先发送id，转成网络字节序
    short msg_id_net=boost::asio::detail::socket_ops::host_to_network_short(msg_id);
    memcpy(_data,&msg_id_net,HEAD_ID_LEN);
    //再发送数据，转为网络字节序
    short max_len_net=boost::asio::detail::socket_ops::network_to_host_short(max_len);
    memcpy(_data+HEAD_ID_LEN,&max_len_net,HEAD_ID_LEN);
    memcpy(_data+HEAD_TOTAL_LEN,msg,max_len);


}




