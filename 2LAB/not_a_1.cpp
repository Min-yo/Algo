#include<iostream>
#include<cmath>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

	ListNode()
	{
		this->val = 0;
		this->next = NULL; 
	}

	ListNode(int val)
	{
		this->val = val;
		this->next = NULL;
	}

	ListNode(int val, ListNode *next)
	{
		this->val = val;
		this->next = next;
	}
};

struct LinkedList
{
	int size;
	ListNode *head;
	ListNode *tail;

	LinkedList()
	{
		this->size = 0;
		this->head = NULL;
		this->tail = NULL;
	}

	void push(int val){
        ListNode * newNode = new ListNode(val);
        if (head == NULL){
            head = newNode;
        }
        else{
            ListNode *i = head;
            while(i -> next != NULL){
                i = i -> next;
            }
            i -> next = newNode;

        }
    }

    void search(int k){   
    int x = 2147483647 , cnt = 0, ans, y;
    ListNode* current = head; 
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

int main(){
    int n,c,num;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        list.push(a);
    }
    cin >> c;
    list.search(c);
    return 0;
}
