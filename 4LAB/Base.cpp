#include <bits/stdc++.h>

using namespace std;

class Bst {
private:

    struct Node{

        Node(int x) {
            val = x;
        }

        int val;
        Node *left = nullptr;
        Node *right = nullptr;
    };

    Node *root = nullptr;

    void add(Node *node, int x) {
        if(node->val > x) {
            if (node->left)
                add(node->left, x);
            else
                node->left = new Node(x);
        } else {
            if(node->right)
                add(node->right, x);
            else
                node->right = new Node(x);
        }
    }

public:

    void add(int x) {
        if(!root)
            root = new Node(x);
        else
            add(root, x);
    }
};