#pragma once
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;
class WorkoutQueueNode {
private:
	string excercise;
	string equipment;
	string dtime;
	int kcal;

	WorkoutQueueNode* next;
	WorkoutQueueNode* prev;

public:
	WorkoutQueueNode(string input) {
		istringstream ss (input);
		getline(ss,excercise,'|');
		getline(ss,equipment,'|');
		getline(ss,dtime,'|');
		ss>>kcal;
		this->prev=nullptr;
		this->next=nullptr;
	}
	~WorkoutQueueNode() {
		
	}

	void set(WorkoutQueueNode* nextc) {
		this->next=nextc;
		nextc->prev=this;
	}

	
	bool exist (WorkoutQueueNode* test){
		if(test->excercise!=this->excercise)return false;
		if(test->equipment!=this->equipment)return false;
		if(test->dtime!=this->dtime)return false;
		if(test->kcal!=this->kcal)return false;
		return true;
	}
	
	
	WorkoutQueueNode* pop(){
		if (this->next!=nullptr){
			this->next->prev=nullptr;
		}
		WorkoutQueueNode* tmp = this->next;
		this->next=nullptr;
		return tmp;
	}

	WorkoutQueueNode* rtnext(){return this->next;}
	string getstr(){
		stringstream ss ;
		ss<<excercise<<'/'<<equipment<<'/'<<dtime<<'/'<<kcal;
		return ss.str();
	}
	vector<string> info(){
		vector<string>tmp;
		tmp.push_back(excercise);
		tmp.push_back(equipment);		
		tmp.push_back(dtime);
		tmp.push_back(to_string(kcal));
		return tmp;
	}
};
