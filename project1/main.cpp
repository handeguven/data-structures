// main.cpp

#include "Warehouse.h"

using namespace std;

int main(int argc, char *argv[])
{
    (void)argc;
    Warehouse wh(argv[2]);
    wh.fetchOrders(argv[1], argv[3]);
    wh.output();
    return 0;
}



