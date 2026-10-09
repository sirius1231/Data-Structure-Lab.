#include "ExerciseBST.h"

ExerciseBST::ExerciseBST(outstream& ost):os(ost){

}

ExerciseBST::~ExerciseBST() {
    terminate(root);
    root=nullptr;
}   

void ExerciseBST::insert(vector<string>& input) {
    target=root;
    ExerciseBSTNode*tmp=search(input[0]);
    if(tmp!=nullptr){
        tmp->set(input);
        return;
    }else{
        tmp=new ExerciseBSTNode(input);
        if(root=nullptr)root=tmp;
        else{
            target=root;
            position(tmp);
        }
    }


}
void ExerciseBST::position(ExerciseBSTNode*tmp) {
    if(tmp->getname()>target->getname()){
        if (target->get_right()==nullptr){
            target->connect(false,tmp);
            return;
        }else{
            target=target->get_right();
            position(tmp);
            return;
        }
    }else{
    if(tmp->getname()<target->getname()){
        if (target->get_left()==nullptr){
            target->connect(true,tmp);
            return;
        }
        else{
            target=target->get_left();
            position(tmp);
            return;
        }
    }
    }
}

ExerciseBSTNode* ExerciseBST::search(string exce) {
    return searchRC(root, exce);
}

ExerciseBSTNode* ExerciseBST::searchRC(ExerciseBSTNode* node, string exce) {
    if (node == nullptr) return nullptr;

    ExerciseBSTNode* found = searchRC(node->get_left(), exce);
    if (found != nullptr) return found;

    if (node->search(exce)) return node;

    return searchRC(node->get_right(), exce);
}

void ExerciseBST::print(ExerciseBSTNode* tmp) {
    if (tmp==nullptr)return;
    //Inorder Traversal(LVR)
    print(tmp->get_left());
    os<<tmp;
    print(tmp->get_right());

}

void ExerciseBST::delete_node(ExerciseBSTNode* input) {

    if(input == nullptr){
        return;
    }
    
    if(input->get_left() == nullptr && input->get_right() == nullptr){
        if(input->get_parents() != nullptr){
            bool k = (input->get_parents()->get_left() == input);
            input->get_parents()->disconnect(k);
        } else {
            root = nullptr;
        }
        delete(input);
    
    } else if(input->get_left() == nullptr || input->get_right() == nullptr){
        ExerciseBSTNode* tmp = (input->get_left() == nullptr) ? input->get_right() : input->get_left();
        
        if(input->get_parents() == nullptr){
            root = tmp;
            tmp->unconnect();
        } else {
            bool k = (input->get_parents()->get_left() == input);
            input->get_parents()->connect(k, tmp);
        }
        delete(input);

    } else {
        ExerciseBSTNode* tmp = input->get_right();
        while(tmp->get_left() != nullptr){
            tmp = tmp->get_left();
        }
        
        *input = *tmp;
        delete_node(tmp);
    }
}
void terminate(ExerciseBSTNode* input){
    if (input==nullptr)return;
    //memory delete(post oredr traversal)
    terminate(input->get_left());
    terminate(input->get_right());
    delete(input);
    return;

}
ExerciseBSTNode* ExerciseBST::delete_eq(string exce) {
    return delete_eqRC(root, exce);
}

ExerciseBSTNode* ExerciseBST::delete_eqRC(ExerciseBSTNode* node, string exce) {
    if (node == nullptr) return nullptr;

    delete_eqRC(node->get_left(), exce);
    
    node->delete_eq(exce);
    
    delete_eqRC(node->get_right(), exce);

    return node;
}
 