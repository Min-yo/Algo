#include <iostream>
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

	void pushfront(int val)
	{
		this->size++;
		ListNode *temp = new ListNode(val);
		if (this->head == NULL)
		{
			this->head = temp;
			this->tail = temp;
		}
		else
		{
			temp->next = this->head;
			this->head = temp;
		}
	}

    	void pushback(int val)
	{
		this->size++;
		ListNode *temp = new ListNode(val);
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

	void addAtIndex(int index, int val)
	{
		if (index > this->size)
		{
			return;
		}
		else if (index == 0)
		{
			this->pushfront(val);
		}
		else if (index == this->size)
		{
			this->pushback(val);
		}
		else
		{
            this->size++;
			ListNode *temp = new ListNode(val);
			ListNode *cur = this->head;
			for (int i = 1; i < index; i++)
			{
				cur = cur->next;
			}
			temp->next = cur->next;
			cur->next = temp;
		}
	}

	void printLL() {
		ListNode *cur = this->head;
		while (cur != NULL) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};

int main()
{
	int n;
    cin >> n;
    LinkedList list;
    while (n--){
        int val;
        cin >> val;
        list.pushback(val);
    }
    int c, index;
    cin >> c;
    cin >> index;
    list.addAtIndex(index, c);
    list.printLL();

	return 0;
}