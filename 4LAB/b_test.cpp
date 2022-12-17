#include <iostream>
using namespace std;

struct Node{
    int val;    
    Node* left, *right;     
    Node(int val){
        left = right = NULL;
        this->val = val;
    }
};
Node* add(Node* root, int val){
    if(!root) return new Node(val);
    else if(root->val < val) {
        root->right = add(root->right, val);
    }
    else if(root->val > val) {
        root->left = add(root->left, val);
    }
    return root;
}

Node* search(Node* root, int val){
    if(!root) return NULL;
    else if(root->val == val) return root;
    else if(root->val > val) return search(root->left, val);
    else if(root->val < val) return search(root->right, val);
}

int cnt = 0;
void inorder(Node* root){
    if (!root) return;
    if(root->left) inorder(root->left);
    cnt++;
    if(root->right) inorder(root->right);
}
int _getSize(Node* node) {
    if (!node) return 0;
    return _getSize(node->left) + _getSize(node->right) + 1;
}
void _inorder(Node* root){
    if(!root) return;
    _inorder(root->left);
    cout << root->val << " ";
    _inorder(root->right);
}
int main(){
    Node* root = NULL;
    int n, a, k;
    cin >> n;
    while(n--){
        cin >> a;
        root = add(root, a);
    }
    cin >> k;
    Node* root2 = search(root, k);
    inorder(root2);
    cout << cnt << " " << _getSize(root2);
    return 0;
}