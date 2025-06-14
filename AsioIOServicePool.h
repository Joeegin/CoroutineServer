//
// Created by 乔益金 on 25-6-14.
//

#ifndef ASIOIOSERVICEPOOL_H
#define ASIOIOSERVICEPOOL_H
#include <memory>
#include<boost/asio.hpp>
#include<vector>

class AsioIOServicePool {
public:
    using IOService=boost::asio::io_context;
    using Work = boost::asio::executor_work_guard<boost::asio::io_context::executor_type>;
    using WorkPtr =std::unique_ptr<Work>;
    ~AsioIOServicePool();
    AsioIOServicePool(const AsioIOServicePool&) = delete;
    AsioIOServicePool& operator=(const AsioIOServicePool&)=delete;
    boost::asio::io_context& GetIOService();
    void Stop();
    static AsioIOServicePool& GetInstance();
private:
    AsioIOServicePool(std::size_t poolSize=std::thread::hardware_concurrency());
    std::vector<boost::asio::io_context> _ioServices;
    std::vector<WorkPtr> _works;
    std::vector<std::thread> _threads;
    std::size_t _nextIOService;
};



#endif //ASIOIOSERVICEPOOL_H
