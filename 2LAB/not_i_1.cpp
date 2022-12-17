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

    bool isEmpty()
	{
		return size == 0;
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
        cout<<"ok"<<endl;
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
        cout<<"ok"<<endl;
	}

    void pop_front()
	{
		if (this->isEmpty())
		{
			cout<<"error"<<endl;
		}
		else
		{
			ListNode *toDel = head;
			head = head->next;
            cout<< toDel->word << endl;
			delete (toDel);
			size--;
		}
	}

       void pop_front1()
	{
		if (this->isEmpty())
		{
			cout<<"ok"<<endl;
		}
		else
		{
			ListNode *toDel = head;
			head = head->next;
            //cout<< toDel->word << endl;
			delete (toDel);
			size--;
		}
	}

    void pop_back(){

    if (head == NULL)
        cout<<"error"<<endl;
 
    if (head->next == NULL) {
        cout<< head->word << endl;
        delete head;
    }
 
    ListNode* second_last = head;

    while (second_last->next->next != NULL){
        second_last = second_last->next;
    }

    cout<<second_last->next->word<<endl;

    delete (second_last->next);
    second_last->next = NULL;
}

    void front(){
        if (head == NULL){
            cout<<"error"<<endl;
        }
        else{
            cout<<head->word<<endl;
        }
    }

    void back(){
        if (head == NULL){
            cout<<"error"<<endl;
        }
        else{
            cout<<tail->word<<endl;
        }
    }

    void clear(){
        while(!this->isEmpty()){
           
           ListNode *toDel = head;
			head = head->next;
			delete (toDel);
			size--;
		}
        cout<< "ok" << endl;
    }

};

int main(){
    string command;
    LinkedList list;
    while(true){
        cin>>command;
        if(command == "add_front"){
            string word;
            cin>>word;
            list.pushfront(word);
        }
        else if(command == "add_back"){
            string word;
            cin>>word;
            list.pushback(word);
        }
        else if(command == "erase_front"){
            list.pop_front();
        }
        else if(command == "erase_back"){
            list.pop_back();
        }
        else if(command == "front"){
            list.front();
        }
        else if(command == "back"){
            list.back();
        }
        else if(command == "clear"){
            list.clear();
        }
        else if(command == "exit"){
            cout<< "goodbye" << endl;
            break;
        }
    }
    
}
