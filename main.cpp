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
        std::cerr << "usage: proxy <local host ip> <local port> <forward host ip> <forward port> <protocol: udp/tcp>" << std::endl;
        return 1;
    }

    const std::string protocol = argv[5];

    if(protocol == "udp") {
        return udpProxy(argc, argv);
    } else {
        if(protocol == "tcp") {
            return tcpProxy(argc, argv);
        } else {
            std::cerr << "Please, set normal protocol: 'udp' or 'tcp' IN LOWER CASE" << std::endl;
            return 1;
        }
    }
}