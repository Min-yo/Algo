#include <iostream>
using namespace std;
int removed;
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p){ // 1
    if(head == NULL){
        Node* temp = node;
        head = node;
    }
    else{
        int cnt = 0;
        Node* temp = head;
        if(p == 0){
            head = node;
            head->next = temp;
        }
        else{
            while(cnt != p-1){
                temp = temp->next; // prev of position p
                cnt++;
            }Node* temp0 = temp->next; // p
            temp->next = node;
            node->next = temp0;
        }
    }
    return head;
}
 /*
Node* remove(Node* head, int p){ // 2
    if(head->next == NULL){
        head = NULL;
    }
    else{int cnt = 0;
        Node* temp = head;
        if(p == 0){
            head = temp->next;
            temp = NULL;
        }
        else{;
            while(cnt != p-1){
                temp = temp->next; // prev of position p
                cnt++;
            }
            temp->next = temp->next->next;
            temp->next->next = NULL;
        }
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){ //4
    if(p1 == p2){
        return head;
    }
    Node *prevP1 = NULL, *currP1 = head;
    int cnt = 0;
    while(cnt != p1){
        prevP1 = currP1;
        currP1 = currP1->next;
        
        cnt++;
    }
    Node *prevP2 = NULL, *currP2 = head;
    cnt = 0;
    while(cnt != p2){
        prevP2 = currP2;
        currP2 = currP2->next;
        cnt++;
    }
    
    if(prevP1 != NULL)
        prevP1->next = currP2;
    else    
        head = currP2;
    if(prevP2 != NULL)
        prevP2->next = currP1;
    else    
        head = currP1;
    Node* temp = currP2->next;
    currP2->next = currP1->next;
    currP1->next = temp;
    currP1 = currP2;

    return head;
}
Node* replace(Node* head, int p1, int p2) {
    if(p1 == p2){
        return head;
    }
    Node* temp = head; int cnt = 0;
    while(cnt != p1){
        temp = temp->next; 
        cnt++;
    }
    head = remove(head, p1);
    temp->next = NULL;
    head = insert(head, temp, p2);
    return head;
}*/
 
 Node* remove(Node* head, int p) {
  if(p > 1) remove(head->next, p - 1);
  else if(p) {
    removed = head->next->val;
    head->next = head->next->next;
  }
  else {
    removed = head->val;
    head = head->next;
  }
  return head;
}
 
Node* replace(Node* head, int p1, int p2) {
  head = remove(head, p1);
  
  head = insert(head, new Node(removed), p2);
  return head;
}
Node* reverse(Node* head){ // 5
    Node* current = head;
    Node *prev = NULL, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
 
void print(Node* head){ // 3
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* cyclic_left(Node* head, int x){
    int len = 1;
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
        len++;
    }
    int offset = x % len;
    if(offset == 0) return head;
    int newtailpos = offset; 
    Node* newtail = head;
    for(int i = 1; i < newtailpos; i++){
        newtail = newtail->next;
    }
    Node* newhead = newtail->next;
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}
 
Node* cyclic_right(Node* head, int x){
    int len = 1;
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
        len++;
    }
    int offset = x % len;
    if(offset == 0) return head;
    int newtailpos = len - offset; 
    Node* newtail = head;
    for(int i = 1; i < newtailpos; i++){
        newtail = newtail->next;
    }
    Node* newhead = newtail->next;
    newtail->next = NULL;
    tail->next = head;
    return newhead;
}
 
int main(){
    Node* head = NULL;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}