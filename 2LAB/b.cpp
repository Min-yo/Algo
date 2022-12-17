#include<iostream>
using namespace std;

struct ListNode
{
	string word;
	ListNode *next;

	ListNode()
	{
		this->word = "";
		this->next = NULL;
	}

	ListNode(string word)
	{
		this->word = word;
		this->next = NULL;
	}

	ListNode(string word, ListNode *next)
	{
		this->word = word;
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

	void pushfront(string word)
	{
		this->size++;
		ListNode *temp = new ListNode(word);
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

    
	void pushback(string word)
	{
		this->size++;
		ListNode *temp = new ListNode(word);
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

    void change(int index){
        ListNode *temp = this->head;
        for(int i = 0; i < index; i++){
            this->pushback(temp->word);
            temp = temp->next;
        }
        this->head = temp;
    }

    void print()
    {
        ListNode *cur = this->head;
        while (cur != NULL)
        {
            cout << cur->word << " ";
            cur = cur->next;
        }
        cout << endl;
    }

};

int main(){
    int n, c;
    cin >> n >> c;
    LinkedList list;
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        list.pushback(word);
    }
    list.change(c);

    list.print();
}

