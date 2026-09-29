# Programming-Project-1
This project demonstrates implementing a priority queue ADT using heap algorithm in a C++ single-core CPU scheduling simulation. The scheduler manages and prioritizes each process by highest priority and then by arrival time.


A C++ simulation of a single-core CPU scheduler that manages processes using a custom priority queue implementation. The simulator supports both file-based and randomly generated processes and tracks process execution across individual CPU cycles.
The project implements a heap-based priority queue from scratch and uses process priority and arrival time to determine scheduling order. Once a process begins executing, it runs to completion before another process is scheduled. The simulator also calculates performance statistics such as average waiting time, process creation rate, and average execution time.
Key concepts: C++, priority queues, binary heaps, custom comparators, process scheduling, file I/O, random process generation, and simulation.
