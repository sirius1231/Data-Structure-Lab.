#pragma once
#include "EquipmentBSTNode.h"
#include "Manager.h"

class EquipmentBST {
private:
	EquipmentBSTNode* root;
	outstream& os;
	EquipmentBSTNode* target;
public:
	EquipmentBST(outstream& ost);
	~EquipmentBST();

	
	void insert(vector<string>& input);
	void position(EquipmentBSTNode*tmp);
	EquipmentBSTNode* search(string exce);
	void print(EquipmentBSTNode* tmp);
	void delete_node(EquipmentBSTNode* input);
	void terminate(EquipmentBSTNode* input);
};
