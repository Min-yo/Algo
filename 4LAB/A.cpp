#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};
class BST{
    Node * root;

    Node* push(Node * cur, int val){
        if (cur == NULL) {
            return new Node(val);
        }
        if (val < cur -> val) cur -> left = push(cur -> left, val);
        if (val > cur -> val) cur -> right = push(cur -> right, val);
        return cur;
    }
    void check(Node * cur, string s){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                if(cur -> left == NULL){
                    cout << "NO" << endl;
                    return;
                }
                cur = cur -> left;
            }
            if(s[i] == 'R'){
                if(cur -> right == NULL){
                    cout << "NO" << endl;
                    return;
                }
                cur = cur -> right;
            }
        }
        cout << "YES" << endl;
    }
public:
    BST(){
        root = NULL;
    }
    void push(int val){
        root = push(root, val);
    }
    void check(string s){
        check(root,s);
    }
};

int main() {
    BST tree;
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){ 
        int x;
        cin >> x;
        tree.push(x);
    }
    for(int i = 0; i < m; i++){
        string s;
        cin >> s;
        tree.check(s);
    }
}