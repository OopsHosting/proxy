//
// Created by Паша Косило on 11/3/18.
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

#include "udp/udp_proxy.h"

int udpProxy(int argc, char* argv[])
    {

        const unsigned short local_port   = static_cast<unsigned short>(::atoi(argv[2]));
        const unsigned short forward_port = static_cast<unsigned short>(::atoi(argv[4]));
        const std::string local_host      = argv[1];
        const std::string forward_host    = argv[3];

        boost::asio::io_service ios;

        try
        {
            udp_proxy::m_udpProxyServer svrTest(ios,
                                                local_host,local_port,
                                                forward_host,forward_port);

            ios.run();
        }
        catch(std::exception& e)
        {
            std::cerr << "main : Error: " << e.what() << std::endl;
            return 1;
        }

        return 0;
    }