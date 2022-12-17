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
Node* _add(Node* root, int val){
    if(!root) return new Node(val);
    else if(root->val < val) {
        root->right = _add(root->right, val);
    }
    else if(root->val > val) {
        root->left = _add(root->left, val);
    }
    return root;
}
int _rightmost(Node* root){
    if (!root) return -1;
    else if(!root->right) return root->val;
    return _rightmost(root->right);
}

Node* _remove(Node* root, int val){
    if(!root) return NULL;
    else if (root->val == val){
        if(!root->right && !root->left){
            delete root;
            return NULL;
        }
        else if(!root->right && root->left){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(root->right && !root->left){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right && root->left){
            root->val = _rightmost(root->left);
            root->left = _remove(root->left, root->val);
        }
    }
    else if(root->val > val){
        root->left = _remove(root->left, val);
    }
    else if(root->val < val){
        root->right = _remove(root->right, val);
    }
    return root;
}


void _inorder(Node* root){
    if(!root) return;
    _inorder(root->left);
    cout << root->val << " ";
    _inorder(root->right);
}

int getHeight(Node* root){
    if(!root) return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    return max(l,r) +1;
}
int getHeight2(Node* root){
    if(!root) return -1;
    return max(getHeight(root->left), getHeight(root->right))+1;
}

int main(){
    Node* root = NULL;
    int n, a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        root = _add(root, a);
    }
    _remove(root, 3);
    _inorder(root);
    cout << endl << getHeight(root);
    return 0;
}