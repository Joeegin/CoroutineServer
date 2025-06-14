cmake_minimum_required(VERSION 3.31)
project(clion)

set(CMAKE_CXX_STANDARD 20)

# 查找 Boost 库
find_package(Boost 1.88 REQUIRED COMPONENTS filesystem system)  # 按需添加组件
include_directories(${Boost_INCLUDE_DIRS})

# 查找 JsonCpp 库
find_package(Jsoncpp REQUIRED)
include_directories(${JSONCPP_INCLUDE_DIRS})

add_executable(clion main.cpp
        MsgNode.cpp
        MsgNode.h
        const.h
        AsioIOServicePool.cpp
        AsioIOServicePool.h
        CServer.cpp
        CServer.h
        CSession.cpp
        CSession.h
        LogicSystem.cpp
        LogicSystem.h
        )

# 链接库
target_link_libraries(clion
        ${Boost_LIBRARIES}
        ${JSONCPP_LIBRARIES}
        jsoncpp_lib
)
