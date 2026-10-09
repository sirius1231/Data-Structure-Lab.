#pragma once
#include "WorkoutQueueNode.h"


class RoutineNode {
private:
	string exercise;
	string equipment;
	string dtime;
	int seconds;
	int kcal;

	RoutineNode* prev;
	RoutineNode* next;

public:
	RoutineNode(string exercise,string equipment,string dtime,int seconds,int kcal) 
	: exercise(exercise), equipment(equipment), dtime(dtime), seconds(seconds), kcal(kcal), prev(nullptr), next(nullptr) {}
	~RoutineNode() {
		if(prev!=nullptr)this->prev->next=this->next;
		if(next!=nullptr)this->next->prev=this->prev;
	}

	void set(RoutineNode* tmp) {
		this->next=tmp;
		tmp->prev=this;
	}
	bool search(const vector<string>& tmp){
		stringstream ss (tmp[3]);
		int k;
		ss>>k;
		if(exercise==tmp[0]&&equipment==tmp[1]&&dtime==tmp[2]&&kcal==k){
			return true;
		}
		
	}
	bool search(string a,string b){
		if(exercise==a&&equipment==b){
			return true;
		}return false;
	}
	RoutineNode* getnext(){return next;}
	RoutineNode* getprev(){return prev;}

	void mhead(){
		this->prev=nullptr;
	}void mtail(){
		this->next=nullptr;
	}
	string print(){
		stringstream ss;
		ss<<exercise<<"/"<<equipment<<"/"<<dtime<<"/"<<kcal;
		return ss.str();
	}
	bool seq(string input){
		if(input==equipment){
			return true;
		}return false;
	}
	bool sec(string input){
		if(input==exercise){
			return true;
		}return false;
	}
	int getsec(){return seconds;};
	int getkcal(){return kcal;};

};
