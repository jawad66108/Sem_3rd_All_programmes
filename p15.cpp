//Task 4 – (5 Marks)
//Singly Linked List
//Write a C++ program to:
//1. Create a singly linked list to store names.
//2. Implement insertion at:
//o The beginning of the list
//o The end of the list
//o A specific position in the list
//3. Traverse and display all names in the list.
#include<iostream>
using namespace std;
#include<string>
struct Node{
	string data;
	Node * next;
	public:
		Node(string val){
		data=val;
		next=NULL;
	}
};

class linked{
	Node * head;
	Node * tail;
	public:
		linked(){
			head=tail=NULL;
		}
		
	void ADDFRONT(string val){
		Node * newnode = new Node(val);
		if(head==NULL){
			head=tail=newnode;
		}
		else{
			newnode->next=head;
			head=newnode;
		}
	}
	
	void ADDLAST(string val){
		Node * newnode = new Node(val);
		if(head==NULL){
			head=tail=newnode;
		}
		tail->next=newnode;
		tail=newnode;
	}
	
	void ADDATPOS(string val,int pos){
		Node * newnode = new Node(val);
		if(pos<0){
			cout<<"List is empty\n";
			return;
		}else if(pos==1){
			ADDFRONT(val);
			return;
		}else{
			Node * temp =head;
			for(int i=1;i<pos-1;i++){
				temp=temp->next;
			}
			newnode->next=temp->next;
			temp->next=newnode;
		}
	}
	void display(){
		Node*temp=head;
		while(temp!=NULL){
			cout<<temp->data<<" -> ";
			temp=temp->next;
		}
		cout<<"NULL\n";
	}
};

int main(){
	linked l;

	l.ADDFRONT("jawad");
	l.ADDFRONT("ali");
	l.display();
	cout<<endl;
	l.ADDLAST("hamza");
	l.display();
	cout<<endl;
	l.ADDATPOS("hammad",3);
	l.display();
}

