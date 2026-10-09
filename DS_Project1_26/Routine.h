#pragma once
#include "RoutineNode.h"
#include <string>

class Routine {
private:
	RoutineNode* head;
	RoutineNode* tail;
	int count;
	int total_sec;
	int total_kcal;
	int capacity;

public:
	Routine();
	~Routine();
	RoutineNode* mnode(const vector<string>& input);
	void push_front(const vector<string>& input);
	void push_back(const vector<string>& input);
	bool pop_front();
	bool pop_back();
	bool delete_node(const vector<string>& tmp);
	void delete_ex(string input);
	void delete_eq(string input);
	bool empty();
	bool full();
	RoutineNode* exist(const vector<string>& input);
	string print();
	int duration();
	int calories();
	int get_count() { return count; }
};