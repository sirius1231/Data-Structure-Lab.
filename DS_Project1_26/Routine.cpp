#include "Routine.h"

Routine::Routine() :head(nullptr),tail(nullptr),count(0),total_kcal(0),total_sec(0),capacity(10){

}

Routine::~Routine() {
	RoutineNode* tmp=head;
	RoutineNode* tmpp=head->getnext();
	while(tmp!=nullptr){
		tmpp=tmp->getnext();
		delete(tmp);
	}
}
RoutineNode* Routine::mnode(const vector<string>& input){
	int k,l;
	stringstream ss(input[3]);
	ss>>k;
	stringstream ss(input[2]);
	ss>>l;

	RoutineNode* tmp =new RoutineNode (input[0],input[1],input[2],l,k);
	total_sec  +=l;
	total_kcal +=k;
	return tmp;
}

void Routine::push_front(const vector<string>& input) {
	RoutineNode* tmp =mnode(input);
	tmp->set(head);
	head=tmp;
	count ++;
}

void Routine::push_back(const vector<string>& input) {
	RoutineNode* tmp =mnode(input);
	tail->set(tmp);
	tail=tmp;
	count++;
}

bool Routine::pop_front() {
	if(this->empty())return false;
	RoutineNode* tmp =head;
	head=head->getnext();
	total_sec  -=tmp->getsec();
	total_kcal -=tmp->getkcal();
	delete(tmp);
	head->mhead();
	count--;
	return true;
}

bool Routine::pop_back() {
	if(this->empty())return false;
		RoutineNode* tmp =tail;
	tail=tail->getprev();
	total_sec  -=tmp->getsec();
	total_kcal -=tmp->getkcal();
	delete(tmp);
	tail->mtail();
	count--;
	return true;
}

bool Routine::delete_node(const vector<string>& input) {
	RoutineNode* tmp= head;
	bool ttt=false;
	while(tmp != nullptr){
		if(tmp->search(input[0],input[1])){
				total_sec  -=tmp->getsec();
	total_kcal -=tmp->getkcal();
			delete tmp;
			ttt=true;
		}
		
	}return ttt;
}

bool Routine::empty() {
	if(count ==0)return true;
	return false;
}

bool Routine::full() {
	if(count ==capacity)return true;
	return false;
}

RoutineNode* Routine::exist(const vector<string>& input) {
	RoutineNode* tmp=head;
	while(tmp!=nullptr){
		if(tmp->search(input[0],input[1]))return tmp;
	}
	return nullptr;
}

string Routine::print() {
	return "";
}

int Routine::duration() {
	return total_sec;
	return 0;
}

int Routine::calories() {
	return total_kcal;
	return 0;
}
void Routine::delete_ex(string input){
	RoutineNode*tmp=head;
	while(tmp!=nullptr){
		if(tmp->sec(input)){
			if(tmp==head){
				head=tmp->getnext();
			}
			if(tmp==tail){
				head=tmp->getprev();
			}
			delete tmp;
		}
	}
}
void Routine::delete_eq(string input){
	RoutineNode*tmp=head;
	while(tmp!=nullptr){
		if(tmp->seq(input)){
			if(tmp==head){
				head=tmp->getnext();
			}
			if(tmp==tail){
				head=tmp->getprev();
			}
			delete tmp;
		}
	}
}