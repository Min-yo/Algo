#include <iostream>
using namespace std;


struct Node{
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this ->val=val;
        left = NULL;
        right = NULL;
    }
}

Node* add(Node* root, int val){
    if(root == NULL){
        return new Node*(val);
    }
    else if(root->val < val){
        root->right = add(root->right, val);
    }
    else if(root->val > val){
        root->left = add(root->left, val);
    }
    return root;
}

Node* remove(Node* root, val){
    if(root == NULL){
        return NULL;
    }
    else if (root->val == val){
        delete root;
        return NULL;
    }
    else if (root->val > val){
        root->left = remove(root->left, val);
    }
    else if(root->val < val){
        root->right = remove(root->right, val);
    }
    return root;
}







int main(){
    Node* root = NULL;
}



struct Node{
    int val;
    Node* right;
    Node* left;
    Node(int val){
        this->val = val;
        right = NULL;
        left = NULL;
    }
}