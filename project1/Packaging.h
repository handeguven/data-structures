// Packaging.h
// Purpose: The interface of Packaging.cpp
// By: Hande Guven
// Date: 10/06/2016
//
#ifndef Packaging_H
#define Packaging_H

#include "Order.h"
#include "Orderqueue.h"
#include <iostream>
#include <stdexcept>

using namespace std;

class Packaging {
    public:
        Packaging();
        ~Packaging();

        // package()
        // Purpose: Stores the incoming orders in the packaging unit/queue
        // Arguments: the new order struct
        // Return Value: Void         
        void enqueue_order(Order newOrder);

        // pack_order()
        // Purpose: Dequeues an order from the packaging_unit queue, sets
        // the pack_wait_time total_pack_time and total_time
        // Arguments: none
        // Return Value: Void  
        void pack_order();
        
        // num_orders()
        // Purpose: Returns the number of orders in the packaging unit  
        // Arguments: None
        // Return Value: THe integer value of the number of orders  
        int size();
        
        // total_time()
        // Purpose: Returns the sum of "pack time remaining" of 
        // all orders in the queue
        // Arguments: None
        // Return Value: The integer value of total remaining time
        //int total_time_remaining();

        // Purpose: returns the sum of all pack_wait_durations of all the orders that have 
        // not been processed
        // Arguments: none
        // Void: integer value of sum of all pack_wait_durations
        int remaining_time();

        // Purpose: returns the total_time of the top Order in the packed_order
        // queue
        // Arguments: none
        // Void: integer value of total_time of the top Order
        int check_total_time();

        // Purpose: Return true if the packed_orders queue is empty
        // Arguments: None
        // Return Value: True or false
        bool isEmpty();

        // Purpose: Returns the order at the top of the packed_orders queue
        // Arguments: None
        // Return Value: the Order at the top of the packed_orders queue
        Order get_top();

        // Purpose: Dequeues the Order at the top of the packed_orders queue
        // Arguments: None
        // Return Value: the Order struck that was dequeued
        Order dequeue();

    private:
        // new order sent to packaging are stored in packaging_unit
        Orderqueue packaging_unit;
        
        // orders that are done being packaged are stored in packed_orders;
        Orderqueue packed_orders;
        
        // sum of the 'pack_duration's of all the orders that have been packed
        int total_pack_time;
        
        // sum of the 'pack_duration's of all the order that have not been 
        // packed, ones still on the queue  
        int pack_time_left;
        
        // sum of all the 'pack_duration's on the packaging queue
        int sum_duration;


};

#endif