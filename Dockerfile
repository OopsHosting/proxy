FROM ubuntu:18.04
MAINTAINER Pavel Kosilo <kodosgames@gmail.com>
RUN apt-get update
RUN apt-get install -y libboost-all-dev cmake
RUN cmake .
RUN make
RUN ./proxy
EXPOSE 80
EXPOSE 443