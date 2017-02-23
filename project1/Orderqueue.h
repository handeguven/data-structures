// Orderqueue.h
// Purpose: The interface of Orderque.cpp
// By: hguven01
// Date: 10/05/2016

#ifndef Orderqueue_H
#define Orderqueue_H

#include <iostream>
#include <stdexcept>
#include "Order.h"

using namespace std;

class Orderqueue {
    public:
        // constructor
        Orderqueue();
        // destructor
        ~Orderqueue();
        
        // Purpose: Return true if the specific instance of the class is empty
        // Arguments: None
        // Return Value: True if the instance of the class is empty, false 
        // otherwise
        bool isEmpty();
        
        // Purpose: Return the number of orders on the queue
        // Arguments: None
        // Return Value: An integer that is the number of orders on the queue
        int size();

        // Purpose: Return the first order on the queue
        // Arguments: None
        // Return Value: An Order struck that is the fist order on the queue
        Order top();
        
        // Purpose: Adds a new element at the back of the queue
        // Arguments: an instance of the struck Order
        // Return: Void
        void enqueue(Order newOrder);
        
        // Purpose: Removes and returns an element from the front of the queue
        // Arguments: NOne
        // Return Value: The struck that was removed
        Order dequeue();

    private:
        Order *queue;
        int capacity;
        int current_size;
        int front;
        int back;
        // Purpose: expand function for dynamic array
        // Arguments: none
        // Return value: void
        void expand();
        // Purpose: returns the integer value of the next index, wraps around
        // Arguments: an index value 
        // Return value: the integer value of the next index of the value 
        // passed in
        int nextIndex(int index);
};

#endif