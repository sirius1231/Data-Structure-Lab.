#pragma once
#include "WorkoutQueueNode.h"

class WorkoutQueue {
private:
	WorkoutQueueNode* head;
	WorkoutQueueNode* rear;
	int size = 0;
	int capacity;
public:
	WorkoutQueue();
	~WorkoutQueue();

	bool empty();
	bool full();
	bool exist(WorkoutQueueNode* input);
	void push(WorkoutQueueNode* input);
	bool StringTest(string test);
	WorkoutQueueNode* pop();
	WorkoutQueueNode* front();
};
