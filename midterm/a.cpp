#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left, *right;
    Node(int val){
        this->val=val;
        left = right = NULL;
    }
};

Node* add(Node*root, int val){
    if(!root) return new Node(val);
    else if(root->val > val) root->left = add(root->left, val);
    else if(root->val < val) root->right = add(root->right, val);
    return root;
}
bool is_left(Node* node, int i, int o){
    if(i >= o) return true;
    if(!node) return false;
    return is_left(node->left, i+1, o);
}
bool is_right(Node* node, int i, int o){
    if(i >= o) return true;
    if(!node) return false;
    return is_right(node->right, i+1, o);
}

int triples(Node* root,int o){
    int cnt = 0;
    if(root == NULL) return 0;
    if(is_left(root,0,o) && is_right(root, 0 , o)){
        return triples(root->left,o) + triples(root->right, o) + 1;
    }
    return triples(root->left,o) + triples(root->right, o);
}

int main(){
    int n, a;
    cin >> n;
    Node* root = NULL;
    for(int i = 0; i < n; i++){
        cin >> a;
        root = add(root, a);
    }
    vector<int> v(n-1);
    for(int i = 2; i <= n; i++){
        v[i-2] = triples(root,i);
    }
    for(int i = 0; i <n-1; i++){
        cout << v[i] << " ";
    }
    return 0;
}