#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(){
        this->val = 0;
        this->next = NULL;
    }
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
    ListNode(int val, ListNode *next){
        this->val = val;
        this->next = next;
    }
};

struct LinkedList{
    int size;
	ListNode *head;

	LinkedList()
	{
		this->size = 0;
		this->head = NULL;
	}

	void push(int val)
	{
		this->size++;
		ListNode *temp = new ListNode(val);
		if (this->head == NULL)
		{
			this->head = temp;
		}
		else
		{
			temp->next = this->head;
			this->head = temp;
		}
	}

    void findMaxSum() { 
    ListNode *cur = this->head; 
    int sum = 0, mx = -1000000000; 
    while (cur != NULL) { 
        sum += cur->val; 
        if (sum<cur->val){ 
            sum=cur->val;
            } 
        mx=max(sum, mx); 
        cur = cur->next;
        } 
    cout << mx;
    }
 
};

int main(){
    int n;
    cin >> n;
    LinkedList list;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        list.push(a);
        
    }
    list.findMaxSum();
}