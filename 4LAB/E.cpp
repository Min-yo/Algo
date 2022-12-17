#include <iostream>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this -> val = val;
        left = right = NULL;
    }
};
class BST{
    Node* root;
    void find(Node * cur, int x, int y, int z){
        if (cur != NULL){
            if(cur -> val == x){
                push(cur, y, z);
            }
            find(cur -> left, x, y, z);
            find(cur -> right, x, y, z);
        }
    }
    Node* push(Node * cur, int y, int z){
        if (cur == NULL) {
            return new Node(y);
        }
        if(z == 0){
            cur -> left = push(cur -> left, y, 2);
        }
        if(z == 1){
            cur -> right = push(cur -> right, y, 2);
        }
        return cur;
    }
    void inOrder(Node * cur ){
        if (cur != NULL){
            inOrder(cur -> left);
            inOrder(cur -> right);
        }
    }
    int height(Node* cur){
        if(cur == NULL){
            return 0;
        }
        return max(height(cur -> left), height(cur -> right)) + 1;
    }
    int getWidth(Node* cur, int level){
        if(cur == NULL){
            return 0;
        }
        if(level == 1){
            return 1;
        }
        if(level > 1){
            return getWidth(cur -> left, level - 1) + getWidth(cur -> right, level - 1);
        }
    }
public:
    BST(){
        root = NULL;
    }
    void push(int x, int y, int z){
        if(root == NULL){
            root = push(root, x, z);
            root = push(root, y, z);
        }
        else{
            find(root, x, y, z);
        }
    }
    int getMaxWidth(){
        int maxWidth = 0;
        int h = height(root);
        for(int i = 1; i <= h; i++){
            int width = getWidth(root, i);
            if(width > maxWidth){ 
                maxWidth = width;
            }
        }
        return maxWidth;
    }
    void inOrder(){
        inOrder(root);
    }
};

int main() {
    BST tree;
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        tree.push(x, y, z);
    }
    cout << tree.getMaxWidth();
}