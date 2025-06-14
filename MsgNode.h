//
// Created by 乔益金 on 25-6-14.
//

#ifndef MESGENODE_H
#define MESGENODE_H
#include<string>
#include <iostream>
#include <boost/asio.hpp>

class MsgNode {
public:
    MsgNode(short max_len):_total_len(max_len),_cur_len(0) {
        _data=new char[_total_len+1]();
        _data[_total_len]='\0';
    };
    ~MsgNode() {
        delete[] _data;
    }

    void Clear() {
        ::memset(_data,0,_total_len);
        _cur_len=0;
    }
protected:
    short _total_len;
    short _cur_len;
    char *_data;
};

class RecvNode :public MsgNode {
public:
    RecvNode(short max_len,short msg_id);
private:
    short _msg_id;
};

class SendNode :public MsgNode {
public:
    SendNode(const char* msg,short max_len,short msg_id);
private:
    short _msg_id;
};


#endif //MESGENODE_H
