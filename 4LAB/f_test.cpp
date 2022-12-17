#include<iostream>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(int val){
        this->val = val;
        rigth = left = NULL;
    }
};

Node* add(Node* root, int val){
    if(!root) return new Node(val);
    else if(root->val > val){
        root->left = add(root->left, val);
    }
    else if(root->val < val){
        root->right = add(root->right, val);
    }
    return root;
}
int cnt = 0;
void inorder(Node* root){
    if(!root) return NULL;
    else if(root->left && root->right) cnt++;
    if(root->left) return inorder(root->left);
    if(root->right) return inorder(root->rigth);
}

int main(){
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        root = add(root, a);
    }
    inorder(root);
    cout << cnt;
    return 0;
}