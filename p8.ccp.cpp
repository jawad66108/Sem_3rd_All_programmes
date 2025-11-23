#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int val){
		data=val;
		next=NULL;
	}
};

class linkedlist{
	Node* head;
	Node *tail;
	public:
	linkedlist(){
		head=tail=NULL;
	}
	
	void addf(int val){
		Node *newnode =new Node(val);
		if(head==NULL){
			head=tail=newnode;
		}else{
			newnode->next=head;
			head=newnode;
		}
	}
	
	void addl(int val){
		Node *newnode =new Node(val);
		if(head==NULL){
			head=tail=newnode;
		}else{

			tail->next=newnode;
			tail=newnode;
		}
	}
	
	void addm(int val,int pos){
		if(pos<0){
			cout<<"\nTnvild position\n";
			return;
		}if(pos==0){
			addf(val);
		}else{
			Node *newnode =new Node(val);
			Node*temp=head;
			for(int i=0;i<pos-1;i++){
				temp=temp->next;
			}
			newnode->next=temp->next;
			temp->next=newnode;
		}
	}
	
	void delf(){
		if(head==NULL){
			cout<<"List is empty!!\n";
			return;
		}else{
		Node *temp =head;
		head=head->next;
		delete(temp);	
	}
}
	
	void dell(){
		if(head==NULL){
			cout<<"List is empty!!\n";
			return;
		}else{
			Node *temp=head;
			while(temp->next!=tail){
				temp=temp->next;
			}
			delete tail;
			temp->next=NULL;
			tail=temp;
			
		}
	}
	
	void delm(int val){
		if(head==NULL){
			cout<<"List is empty\n";
			return;
		}
		if(head->data==val){
			delf();
			return;
		}
		Node *temp =head;
		while(temp->next->data != val){
			temp=temp->next;
		}
		Node *del=temp->next;
		temp->next=del->next;
		delete del;
		
	}
	
	void display(){
		Node * temp =head;
		while(temp!=NULL){
			cout<<temp->data<<" ->";
			temp=temp->next;
		}
		cout<<"NULL\n";
	}
};

int main(){
	linkedlist l;
	cout<<"---------addding in the front--------------\n";
	l.addf(24);
	l.addf(108);
	l.addf(74);
	l.display();
	cout<<"\n----------adding at the end-----------------\n";
	l.addl(23);
	l.addl(18);
	l.display();
	cout<<"\n-----------Deleting from first-----------------\n";
	l.delf();
	l.display();
	cout<<"\n-----------Deleting from last-------------------\n";
	l.dell();
	l.display();
	cout<<"\n-----------adding at specfice position-----------\n";
	l.addm(56,1);
	l.display();
	cout<<"\n------------deleting with data------------------\n";
	l.delm(56);
	l.display();
}
