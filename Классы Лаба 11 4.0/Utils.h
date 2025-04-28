#pragma once
#include "PriorityQueue.h"

void addElementToQueue(PriorityQueue& pq, int key, int position);
void findAndAddElement(PriorityQueue& pq, int key, int position);
void findAndRemoveElement(PriorityQueue& pq, int key);
void calculateDifference(PriorityQueue& pq);