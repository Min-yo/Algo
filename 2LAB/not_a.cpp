#include<iostream>
#include<cmath>
using namespace std;
struct Node{
    int val;
    Node * next;

    Node(int val){
        this-> val = val;
        next = NULL;
    }
};

class LinkedList{
    public: 
    Node * head;
    LinkedList(){
        head = NULL;
    }

    void push(int val){
        Node * newNode = new Node(val);
        if (head == NULL){
            head = newNode;
        }
        else{
            Node *i = head;
            while(i -> next != NULL){
                i = i -> next;
            }
            i -> next = newNode;

        }
    }

    void print(){
        Node * i = head;
        while(i != NULL){
            cout<< i -> val <<" ";
            i = i -> next;
        }
    }

    void search(int k){   
    int x = 2147483647 , cnt = 0, ans, y;
    Node* current = head; 
    while (current != NULL) {
        if(k >=0 && current->val>=0){
            y = abs(current->val-k);
        }
        else if((current->val>=0 && k<0) || (current->val<0 && k>=0)){
            y = abs(abs(k)+abs(current->val));
        }
        else if(k<0 && current->val <0){
            y = abs(abs(current->val)-abs(k));
        }

        if (y < x){
            x = y;
            ans = cnt;
        }
        current = current->next; 
        cnt++;
    }
    cout<< ans;
    return;
}
};

/*

int search(int k){   
    int x = 0, cnt = 0, ans;
    Node* current = head; 
    while (current != NULL) {
        if (abs(current->key-k) < x)
            x = current->key;
            ans = cnt;
        current = current->next; cnt++;
    }
    return ans;
}

*/



int main(){
    LinkedList list;
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        list.push(a);
    }
    cin >> k;
    list.search(k);
    return 0;
}