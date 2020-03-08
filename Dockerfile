FROM debian:buster
RUN apt-get update && apt-get install -y gcc g++ make wget cmake
ADD . /cxsc
RUN cd /cxsc && mkdir build && cd build && cmake .. && make -j4 && make test
