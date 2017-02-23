// Packaging.cpp
// Purpose:
// By:
// Date: 

#include "Packaging.h"

using namespace std;

Packaging::Packaging()
{
    total_pack_time = 0;
    pack_time_left = 0;
    sum_duration = 0;
}

Packaging::~Packaging()
{
    // nothing to do
}

void Packaging::enqueue_order(Order newOrder)
{    
    packaging_unit.enqueue(newOrder);
    sum_duration += newOrder.pack_duration;
}

void Packaging::pack_order()
{

    while (not packaging_unit.isEmpty()) {
        Order newOrder = packaging_unit.dequeue();
        // the packaging wait time is equal to the sum of 'pack_duration's of 
        // previous orders, which is the total_pack_time
        newOrder.pack_wait_time = total_pack_time;
        // update total_pack_time everytime an order is taken off the queue
        // and packed
        total_pack_time += newOrder.pack_duration;
        newOrder.total_time = 
        newOrder.fetch_duration + newOrder.pack_duration + 
        newOrder.fetch_wait_time + newOrder.pack_wait_time;
        packed_orders.enqueue(newOrder);
    }
}

int Packaging::size()
{
    return packed_orders.size();
}


// returns the sum of all pack_wdurations of all the orders that have 
// not been processed, aka. those still on the queue
int Packaging::remaining_time()
{
    pack_time_left = sum_duration - total_pack_time;
    return pack_time_left;
}

int Packaging::check_total_time()
{
    return packed_orders.top().total_time;
}

bool Packaging::isEmpty()
{
    return packed_orders.isEmpty();
}

Order Packaging::get_top()
{
    Order newOrder = packed_orders.top();
    
    return newOrder;
}

Order Packaging::dequeue()
{
    return packed_orders.dequeue();

}
