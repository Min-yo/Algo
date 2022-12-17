#include <iostream> 
using namespace std; 
 
struct Node{ 
    int val; 
    Node*next; 
    Node (int val){ 
        this->val=val; 
        next=NULL; 
    } 
}; 
 
class linkedList{ 
public:  
Node*head; 
linkedList(){ 
    head = NULL; 
} 
 
void push(int val){ 
    Node*newNode=new Node(val); 
    if (head==NULL){ 
        head=newNode; 
    } 
    else { 
        Node*i = head; 
    while (i->next!=NULL){ 
        i=i->next; 
    } 
        i->next=newNode; 
} 
} 
 
void print(){ 
    Node*i=head; 
    while(i!=NULL){ 
    cout << i ->val<<" "; 
    i = i->next; 
} 
} 
}; 
 
int main (){ 
    int n; 
    cin >> n; 
    linkedList list; 
    for (int i=0; i<n; i++){ 
        int a; 
        cin >> a; 
        if (i%2==0){ 
            list.push(a); 
        } 
    } 
    list.print(); 
}       