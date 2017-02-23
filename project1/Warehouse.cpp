// Warehouse.cpp
// Purpose:
// By:      Hande Guven
// Date:    10/05/2016


#include "Warehouse.h"

using namespace std;

Warehouse::Warehouse(string n)
{
   num_p_units = string2int(n);
   p_units = new Packaging[num_p_units];
}

Warehouse::~Warehouse()
{
    delete[] p_units;
}

void Warehouse::fetchOrders(string filename, string assg_mode)
{
    r_unit.readOrder(filename);
    Order newOrder;
    current_time = 0;

    // fetches all the orders and stores them in a storage queue
    while ( not r_unit.isEmpty()) {
        if (r_unit.check_order(current_time)) {
            newOrder = r_unit.fetch(current_time);
            current_time += newOrder.fetch_duration;
            storage.enqueue(newOrder);
        } else
            current_time++;
    }
    assignPackaging(assg_mode);

}

void Warehouse::assignPackaging(string assg_mode)
{
    // chooses the assignment mode as long as there are orders in the warehouse
    while (not storage.isEmpty()) {
        if (assg_mode == "FEWEST_ITEMS") {
            fewest_items();
        } else if (assg_mode == "SHORTEST_TIME") {
            shortest_time();
        } else if (assg_mode == "ROUND_ROBIN") {
            round_robin();
        }
    }
    start_packaging();
}

void Warehouse::fewest_items()
{
    int fewest = 0;

    // gets the newOrder from storage
    Order newOrder = storage.dequeue();

    // finds the packaging_unit with the fewest items
    for (int i = 0; i < num_p_units; i++) {
        if (p_units[i].size() < p_units[fewest].size())
            fewest = i;
    }
    
    current_time += newOrder.fetch_duration;                 
    // sends the newOrder to the packaging_unit with the fewest items
    p_units[fewest].enqueue_order(newOrder);

}

void Warehouse::shortest_time()
{
    int shortest = 0;

    Order newOrder = storage.dequeue();

    for (int i = 0; i < num_p_units; i++) {
        if (p_units[i].remaining_time() < p_units[shortest].remaining_time())
            shortest = i;
    }

    current_time += newOrder.fetch_duration;       
    p_units[shortest].enqueue_order(newOrder);
}

void Warehouse::round_robin()
{
    // sends the orders to packaging unit(s)
    for (int i = 0; i < num_p_units; i++) {
        Order newOrder = storage.dequeue();
        // update the current time to 'fetch_duration' number of units ahead
        current_time += newOrder.fetch_duration;
        // enqueues the new order into the packaging unit queue
        // cout << "enqueueing p_unit from round_robin" << endl;
        p_units[i].enqueue_order(newOrder);
    }
}

void Warehouse::start_packaging()
{
    // gives the packaging unit(s) the command to start packing
    for (int i = 0; i < num_p_units; i++)
        p_units[i].pack_order();
}

void Warehouse::output()
{
    int sum = 0;
    int size = 1;
    int min = p_units[0].get_top().total_time;
    int max = p_units[0].get_top().total_time;
    
    while (not everything_packed()) {
        for (int i = 0; i < num_p_units; i++) {
            Order newOrder = p_units[i].dequeue();
            sum += newOrder.total_time;
            print_orders(newOrder);
            size++;
            if (newOrder.total_time < min)
                min = newOrder.total_time;
            else if (newOrder.total_time > max)
                max = newOrder.total_time;
        }   
    }
    print_stats(min, max, sum, size);


}

void Warehouse::print_orders(Order newOrder)
{
    cout << "<Order(" << newOrder.id << ") arrival_timestamp = " 
                << newOrder.arrival_timestamp << " fetch_duration = " 
                << newOrder.pack_duration << " total_time = " 
                << newOrder.total_time << endl;
}

bool Warehouse::everything_packed()
{
    bool everything_packed = false;

    for (int i = 0; i < num_p_units; i++) {
        if ( p_units[i].isEmpty())
            everything_packed = true;
        else 
            everything_packed = false;
    }

    return everything_packed;
}

void Warehouse::print_stats(int min, int max, int sum, int size)
{
    int mean = sum / size;

    cout << "min elapsed time " << min << " minutes" << endl;
    cout << "max elapsed time " << max << " minutes" << endl;
    cout << "mean elapsed time " << mean << " minutes" << endl;
    cout << size << " orders processed" << endl;

}


