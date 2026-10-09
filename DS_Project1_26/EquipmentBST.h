#pragma once
#include "EquipmentBSTNode.h"
class outstream;
class EquipmentBST {
private:
	EquipmentBSTNode* root;
	outstream& os;
	EquipmentBSTNode* target;
public:
	EquipmentBST(outstream& ost);
	~EquipmentBST();

	bool empty() { return root == nullptr; }
	void insert(vector<string>& input);
	void position(EquipmentBSTNode*tmp);
	EquipmentBSTNode* search(string exce);
	void print(EquipmentBSTNode* tmp);
	void delete_node(EquipmentBSTNode* input);
	void terminate(EquipmentBSTNode* input);
	EquipmentBSTNode* delete_ex(string order);
	EquipmentBSTNode* delete_exRC(EquipmentBSTNode* node, string exce);
	void print() { print(root); }
};
