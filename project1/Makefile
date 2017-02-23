# Makefile
# Hande Guven
# Date: 10/05/2016

CXX = clang++
CFLAGS = -Wall -Wextra

all: Orderqueue Retrieval Parser Warehouse main string2int Packaging
    ${CXX} ${CFLAGS} Orderqueue.o Retrieval.o Parser.o \
        Warehouse.o main.o string2int.o Packaging.o

Orderqueue: Orderqueue.cpp
    ${CXX} ${CFLAGS} -c Orderqueue.cpp

Retrieval: Retrieval.cpp
    ${CXX} ${CFLAGS} -c Retrieval.cpp

Parser: Parser.cpp
    ${CXX} ${CFLAGS} -c Parser.cpp

Warehouse: Warehouse.cpp
    ${CXX} ${CFLAGS} -c Warehouse.cpp

main: main.cpp
    ${CXX} ${CFLAGS} -c main.cpp

string2int: string2int.cpp
    ${CXX} ${CFLAGS} -c main.cpp

Packaging: Packaging.cpp
    ${CXX} ${CFLAGS} -c Packaging.cpp

run:
    ./a.out data/random1.txt 2 SHORTEST_TIME;
