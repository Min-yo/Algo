#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left, *right;
    Node(int val){
        this->val = val;
        right = left = NULL;
    }
};

Node* add(Node* root, int val){
    if(!root) return new Node(val);
    else if(root->val > val) root->left = add(root->left, val);
    else if(root->val < val) root->right = add(root->right, val);
    return root;
}
int ans = 0, lvl = 0;
void inorder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int t = q.size();
        for(int i = 0; i < t; i++){
            Node* top = q.front();
            q.pop();
            ans += top->val - lvl;
            if(top->left) q.push(top->left);
            if(top->right) q.push(top->right);
        }
        lvl++;
    }
    cout << ans;
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
    return 0;
}