#include "Manager.h"
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;
enum commend { Load, Add, Qpop, Search, Makert, Print, Delete, Exit, Error,Line };
Manager::Manager()
:os(),q(),exb(os),eqb(os),rt(os),fcmd(),flog(),road(false){

}

Manager::~Manager() {

}

void Manager::run(const char* command) {
    ifstream file(command);
    string tmp;
    while(    getline(file,tmp)){
   
    string order;
    string passorder;
    size_t space= tmp.find(' ');
    order = tmp.substr(0, space);
    passorder = tmp.substr(space + 1);
    try{
        if (order=="LOAD"){
            if(!passorder.empty())throw 1000;
            LOAD();
        }else if (order=="ADD"){
            if(passorder.empty())throw 1000;
            ADD(passorder);
        }else if (order=="QPOP"){
            if(!passorder.empty())throw 1000;
            QPOP();
        }else if (order=="SEARCH"){
            if(passorder.empty())throw 1000;
            SEARCH(passorder);
        }else if (order=="MAKRT"){
            if(passorder.empty())throw 1000;
            MAKERT(passorder);
        }else if (order=="PRINT"){
            if(passorder.empty())throw 1000;
            PRINT(passorder);
        }else if (order=="DELETE"){
            if(passorder.empty())throw 1000;
            DELETE(passorder);
        }else if (order=="EXIT"){
            if(passorder.empty())throw 1000;
            EXIT();
            return;
        }else{
            throw 1000;
        }

    }
    catch(int k){
        os.error(k);
    }
    }
}

void Manager::LOAD() {
    if(!road){
        //error
        os.error(100);
        return;
    }
    ifstream file("Exercise_List.txt");
    if (!file.is_open()) {
        //error
        os.error(100);
        return;
    }

    string line;
    int lineNumber = 1;

    os<<Load;
    while (std::getline(file, line)) {
        WorkoutQueueNode* tmp=new WorkoutQueueNode(line); 
        q.push(tmp);
        os<<tmp;
    }
    os<<Line;
    file.close();
    road=true;
    return ;
}

void Manager::ADD(string order) {

    if(!q.StringTest(order)){
        //error
        os.error(200);
        return;
    }
    WorkoutQueueNode* tmp=new WorkoutQueueNode(order); 
    if(q.exist(tmp)){
      //error
      os.error(200);
    }else{
        
        q.push(tmp); 
        os<<Add<<tmp<<Line;
    }
}

void Manager::QPOP() {
    if (q.empty()){
        os.error(300);
        return;
    }
    while(1){
        WorkoutQueueNode* tmp = q.pop();
        if(tmp==nullptr){
            break;
        }
        vector<string>info =tmp->info();
        exb.insert(info);
        eqb.insert(info);
        delete tmp;
    }
    
    os<<Qpop<<"Success"<<Line;
    return;
}

void Manager::SEARCH(string commend) {
    stringstream ss(commend);
    string word;
    vector<std::string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    try{
    if(words[0]=="EXERCISE"){
       ExerciseBSTNode* tmp =exb.search(words[1]);
       if (tmp==nullptr)throw 400;
    os<<Search<<tmp<<Line;

    }
    else if(words[0]=="EQUIPMENT"){
        EquipmentBSTNode* tmp = eqb.search(words[1]);
        if (tmp==nullptr)throw 400;
        os<<Search<<tmp<<Line;

    }
    else if(words[0]=="SET"){
        stringstream ssc(words[1]);
        vector<std::string> result;
        while (std::getline(ssc, word, '|')) {
        result.push_back(word);
        }
        RoutineNode* tmp=rt.exist(result);
        if (tmp==nullptr)throw 400;
        os<<Search<<tmp<<Line;

    }else{
        throw 1000;
    }
    }
    catch(int k){
        os.error(k);

    }
}

void Manager::MAKERT(string commend) {
    stringstream ss(commend);
    string word;
    vector<std::string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    
    try {
        if (words.size() < 3) throw 1000;

        vector<vector<string>> tmp_sets;
        vector<string> kkk;

        if (words[1] == "EXERCISE") {
            ExerciseBSTNode* tmp = exb.search(words[2]);
            if (tmp == nullptr) throw 500;

            for (int i = 0; i < tmp->getnum(); i++) {
                tmp_sets.push_back(tmp->info(i));
            }
        }
        else if (words[1] == "EQUIPMENT") {
            EquipmentBSTNode* tmp = eqb.search(words[2]);
            if (tmp == nullptr) throw 500;
            
            for (int i = 0; i < tmp->getnum(); i++) {
                tmp_sets.push_back(tmp->info(i));
            }
        }
        else if (words[1] == "SET") {
            stringstream ssc(words[2]);
            vector<std::string> result;
            while (std::getline(ssc, word, '|')) {
                result.push_back(word);
            }
            
            ExerciseBSTNode* tmp = exb.search(result[0]);
            if (tmp == nullptr) throw 500;

            kkk = tmp->searcheq(result[1]);
            if (kkk.empty()) throw 500;
            else tmp_sets.push_back(kkk);
        }
        else {
            throw 1000;
        }

        if (rt.get_count() + tmp_sets.size() > 10) {
            throw 500; 
        }

        for (size_t i = 0; i < tmp_sets.size(); i++) {
            if (rt.exist(tmp_sets[i]) != nullptr) {
                throw 500; 
            }
        }

        if (words[0] == "FRONT") {
            for (int i = tmp_sets.size() - 1; i >= 0; i--) {
                rt.push_front(tmp_sets[i]);
            }
        }
        else if (words[0] == "BACK") {
            for (size_t i = 0; i < tmp_sets.size(); i++) {
                rt.push_back(tmp_sets[i]);
            }
        }
        else {
            throw 1000; 
        }

        os << Makert; 
        os << Line;

    }
    catch (int k) {
        os.error(k);
    }
}

