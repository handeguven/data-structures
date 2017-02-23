// Orderqueue.cpp
// Purpose:
// By: hguven01
// Date: 10/05/2016

#include "Orderqueue.h"

Orderqueue::Orderqueue()
{
    capacity = 5;
    queue = new Order[capacity];
    current_size = 0;
    front = 0;
    back = 0;
}

Orderqueue::~Orderqueue()
{
    delete[] queue;
}

bool Orderqueue::isEmpty()
{
    if (current_size == 0)
        return true;
    else
        return false;
}

int Orderqueue::size()
{
    return current_size;
}

Order Orderqueue::top()
{
    if (current_size == 0)
        throw runtime_error("empty_stack");

    Order top = queue[front];

    return top;

}
// insert an element at the back of the circular array
void Orderqueue::enqueue(Order newOrder)
{
    if (nextIndex(back) == front)
        expand();

    queue[back] = newOrder;
    current_size++;
    back = nextIndex(back);
}

// remove an element from the front of the circular array
Order Orderqueue::dequeue()
{
    if (isEmpty())
        throw runtime_error("empty_stack");

    Order removed;

    removed = queue[front];
    current_size--;
    front = nextIndex(front);
    return removed;
}

void Orderqueue::expand()
{
    Order *new_array = new Order[capacity * 2];
    
    // copy the current element of the sequence to the new array
    for (int i = 0; i < capacity; i++)
        new_array[i] = queue[(front+i) % capacity];

    delete[] queue;

    front = 0;
    back = current_size;

    queue = new_array;

    capacity *= 2;  

}

int Orderqueue::nextIndex(int index)
{
    int nextIndex;

    // wraps around if at the [capacity] position
    nextIndex = (index + 1) % capacity;

    return nextIndex;
}
