#include <bits/stdc++.h>
using namespace std;
struct Node {
    int val;
    Node*left;
    Node*right;

    Node(int val) {
        this->val=val;
        left=nullptr;
        right=nullptr;
    }
};
int sum = 0;
class BST{
    Node * root;
    
    Node * push(Node * cur, int val) {
        if(cur==nullptr) {
            return new Node(val);
        }
        if(val < cur->val) cur->left = push(cur->left, val);
        if(val > cur->val) cur->right = push(cur->right, val);
        return cur;
    }
    void inOrder(Node * cur) {
        if(cur->right) inOrder(cur->right);
        sum+=cur->val;
        cout<<sum<<" ";
        if(cur->left) inOrder(cur->left);
    }
public:
    BST(){
        root=nullptr;
    }
    void push(int val) {
        root=push(root, val);
    }

    void inOrder() {
        inOrder(root);
    }
};


int main() {
    BST tree;
    int n;
    cin>>n;
    while(n--) {
        int x;
        cin>>x;
        tree.push(x);
    }
    tree.inOrder();
}