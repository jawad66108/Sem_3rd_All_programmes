#include<iostream>
using namespace std;
struct Node{
	Node * next;
	int data;
	int pri;
};

class PQueue{
	Node * front;
	
	public:
		PQueue(){
	 		front = NULL;
	 	}
	 		
	void enqueue(int val , int pri){
		Node * temp = front;
		Node * newnode = new Node();
					
			newnode->data = val;
			newnode->pri = pri;
			
			newnode->next = NULL;
		
		if(front == NULL || front->pri > pri){
			newnode -> next = front;
			front = newnode;
		}
		else{
			while(temp->next !=NULL && temp->next->pri>=pri){
				temp = temp->next;
				
			}
			newnode->next = temp -> next;
			temp -> next = newnode;
		}
	}
	
	void dis(){
	Node *temp = front ;
	if(front == NULL)
		cout<<"Queue is empty"<<endl;
	else
	{
		cout<<"Queue is : "<<endl;
		cout<<"Priority       Item"<<endl;
		while(temp != NULL)
		{
			cout<<temp->pri<<"->"<<temp->data<<" ";
			temp = temp->next;
		}
	}
	cout<<endl;

	}
};

int main(){
	PQueue p;
	
	p.enqueue(20,2);
	p.enqueue(40,22);
	p.enqueue(68,1);
	p.enqueue(2,4);
	
	p.dis();

}
