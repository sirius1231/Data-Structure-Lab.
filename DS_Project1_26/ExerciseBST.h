#pragma once
#include "ExerciseBSTNode.h"
class outstream;

class ExerciseBST {
private:
	ExerciseBSTNode* root;
	outstream& os;
	ExerciseBSTNode* target;
public:
	ExerciseBST(outstream& ost);
	~ExerciseBST();

	void insert(vector<string>& input);
	void position(ExerciseBSTNode*tmp);
	ExerciseBSTNode* search(string exce);
	ExerciseBSTNode* searchRC(ExerciseBSTNode* node, string exce) ;
	bool empty() { return root == nullptr; }
	void print(ExerciseBSTNode* tmp);
	void delete_node(ExerciseBSTNode* input);
	ExerciseBSTNode*  delete_eq(string order);
	ExerciseBSTNode* delete_eqRC(ExerciseBSTNode* node, string exce);
	void terminate(ExerciseBSTNode* input);
	void print() { print(root); }
};
