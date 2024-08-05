//
// Created by myheng2528 on 24-8-2.
//
#include "mystl.h"

void testPriorityQueue()
{
    mystl::priority_queue<int> priorityQueue;
    priorityQueue.push(10);
    priorityQueue.push(5);
    priorityQueue.push(6);
    priorityQueue.push(3);
    priorityQueue.push(15);
    priorityQueue.push(9);
    priorityQueue.push(20);
    priorityQueue.push(33);
    while (!priorityQueue.empty()){
        std::cout<<priorityQueue.top()<<std::endl;
        priorityQueue.pop();
    }
    std::cout<<"pass"<<std::endl;
}