#include <iostream>
using namespace std;

struct Node{
    string val;
    Node* next;
    bool ok;
    string ans;

    Node(string val){
        this->val = val;
        next = NULL;
        ok = true;
    }
};

string search(Node* head, Node* now){
    Node *cur = head;
    while(cur != now->next){
        if(cur->ok) {
            return cur->val;
        }
        cur = cur->next;
    }
    return "-1";
}

Node* push(Node *head, string val){
    Node *new_Node = new Node(val);
    if(head == NULL){
        head = new_Node;
        head->ans = head->val;
    }
    else{
        Node* cur = head;
        while(cur != NULL){
            if(cur->val == new_Node->val){
                cur->ok = false;
                new_Node->ok = false;
            }if(cur->next == NULL){
                cur->next = new_Node;
                new_Node->ans = search(head, new_Node);
                break;
            }
            cur = cur->next;
        }
    }
    return head;
}

void print(Node *head){
    Node *cur = head;
    while(cur != NULL){
        cout << cur->ans << " ";
        cur = cur->next;
    }
    cout << endl;
}


int main(){
    int t;
    cin >> t;
    Node* head = NULL;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            string val;
            cin >> val;
            head = push(head, val);
        }
        print(head);
        head = NULL;
    }
    return 0;
}