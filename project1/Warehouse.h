// Warehouse.h
// Purpose: The interface of Retrieval.cpp
// By: hguven01
// Date: 10/06/2016

#ifndef Warehouse_H
#define Warehouse_H

#include "Retrieval.h"
#include "Packaging.h"
#include "string2int.h"

using namespace std;

class Warehouse {
    public:
        Warehouse(string n);
        ~Warehouse();
        
        // output()
        // Purpose: reads in the input file, and fetches arriving orders from
        // the retrieval unit, enqueues them in the storage queue
        // Arguments: strings for filename and assignment mode
        // Return Value: Void
        void fetchOrders(string filename, string assg_mode);
       
        // output()
        // Purpose: assigns Orders to packaging units based on assignment mode
        // Arguments: string assignment mode
        // Return Value: Void
        void assignPackaging(string assg_mode);  
        
        // output()
        // Purpose: goes through all the orders in all the packaging units,
        // prints out the orders in ascending total_time order
        // Arguments: None
        // Return Value: Void
        void output();

    private:
        Warehouse();
        Retrieval r_unit;
        // a dynamic array which holds all the packagin units 
        Packaging *p_units;
        Orderqueue storage;
        int num_p_units;
        int current_time;

        // fewest_items()
        // Purpose: Sends the order to the packaging unit with the smallest
        // size()
        // Arguments: the new order struct
        // Return Value: Void
        void fewest_items();

        // shorters_time()
        // Purpose: Sends the order to the packaging unit with the smallest
        // total_time()
        // Arguments: the new order struct, the input command
        // Return Value: Void      
        void shortest_time();
        
        // round_robin()
        // Purpose: Sends the order to the packaging unit based on "taking
        // turns"
        // Arguments: the new order struct, the input command
        // Return Value: Void        
        void round_robin();

        // start_packaging()
        // Purpose: Initiates packaging in the packaging unit(s)
        // Arguments: None
        // Return Value: Void 
        void start_packaging();

        // print_orders()
        // Purpose: prints the order information
        // Arguments: None
        // Return Value: Void
        void print_orders(Order newOrder);

        // everything_packed()
        // Purpose: returns true if the all packaging unit queues still has 
        // elements in it, false if it is empty
        // Arguments: None
        // Return Value: true or false
        bool everything_packed();

        void print_stats(int min, int max, int sum, int size);



};

#endif