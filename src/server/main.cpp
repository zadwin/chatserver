#include "chatserver.hpp"
#include "chatservice.hpp"
#include <iostream>
#include <signal.h>
using namespace std;

// 处理服务器ctrl+c结束后，重置user的状态信息
void resetHandler(int)
{
    ChatService::instance()->reset();
    exit(0);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cerr << "command invalid! example: ./ChatServer 127.0.0.1 6000" << endl;
        exit(-1);
    }

    // 解析通过命令行参数传递的ip和port
    char *ip = argv[1];
    uint16_t port = atoi(argv[2]);

    signal(SIGINT, resetHandler);   // 处理信号的。

    EventLoop loop;                 // 一个IO线程
    InetAddress addr(ip, port);   // 服务端的监听端口。
    ChatServer server(&loop, addr, "ChatServer");   // 聊天服务器
    // 服务器启动。
    server.start();         // 启动的是 IO 线程池。
    loop.loop();            // 这里 loop相当于就是主 IO 线程。

    return 0;
}