// Retrieval.cpp
// Purpose:
// By: Hande Guven
// Date: 10/13/2016

#include "Retrieval.h"

Retrieval::Retrieval()
{
    // nothing to do
}

Retrieval::~Retrieval()
{
    // nothing to do
}

void Retrieval::readOrder(string filename)
{
    Order newOrder;
    Parser p(filename);

    while (not p.is_done()) {
        newOrder = p.read_order();
        incomingOrders.enqueue(newOrder);
    }

}
Order Retrieval::fetch(int current_time)
{
    Order newOrder = incomingOrders.dequeue();

    newOrder.fetch_wait_time = 
    current_time - newOrder.arrival_timestamp;

    return newOrder;

}

bool Retrieval::isEmpty()
{
    if (incomingOrders.isEmpty())
        return true;
    else 
        return false;
}

Order Retrieval::next_order()
{
    return incomingOrders.top();
}

bool Retrieval::check_order(int current_time)
{
    Order newOrder = incomingOrders.top();

    if (current_time >= newOrder.arrival_timestamp)
        return true;
    else
        return false;
}

