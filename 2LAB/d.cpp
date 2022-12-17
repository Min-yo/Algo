#include<bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    int cnt;
    Node * next;
    Node(int x){
        val = x;
        cnt = 1;
        next = NULL;
    }
};
struct ll{
    Node * head;
    Node * tail;
    ll(){
        head = NULL;
        tail = NULL;
    }
    void add(int x){
        Node * newNode = new Node(x);
        int cnt = 0;
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            Node * cur = head;
            while( cur != NULL){
                if(cur -> val == x){
                    cur->cnt++;
                    break;
                }
                if(cur->next == NULL){
                    cur->next = newNode;
                    break;
                }
                cur = cur->next;
            }
        }
    }
    int findMode(){
        Node * cur  = head;
        int mode  = 0;
        while(cur != NULL){
            if(cur -> cnt > mode){
                mode = cur -> cnt;
            }
            cur = cur -> next; 
        }
        return mode;
    }
    void reverse(){
        Node * first = head;
        Node * second = NULL;
        while(first->next != NULL){
            second = first-> next;
            while (second != NULL)
            {
                if(first-> val < second->val){
                    swap(first->val, second-> val);
                    swap(first->cnt, second->cnt);
                }
                second = second -> next;
            }
            first = first -> next;
            
        } 
    }
    void print(){
        Node * cur = head;
        int mode = findMode();
        while(cur != NULL){
            if(cur -> cnt == mode){
                cout << cur->val << " ";
            }
            cur = cur->next;
        }
    }

};

int main(){
    int n; cin >> n;
    ll l;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.add(x);
    }
    l.reverse();
    l.print();
    

    return 0;
}