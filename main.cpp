#include <iostream>
#include"CServer.h"
#include <csignal>
#include <thread>
#include <mutex>
#include "AsioIOServicePool.h"

int main() {
    try {
        auto &pool =AsioIOServicePool::GetInstance();
        boost::asio::io_context io_context;
        boost::asio::signal_set signals(io_context,SIGINT,SIGTERM);
        signals.async_wait([&io_context,&pool](auto,auto) {
            io_context.stop();
            pool.Stop();
        });

        CServer s(io_context,2025);
        io_context.run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}