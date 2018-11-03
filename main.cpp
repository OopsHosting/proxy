//
// Created by Паша Косило on 11/2/18.
//

#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <string>

#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/thread/mutex.hpp>

#include "src/tcp.h"
#include "src/udp.h"

int main(int argc, char* argv[]) {
    if (argc != 6)
    {
        std::cerr << "usage: proxy <local host ip> <local port> <forward host ip> <forward port> <protocol: udp/tcp>"
                     "tcp: proxy 0.0.0.0 80 17.0.0.1 80 tcp"
                     "udp: proxy 0.0.0.0 1935 17.0.0.1 1935 tcp" << std::endl;
        return 1;
    }

    const std::string protocol = argv[5];

    if(protocol == "udp") {
        return udpProxy(argv);
    } else if(protocol == "tcp") {
        return tcpProxy(argv);
    } else {
        std::cerr << "Please, set available protocol IN LOWER CASE" << std::endl;
        return 1;
    }

}