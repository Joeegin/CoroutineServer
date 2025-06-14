//
// Created by 乔益金 on 25-6-14.
//

#include "AsioIOServicePool.h"
#include<iostream>
#include <boost/asio/executor_work_guard.hpp>
#include <boost/asio/io_context.hpp>
using namespace std;

AsioIOServicePool::AsioIOServicePool(std::size_t size):_ioServices(size),
    _works(size),_nextIOService(0) {
    for (std::size_t i=0;i<size;++i) {
        _works[i]=std::make_unique<Work>(boost::asio::make_work_guard(_ioServices[i]));
    }

    //遍历多个ioservice，创建多个线程，每个线程内部启动ioservice
    for (std::size_t i =0;i<_ioServices.size();++i) {
        _threads.emplace_back([this,i]() {
           _ioServices[i].run();
        });
    }
}

AsioIOServicePool::~AsioIOServicePool() {
    std::cout<<"~AsioIOServicePool()"<<std::endl;
}

boost::asio::io_context &AsioIOServicePool::GetIOService() {
    auto &service=_ioServices[_nextIOService++];
    if (_nextIOService== _ioServices.size()) {
        _nextIOService=0;
    }
    return service;
}

AsioIOServicePool &AsioIOServicePool::GetInstance() {
    static AsioIOServicePool instance(1);
    return instance;
}

void AsioIOServicePool::Stop() {
    for (auto & work:_works) {
        work.reset();
    }
    for (auto & t:_threads) {
        t.join();
    }
}