void Manager::PRINT(string commend) {
    try{
    if(commend=="EXERCISE"){
        if(exb.empty()){throw 600;}
        else{
        os<<Print;
        exb.print();
        os<<Line;}
    }else if(commend=="EQUIPMENT"){
        if(eqb.empty()){throw 600;}
        else{
        os<<Print;
        eqb.print();
        os<<Line;}

    
    }else if(commend=="ROUTINE"){
        if(rt.empty()){throw 600;}
        else{
            os<<Print;
            rt.print();
            os<<Line;}
    }else{
        throw 1000;
    }}
    catch(int k){
        os.error(k);
    }
}

void Manager::DELETE(string commend) {
    stringstream ss(commend);
    string word;
    vector<std::string> words;
    while (ss >> word) {
        words.push_back(word);
    }
    try {
        if (words[0] == "FRONT") {
            if (!rt.pop_front()) {
                throw 700;
            }
        }
        else if (words[0] == "BACK") {
            if (!rt.pop_back()) {
                throw 700;
            }
        }
        else if (words[0] == "EXERCISE") {
            rt.delete_ex(words[1]);
            ExerciseBSTNode* tmp_ex = exb.search(words[1]);
            if (tmp_ex != nullptr) {
                exb.delete_node(tmp_ex);
            }
            eqb.delete_ex(words[1]);
        }
        else if (words[0] == "EQUIPMENT") {
            rt.delete_eq(words[1]);
            EquipmentBSTNode* tmp_eq = eqb.search(words[1]);
            if (tmp_eq != nullptr) {
                eqb.delete_node(tmp_eq);
            }
            exb.delete_eq(words[1]);
        }
        else if (words[0] == "SET") {
            stringstream ssc(words[1]);
            vector<std::string> result;
            while (std::getline(ssc, word, '|')) {
                result.push_back(word);
            }
            
            rt.delete_node(result);
            
            ExerciseBSTNode* tmp_ex = exb.search(result[0]);
            if (tmp_ex != nullptr) {
                tmp_ex->delete_eq(result[1]);
            }
            
            EquipmentBSTNode* tmp_eq = eqb.search(result[1]);
            if (tmp_eq != nullptr) {
                tmp_eq->delete_ex(result[0]);
            }
        }
        else if (words[0] == "ROUTINE") {
            stringstream ssc(words[1]);
            vector<std::string> result;
            while (std::getline(ssc, word, '|')) {
                result.push_back(word);
            }
            rt.delete_node(result);
        }
        else {
            throw 1000;
        }
    }
    catch (int k) {
        os.error(k);
    }
}

void Manager::EXIT() {
    //delete memory
    os<<Exit<<"Success"<<Line;
}
void Manager::COMMENDERROR(){
    os.error(1000);
}
outstream::outstream ():fp(fopen("log.txt","a")){
   if (fp == nullptr) {
   perror("파일 열기 실패");
   }
}
outstream&  outstream::operator<<(string input){
    fprintf (this->fp,"%s",input.c_str());
    cout<<input<<endl;
    return (*this);

}
outstream&    outstream::operator<<(WorkoutQueueNode* input){
    (*this)<<(input->getstr());
    return (*this);
}
outstream&   outstream::operator<<(ExerciseBSTNode* input ){
    string name=input->getname();
    const vector<ExerciseSet>& info=input->getinfo();

    for(const auto& inputs: info){
        stringstream ss;
        ss<<name<<'/'<<inputs.equipment<<'/'<<inputs.duration<<'/'<<inputs.kcal;
        (*this)<<ss.str();
    }
    return (*this);
}
outstream&   outstream::operator<<(EquipmentBSTNode* input ){
    string name=input->getname();
    const vector<EquipmentSet>& info=input->getinfo();

    for(const auto& inputs: info){
        stringstream ss;
        ss<<inputs.exercise<<'/'<<name<<'/'<<inputs.duration<<'/'<<inputs.kcal;
        (*this)<<ss.str();
    } 
    return (*this);   
}
outstream&   outstream::operator<<(RoutineNode* input ){
    (*this)<<input->print();
    return (*this);
}
outstream&   outstream::operator<<( commend input){
    switch (input) {
    case Load:
        this->order("LOAD");break;
    case Add:
        this->order("ADD");break;
    case Qpop:
        this->order("QPOP");break;
    case Search:
        this->order("SEARCH");break;
    case Makert:
        this->order("MARKET");break;
    case Print:
        this->order("PRINT");break;
    case Delete:
        this->order("DELETE");break;
    case Exit:
        this->order("EXIT");break;
    case Error:
        this->order("ERROR");break;
    case Line:
        this->line();break;
    default:
        break;

}  
} 
void outstream::line(){
    (*this)<<"====================";
  
}
void outstream::order(string order){
    stringstream ss;
    ss<< "========"<<order<<"========";
    (*this)<<(ss.str());
}
void outstream::error(int k){
    this->order("ERROR");
    (*this)<<(to_string(k));
    this->line();
}
outstream::~outstream (){
   fclose(this->fp);
}
