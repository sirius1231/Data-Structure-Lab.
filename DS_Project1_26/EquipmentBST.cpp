#include "EquipmentBST.h"
#include "Manager.h"
EquipmentBST::EquipmentBST(outstream& ost):os(ost) {
    root = nullptr;
}

EquipmentBST::~EquipmentBST() {
    terminate(root);
    root=nullptr;
}
void EquipmentBST::insert(vector<string>& input) {
    target = root;
    EquipmentBSTNode* tmp = search(input[1]); 
    if(tmp != nullptr){
        tmp->set(input);
        return;
    } else {
        tmp = new EquipmentBSTNode(input);
        if(root == nullptr) root = tmp; 
        else {
            target = root;
            position(tmp);
        }
    }
}

EquipmentBSTNode* EquipmentBST::search(string exce) {
    EquipmentBSTNode* tmp = root;
    while (tmp != nullptr) {
        if (tmp->getname() == exce) return tmp;
        else if (tmp->getname() > exce) tmp = tmp->get_left();
        else tmp = tmp->get_right();
    }
    return nullptr;
}
void EquipmentBST::position(EquipmentBSTNode*tmp) {
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

void EquipmentBST::print(EquipmentBSTNode* tmp) {
    if (tmp==nullptr)return;
    //Inorder Traversal(LVR)
    print(tmp->get_left());
    os<<tmp;
    print(tmp->get_right());

}


void EquipmentBST::delete_node(EquipmentBSTNode* input) {

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
        EquipmentBSTNode* tmp = (input->get_left() == nullptr) ? input->get_right() : input->get_left();
        
        if(input->get_parents() == nullptr){
            root = tmp;
            tmp->unconnect();
        } else {
            bool k = (input->get_parents()->get_left() == input);
            input->get_parents()->connect(k, tmp);
        }
        delete(input);

    } else {
        EquipmentBSTNode* tmp = input->get_right();
        while(tmp->get_left() != nullptr){
            tmp = tmp->get_left();
        }
        
        *input = *tmp;
        delete_node(tmp);
    }
}
void EquipmentBST::terminate(EquipmentBSTNode* input){
    if (input==nullptr)return;
    //memory delete(post oredr traversal)
    terminate(input->get_left());
    terminate(input->get_right());
    delete(input);
    return;

}
EquipmentBSTNode* EquipmentBST::delete_ex(string exce) {
    return delete_exRC(root, exce);
}

EquipmentBSTNode* EquipmentBST::delete_exRC(EquipmentBSTNode* node, string exce) {
    if (node == nullptr) return nullptr;

    delete_exRC(node->get_left(), exce);
    node->delete_ex(exce);
    delete_exRC(node->get_right(), exce);

    return node;
}