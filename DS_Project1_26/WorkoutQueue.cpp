#include "WorkoutQueue.h"

WorkoutQueue::WorkoutQueue()
:head(nullptr),rear(nullptr){

}

WorkoutQueue::~WorkoutQueue() {
	WorkoutQueueNode* tmp =head;
	while(tmp!=nullptr){
		WorkoutQueueNode* tmpp = tmp->rtnext();
		delete tmp;
		tmp=tmpp;
	}
}

bool WorkoutQueue::empty() {
	if(size!=0)return false;
	return true;
}

bool WorkoutQueue::full() {
	if(size==100)return true;
	return false;
}

bool WorkoutQueue::exist(WorkoutQueueNode* input) {
	if(empty())return false;
	WorkoutQueueNode* tmp = head;
	bool result=false;
	while(tmp!=nullptr){
		if(input->exist(tmp))result =true;
		tmp = tmp->rtnext();
	}
	return result;
}
void WorkoutQueue::push(WorkoutQueueNode* input) {
	if(input==nullptr){
		//error
		return; 
	}
	
	if (empty()){
		head=input;
		rear=input;
	}else{
		rear->set(input);
	
		rear=input;
	}
	size++;
	return;
}

WorkoutQueueNode* WorkoutQueue::pop() {
	if(!empty()){
		WorkoutQueueNode* tmp= head;
		head=head->pop();
		size --;
		if(empty()){
			rear=nullptr;
		}
		return tmp;
	}
	return nullptr;
}

WorkoutQueueNode* WorkoutQueue::front() {
	WorkoutQueueNode* tmp= head;
	
	return head;
}
