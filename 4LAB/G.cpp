#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;


template<class T>
struct Node{
    T val;
    Node<T> *left, *right;

    Node(T v) {
        val = v;
        left = right = nullptr;
    }
};

template<class T>
class BST{
    Node<T> *root;

    Node<T>* push(T val, Node<T> *cur){
        if (!cur) return new Node<T>(val);
        if (cur->val == val) return cur;
        if (cur->val > val) cur->left = push(val, cur->left);
        else cur->right = push(val, cur->right);
        return cur;
    }
    pll max_dist(Node<T> *cur, ll& ans){
        if (!cur) return {-1,-1};
        pll l = max_dist(cur->left, ans), r = max_dist(cur->right, ans);
        ans = max(ans, max(l.first, l.second) + max(r.first, r.second)+3);
        return {max(l.first, l.second)+1, max(r.first, r.second)+1};
    }

public:
    BST(): root(nullptr){}
    BST(T v): root(new Node<T>(v)){}

    void push(T val){
        root = push(val, root);
    }
    void max_dist(T &ans) {
        max_dist(root, ans);
    }
};

int main(){
    BST<ll> tree;
    ll n, x;
    cin>>n;
    while(n--){
        cin>>x;
        tree.push(x);
    }
    ll ans = 0;
    tree.max_dist(ans);
    cout<<ans;
}