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
}

int getHeight(Node* node, int &d) {
    if (!node) return 0;
    int left = getHeight(node->left, d);
    int right = getHeight(node->right, d);
    d = max(d, left + right+1);
    return max(left, right) + 1;
}

int findDiameter(Node* root) {
    int d = 0;
    getHeight(root, d);
    return d;
}

int main(){
    Node* root = NULL;
    int n, m, a;
    cin >> n;
    while(n--){
        cin >> a;
        root = add(root, a);
    }
    cout << findDiameter(root);
    
    return 0;
}