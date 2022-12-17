#include <iostream>
#include <iterator>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val = ""){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
    Node* cur = new Node(s);
    if(head == NULL){
        head = cur;
        tail = cur;
    }
    else{
        tail->next = cur->prev;
        tail = cur;
    }
}
void add_front(string s){
    Node* cur = new Node(s);
    if(head == NULL){
        head = cur;
        tail = cur;
    }
    else{
        cur->next = head;
        head = cur;
    }
}
bool empty(){
    if(head==NULL && tail==NULL)
        return true;
    return false;
}
void erase_front(){
    Node* temp = head;
    head = head->next;
    temp = NULL;
}
void erase_back(){
    Node* temp = tail;
    tail = tail->prev;
    temp = NULL;
}
/*
T& front() { return *begin(); }
T& back() { return *(--end()); }

iterator begin() const { return iterator(head->next, head); }
iterator end() const { return iterator(head, head); }
*/
string front(){
    return head->val;
}
string back(){
    return tail->val;
}
void clear(){
    
    while(head != NULL){
        Node * temp = head;
        head = head->next;
        temp = NULL;
    }
    tail = NULL;
}
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// cout << "hi" << endl;
   	}
    return 0;
}