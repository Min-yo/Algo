#include<iostream>
using namespace std;

struct ListNode
{
	string name;
	ListNode *next;

	ListNode()
	{
		this->name = "";
		this->next = NULL; 
	}

	ListNode(string name)
	{
		this->name = name;
		this->next = NULL;
	}

	ListNode(string name, ListNode *next)
	{
		this->name = name;
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

    	void pushback(string name)
	{
		this->size++;
		ListNode *temp = new ListNode(name);
		if (this->head == NULL)
		{
			this->head = temp;
			this->tail = temp;
		}
		else
		{
			this->tail->next = temp;
			this->tail = temp;
		}
	}

    void reverse()
    {
        // Initialize current, previous and next pointers
        ListNode* current = this -> head;
        ListNode *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }


	void printLL() {
        cout<< "All in all: "<< this->size << endl;
        cout<< "Students:"<< endl;
		ListNode *cur = this->head;
        while (cur != NULL) {
            cout << cur->name << endl;
            cur = cur->next;
        }
	}
};

int main()
{
    int n;
    cin >> n;
    string name , copy;
    copy = "";
    LinkedList list;
    while(n--){
        cin >> name;
        if(name != copy){
            list.pushback(name);
            copy = name;
        }
        else{
            continue;
        }
    }
    list.reverse();
    list.printLL();

	return 0;
}