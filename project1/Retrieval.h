// Retrieval.h
// Purpose: The interface of Retrieval.cpp
// By: Hande Guven
// Date: 10/06/2016

#ifndef Retrieval_H
#define Retrieval_H

#include "Orderqueue.h"
#include "Parser.h"

using namespace std;

class Retrieval {
    public:
        // constructor
        Retrieval();
        // destructor
        ~Retrieval();
        
        // readInFromFile()
        // Purpose: reads in the input, parses it into Order strucks, creates 
        // a new instance of Orderqueue class, adds the order to the back of 
        // queue
        // Arguments: the input
        // Return value: void 
        void readOrder(string input);

        // fetch()
        // Purpose: checks the list of orders that arrived, fetches the new
        // order
        // Arguments: the new order struct, the input command
        // Return Value: Void
        Order fetch(int current_time);

        // isEmpty()
        // Purpose: return true if there are no more orders left in the queue,
        // false otherwise
        // Arguments: the input
        // Return value: true or false 
        bool isEmpty();

        Order next_order();

        bool check_order(int current_time);

    private:   
        Orderqueue incomingOrders;     

};

#endif