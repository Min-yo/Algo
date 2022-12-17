#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node * left;
    Node * right;
    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
int cnt = 0;
class MinTriangle{
    Node * root;

    Node * push(Node* cur, int val){
        if(cur == NULL) return new Node(val);
        if(cur -> val > val) cur -> left = push(cur -> left, val);
        if(cur ->val < val) cur -> right = push(cur -> right, val); 
        return cur;
    }

    void inOrder(Node * cur) {
        if(cur->left!=NULL && cur->right!=NULL) cnt++;
        if(cur->left) inOrder(cur->left);
        // cout<<cur->val<<" ";
        if(cur->right) inOrder(cur->right);
    }

public:
    MinTriangle() {
        root = NULL;
    }

    void push(int val) {
        root = push(root, val);
    }

    void inOrder() {
        inOrder(root);
    }
};

int main() {
    MinTriangle tree;
    int n;
    cin>>n;
    while(n--) {
        int x;
        cin>>x;
        tree.push(x);
    }
    tree.inOrder();
    cout<<cnt<<'\n';
}