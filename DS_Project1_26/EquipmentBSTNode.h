#pragma once
#include <string>
#include <vector>
using namespace std;

struct EquipmentSet {
	string exercise;
	string duration;
	int kcal;
};

class EquipmentBSTNode {
private:
	string equipment;
	vector<EquipmentSet> sets;
	int count;
	EquipmentBSTNode* parents;
	EquipmentBSTNode* left;
	EquipmentBSTNode* right;

public:
	EquipmentBSTNode(vector<string>& input):
	equipment(input[1]),count(0),
	parents(nullptr),left(nullptr),right(nullptr){
		EquipmentSet tmp;
		tmp.exercise=input[0];
		tmp.duration=input[2];
		tmp.kcal=stoi(input[3]);
		sets.push_back(tmp);
		count++;
	}
	~EquipmentBSTNode() {}

	void set(vector<string>& input ) {
		EquipmentSet tmp;
		tmp.exercise=input[0];
		tmp.duration=input[2];
		tmp.kcal=stoi(input[3]);
		sets.push_back(tmp);
		count++;
	}

	EquipmentBSTNode* search(string exce) {
		if (exce==equipment){
			return this;
		}
		return nullptr;
	}
	void push_left(EquipmentBSTNode* input){
		left=input;
	}
	void push_right(EquipmentBSTNode* input){
		right=input;
	}
	const vector<EquipmentSet>& getinfo(){
		return sets;
	}
	EquipmentBSTNode* get_left(){
		return left;
	}
	EquipmentBSTNode* get_right(){
		return right;
	}
	EquipmentBSTNode* get_parents(){
		return parents;
	}
	string getname(){
		return equipment;
	}
	void connect(bool k,EquipmentBSTNode*tmp){
		if(k){
			left=tmp;
		}else{
			right=tmp;
		}
		tmp->parents=this;
		return;
	}
	EquipmentBSTNode& operator=(const EquipmentBSTNode& input){
		this-> equipment=input.equipment;
		this->sets=input.sets;
		this->count=input.count;
		return *this;
	}
	void disconnect(bool k){
		if(k){
			left=nullptr;
		}else{
			right=nullptr;
		}
		return;
	}
	void unconnect(){
		parents=nullptr;
	}
	vector<string> info(int i){
		vector<string> info;
		info.push_back(sets[i].exercise);
		info.push_back(equipment);
		info.push_back(sets[i].duration);
		info.push_back(to_string(sets[i].kcal));
		return info;
	}
	bool delete_ex(string exce){
		for(int i = 0; i < count; ){
			if(sets[i].exercise == exce){
				sets.erase(sets.begin() + i);
				count--;
			}else{
				i++;
			}
		}
		if (count <= 0){
			return true;
		}
		return false;
	}
	int getnum() { return count; }
};
