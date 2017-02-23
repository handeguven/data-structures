README for COMP15 Project 1

Created by: Hande Guven
Date: 10/14/2016

* * * * *
The program implements a simulation of an order processing facility with a retrieval unit and multiple packaging units. It reads in a file and input from the command line. It distributes the orders based on three different assignment methods and keeps track of the time each order spends in the facility, which allows the user to determine which parsing method is more efficient. 

* * * * *

Architecture

Order.h: declaration of functions and variables that make up the Order class

Parser.h: declaration of functions and variables that make up the Parser class

Parser.cpp: definitions of the functions inside the Parser.h file

Orderqueue.h: declaration of functions and variables that make up the Orderqueue class

Orderqueue.cpp: definitions of the functions inside the Orderqueue.h file

Retrieval.h: declaration of functions and variables that make up the Retrieval class

Retrieval.cpp: definitions of the functions inside the Retrieval.h file

Warehouse.h: declaration of functions and variables that make up the Warehouse class

Warehouse.cpp: definitions of the functions inside the Warehouse.h file

Packaging.h: declaration of functions and variables that make up the Packaging class

Packaging.cpp: definitions of the functions inside the Packaging.h file

* * * * *

Use the included Makefile to compile.

* * * * *

Outline of data structure

The program utilizes the abstract data type Queue using a circular dynamic array. A queue is optimal for this assignment because each order has to wait for previous orders to be processed before it can be sent to packaging. Therefore, we only need access to the top-most element at any given time. 

Furthermore, the circular dynamic array 
The queue is implemented in the Orderqueue class. 

The Retrieve class (the retrieval unit) reads in the input and saves all incoming orders in a queue called incomingOrders. 

The warehouse class is where the simulation is run. If current_time (which is the masterclock) is equal to the arrival timestamp of an order, Warehouse fetches it from incomingOrders queue in Retrieve. The fetch wait time of an Order is the time it waits for orders before it to be fetched and stored. Once all the orders are fetched and saved into the storage queue in Warehouse, they are sent to packaging unit(s) based on the assignment mode. Once all the orders are sent to and enqueued in all the packaging units, Warehouse gives the command for the packaging units to start packaging.

Packaging unit sets the pack wait time and total time once it is packed (dequeued from the packaging_unit queue.) It then saves all the orders that are already packed into a new queue called packed_orders. Warehouse receives these orders and dispatches them.

I changed the variable names fetch_time_left and pack_time_left in the Order class (which was written by TAs Max Bernstein and Erica Schwartz) to fetch_wait_time and pack_wait_time for clarity. 

* * * * *

Outline of algorithm

I insert at back of the circular array and remove at the front to imitate the behavior of a queue.

The Retrieve class will retrieve orders by calling dequeue() from the instance of a queue holding all incoming orders. Then assigns them to packaging units based on the assignment method chosen. The public functions num_orders() and total_time() in the Packaging class will be called to determine the appropriate method. 

In Warehouse, I initialize a dynamic array of type Packaging and it is the size of the number of packaging units. This dynamic array holds all the instances of Packaging, aka. "packaging units."

The simulation always waits orders to be enqueued to process them. For example, all orders have to be fetched and stored in a queue in Warehouse first. Assignment mode can be determined and orders can be sent to packaging unit(s) only after every order is fetched. The same logic applies for packaging. 

The output algorithm prints out elements based on which element has the smallest_total_time among all of the top elements in all of the queues. The min, max and mean values for time are accurate. Therefore we can assess the efficiency of different assignment modes by inputting the same file with different methods.



