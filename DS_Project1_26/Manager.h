#pragma once
#include "WorkoutQueue.h"
#include "ExerciseBST.h"
#include "EquipmentBST.h"
#include "Routine.h"

#include <fstream>

using namespace std;

enum commend { Load, Add, Qpop, Search, Makert, Print, Delete, Exit, Error,Line };class outstream{
private:
    FILE* fp;
public:
    outstream ();
    outstream&  operator<<(string input);
    outstream&  operator<<(WorkoutQueueNode*input);
    outstream&  operator<<(ExerciseBSTNode* input);
	outstream&  operator<<(EquipmentBSTNode* input);
	outstream&  operator<<(RoutineNode* input );
	outstream&  operator<<( commend input);

    void line();
    void order(string order);
    void error(int k);
    ~outstream ();
};
class Manager {
private:
	WorkoutQueue q;
	ExerciseBST exb;
	EquipmentBST eqb;
	Routine rt;
	ifstream fcmd;
	ofstream flog;
	outstream os;
	bool road;

public:
	Manager();
	~Manager();

	void run(const char* command);

	void LOAD();
	void ADD(string commend);
	void QPOP();
	void SEARCH(string commend);
	void MAKERT(string commend);
	void PRINT(string commend);
	void DELETE(string commend);
	void EXIT();
	void COMMENDERROR();
};
