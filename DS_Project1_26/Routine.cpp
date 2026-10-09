#include "Routine.h"

Routine::Routine() :head(nullptr),tail(nullptr),count(0),total_sec(0),total_kcal(0),capacity(10){
}

Routine::~Routine() {
	RoutineNode* tmp=head;
	while(tmp != nullptr){
		RoutineNode* tmpp = tmp->getnext();
		delete tmp;
		tmp = tmpp;
	}
}
RoutineNode* Routine::mnode(const vector<string>& input){
	int k;
	stringstream ss(input[3]);
	ss>>k;
	int min, sec;
    char colon;
    stringstream ss_time(input[2]);
    ss_time >> min >> colon >> sec;
    int total_s = (min * 60) + sec;

	RoutineNode* tmp =new RoutineNode (input[0],input[1],input[2],total_s,k);
	total_sec  +=total_s;
	total_kcal +=k;
	return tmp;
}
void Routine::push_front(const vector<string>& input) {
	RoutineNode* tmp = mnode(input);
	if (empty()) {
		head = tmp;
		tail = tmp;
	} else {
		tmp->set(head);
		head = tmp;
	}
	count++;
}

void Routine::push_back(const vector<string>& input) {
	RoutineNode* tmp = mnode(input);
	if (empty()) {
		head = tmp;
		tail = tmp;
	} else {
		tail->set(tmp);
		tail = tmp;
	}
	count++;
}
bool Routine::pop_front() {
	if(this->empty()) return false;
	RoutineNode* tmp = head;
	head = head->getnext();
	total_sec -= tmp->getsec();
	total_kcal -= tmp->getkcal();
	delete tmp;
	count--;
	
	if(head == nullptr) {
		tail = nullptr;
	} else {
		head->mhead();
	}
	return true;
}

bool Routine::pop_back() {
	if(this->empty()) return false;
	RoutineNode* tmp = tail;
	tail = tail->getprev();
	total_sec -= tmp->getsec();
	total_kcal -= tmp->getkcal();
	delete tmp;
	count--;
	
	if(tail == nullptr) {
		head = nullptr;
	} else {
		tail->mtail();
	}
	return true;
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
		tmp = tmp->getnext();
	}
	return nullptr;
}

string Routine::print() {
	stringstream ss;
    RoutineNode* tmp = head;
    
    while(tmp != nullptr) {
        ss << tmp->print() << "\n";
        tmp = tmp->getnext();
    }
    int min = total_sec / 60;
    int sec = total_sec % 60;
    
    ss << "Count : " << count << " / " << capacity << "\n";
    ss << "Time : " << min << "min " << sec << "sec\n";
    ss << "Kcal : " << total_kcal ; 
    
    
    return ss.str();
}

int Routine::duration() {
	return total_sec;
	return 0;
}

int Routine::calories() {
	return total_kcal;
	return 0;
}
void Routine::delete_ex(string input) {
	RoutineNode* tmp = head;
	while(tmp != nullptr) {
		RoutineNode* tmpp = tmp->getnext();
		if(tmp->sec(input)) {
			if(tmp == head) {
				head = tmp->getnext();
			}
			if(tmp == tail) {
				tail = tmp->getprev();
			}
			total_sec -= tmp->getsec();
			total_kcal -= tmp->getkcal();
			count --;
			delete tmp;
		}
		tmp = tmpp;
	}
}

void Routine::delete_eq(string input) {
	RoutineNode* tmp = head;
	while(tmp != nullptr) {
		RoutineNode* tmpp = tmp->getnext();
		if(tmp->seq(input)) {
			if(tmp == head) {
				head = tmp->getnext();
			}
			if(tmp == tail) {
				tail = tmp->getprev();
			}
			total_sec -= tmp->getsec();
			total_kcal -= tmp->getkcal();
			count --;
			delete tmp;
		}
		tmp = tmpp;
	}
}

bool Routine::delete_node(const vector<string>& input) {
	RoutineNode* tmp = head;
	bool ttt = false;
	while(tmp != nullptr) {
		RoutineNode* tmpp = tmp->getnext();
		if(tmp->search(input[0], input[1])) {
			if(tmp == head) {
				head = tmp->getnext();
			}
			if(tmp == tail) {
				tail = tmp->getprev();
			}
			total_sec -= tmp->getsec();
			total_kcal -= tmp->getkcal();
			count --;
			delete tmp;

			ttt = true;
		}
		tmp = tmpp;
	}
	return ttt;
}