#include "Utils.h"

void addElementToQueue(PriorityQueue& pq, int key, int position) 
{
    pq.push(key);
}

void findAndAddElement(PriorityQueue& pq, int key, int position) 
{
    if (pq.find(key) != -1) 
    {
        addElementToQueue(pq, key, position);
    }
}

void findAndRemoveElement(PriorityQueue& pq, int key)
{
    pq.remove(key);
}

void calculateDifference(PriorityQueue& pq) 
{
    pq.process();
}