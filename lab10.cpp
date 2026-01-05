#include<iostream>
using namespace std;

class Node
{
public:
	int priority;
	int data;
	Node *next;
};

Node *front = NULL;


void insert(int item, int priority)
{
	Node *temp;
	Node *newNode = new Node();
	newNode->data = item;
	newNode->priority = priority;

	if( front == NULL || priority < front->priority )
	
	{
		newNode->next = front;
		front = newNode;
	}
	else
	{
		temp = front;
		while( temp->next != NULL && temp->next->priority <= priority ){
            temp = temp->next;
		}

		newNode->next = temp->next;
		temp->next = newNode;
	}
}


void dequeue()
{
	Node *temp;
	if(front == NULL)
		cout<<"Queue Underflow"<<endl;
	else
	{
		temp = front;
		cout<<"Deleted item is : "<<temp->data;
		front = front->next;
		delete temp;
	}
}

void display()
{
	Node *temp;
	temp = front;
	if(front == NULL)
		cout<<"Queue is empty"<<endl;
	else
	{
		cout<<"Queue is : "<<endl;
		cout<<"Priority       Item"<<endl;
		while(temp != NULL)
		{
			cout<<temp->priority<<"->"<<temp->data<<" ";
			temp = temp->next;
		}
	}
	cout<<endl;
}

int main()
{
	int choice,item,priority;
	do
	{
		cout<<"1.Insert"<<endl;
		cout<<"2.Delete"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Quit"<<endl;
		cout<<"Enter your choice : "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Input the item value to be added in the queue : ";
				cin>>item;
				cout<<"Enter its priority : ";
				cin>>priority;
				insert(item,priority);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
			break;
				default :
				cout<<"Wrong choice"<<endl;
		}
	}while(choice!=4);

	return 0;
}
