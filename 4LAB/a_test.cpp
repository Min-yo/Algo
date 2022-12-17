#include <iostream>
#include <string>
using namespace std;

struct Node{
    int val;
    Node* right, *left;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};

Node* add(Node* root, int val){
    if(!root) return new Node(val);
    else if(root->val < val){
        root->right = add(root->right, val);
    }
    else if(root->val > val){
        root->left = add(root->left, val);
    }
    return root;
}/*
bool check(Node*root, string s){
    if(!root && s.size()!=0) return false;
    else if()
}*/

void check(Node* root, string s){

    for(int i = 0; i< s.size(); i++){
        if(s[i] == 'L'){
            if(!root->left) { // root->left == NULL 
                cout << "NO" << endl;
                return;
            }
            root = root->left;
        }
        else if(s[i] == 'R'){
            if(!root->right){
                cout << "NO" << endl;
                return;
            }
            root = root->right;
        }
    }
    cout << "YES" << endl;
    return;
}

int main(){
    Node* root = NULL;
    int n, m, a;
    cin >> n >> m;
    while(n--){
        cin >> a;
        root = add(root, a);
    }
    string s;
    for(int i = 0; i < m; i++){
        cin >> s;
        check(root, s);
    }
    return 0;
}