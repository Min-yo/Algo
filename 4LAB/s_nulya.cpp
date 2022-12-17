#include<iostream>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(int val){
        this->val = val;
        left = right = NULL;
    }
};
//BST
Node* add(Node* root, int val){
    if(!root) return new Node(val);// root == NULL
    else if(root->val < val){
        root->right = add(root->right, val);
    }
    else if(root->val > val){
        root->left = add(root->left, val);
    }
    return root;
}

int rightmost(Node* root){
    if (!root) return -1;
    else if(!root->right) return root->val;
    return rightmost(root->right);
}

Node* remove(Node* root, int val){
    if(!root) return NULL; // если корня нет
    else if(root->val == val){ // если значение корня совпадает с искомым значением
        if(!root->left && !root->right){ // если у корня нет детей
            delete root;
            return NULL;
        }
        else if(!root->left && root->right){ // если у корня один ребенок - справа
            root = root->right;
            delete root->right;
        }
        else if(root->left && !root->right){// если у корня один ребенок - слева
            root = root->left;
            delete root->left;
        }
        else if(root->left && root->right){ // если у корня есть два ребенка
            root->val = rightmost(root->left); // or leftmost(root->right)
            root->left = remove(root->left, root->val);
        }
        
    }
    else if (root->val < val){
        root->right = remove(root->right, val); // если корень меньше искомого значения = идем направо рекурсией
    }
    else if (root->val > val){
        root->left = remove(root->left, val);  // если корень больше искомого значения = идем налево рекурсией
    }
    return root;
}

Node* search(Node* root, int val){
    if(!root) return NULL;
    else if(root->val == val) return root;
    else if(root->val > val){
        return search(root->left, val);
    }
    else if(root->val < val){
        return search(root->right, val);
    }
}
int _getSize(Node* node) {
    if (!node) return 0;
    return _getSize(node->left) + _getSize(node->right) + 1;
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int getHeight(Node* root){
    if(!root) return -1;
    return max(getHeight(root->left), getHeight(root->right)) +1;
}

int getHeight2(Node* node, int &d) {
    if (!node) return 0;
    int left = getHeight2(node->left, d);
    int right = getHeight2(node->right, d);
    d = max(d, left + right);
    return max(left, right) + 1;
}

int findDiameter(Node* root) {
    int d = 0;
    getHeight2(root, d);
    return d;
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
    Node* find = search(root, 6);
    cout << find->val;
    
    return 0;
}