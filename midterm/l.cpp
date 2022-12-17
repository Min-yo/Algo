#include <bits/stdc++.h>
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
    else if(root->val > val) root->left = add(root->left, val);
    else if(root->val < val) root->right = add(root->right, val);
    return root;
}
int cnt = 0;
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    if(!root->left && !root->right) cnt++;
    inorder(root->right);
}

int main(){
    int n, a;
    cin >> n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        cin >> a;
        root = add(root, a);
    }
    inorder(root);
    cout << cnt;
    return 0;
}