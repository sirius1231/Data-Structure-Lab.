#pragma once
#include <string>
#include <vector>
using namespace std;

struct ExerciseSet  {
	string equipment;
	string duration;
	int	kcal;
};

class ExerciseBSTNode {
private:
	string exercise;
	vector<ExerciseSet> sets;
	int count;

	ExerciseBSTNode* parents;
	ExerciseBSTNode* left;
	ExerciseBSTNode* right;

public:
	ExerciseBSTNode(vector<string>& input):
	exercise(input[0]),count(0),
	parents(nullptr),left(nullptr),right(nullptr){
		ExerciseSet tmp;
		tmp.equipment=input[1];
		tmp.duration=input[2];
		tmp.kcal=stoi(input[3]);
		sets.push_back(tmp);
		count++;
		
	}
	~ExerciseBSTNode() {}
	void set(vector<string>& input ) {
		ExerciseSet tmp;
		tmp.equipment=input[1];
		tmp.duration=input[2];
		tmp.kcal=stoi(input[3]);
		sets.push_back(tmp);
		count++;
	}
	ExerciseBSTNode* search(string exce) {
		if (exce==exercise){
			return this;
		}
		return nullptr;
	}
	void push_left(ExerciseBSTNode* input){
		left=input;
	}
	void push_right(ExerciseBSTNode* input){
		right=input;
	}
	const vector<ExerciseSet>& getinfo(){
		return sets;
	}
	ExerciseBSTNode* get_left(){
		return left;
	}
	ExerciseBSTNode* get_right(){
		return right;
	}
	ExerciseBSTNode* get_parents(){
		return parents;
	}
	string getname(){
		return exercise;
	}
	void connect(bool k,ExerciseBSTNode*tmp){
		if(k){
			left=tmp;
		}else{
			right=tmp;
		}
		tmp->parents=this;
		return;
	}
	ExerciseBSTNode& operator=(const ExerciseBSTNode& input){
		this-> exercise=input.exercise;
		this->sets=input.sets;
		this->count=input.count;
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
		info.push_back(exercise);
		info.push_back(sets[i].equipment);
		info.push_back(sets[i].duration);
		info.push_back(to_string(sets[i].kcal));
		return info;
	}
	int getnum(){
		return count;
	}
	bool delete_eq(string exce){
		
		for(int i =0;i<count;){
			if(sets[i].equipment==exce){
				sets.erase(sets.begin() + i);
				count--;
			}else{
				i++;
			}
		}
		if (count<=0){
			return true;
		}return false;
	}
	vector<string> searcheq(string k){
		for (int i=0;i<count;i++){
			if(sets[i].equipment==k){
				return this->info(i);
			}
		}
	}

};
