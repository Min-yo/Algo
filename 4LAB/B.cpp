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
int cnt=0;
int t;
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
        if(cur->left) inOrder(cur->left);
        cnt++;
        if(cur->right) inOrder(cur->right);
    }

    void search(int t, Node * cur, Node * &target) {
        if(cur && !target) {
            if(cur -> val == t) target = cur;
            if(cur -> val < t) search(t, cur -> right, target);
            if(cur -> val > t) search(t, cur -> left, target);
        }
    }
public:
    BST(){
        root=nullptr;
    }

    void search(int t) {
        Node * target =nullptr;
        search(t, root, target);
        inOrder(target);
        cout<<cnt<<'\n';
    }

    void push(int val) {
        root=push(root, val);
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
    cin>>t;
    tree.search(t);
}