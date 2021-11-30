/*
    3 synch mechanisms in pthread.h
        - mutex: locks, block access to variable by other threads
        - joins: make a thread wait till other complete
        - condition variables: a way to comm to other threads

    mutex basically a lock to synchronise access to resources
        - one thread can use the resource at a time using a "key" (maybe)
    
    typical mutex sequence:
        - create and initalize mutex var
        - several threads attempt to lock mutex
        - only one succeeds and that thread own smutex
        - thread owner performa soperations
        - owner unlocks mutex
        - another thread aquires mutex and repeats process
        - mutex destroyed

    when several threads compete for a mutex, the losers block at the call waiting
        - deadlock can occur when using a mutex lock; 
        - make sure threads aquite locks in agreed order

*/
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h> 
#include <pthread.h> 
