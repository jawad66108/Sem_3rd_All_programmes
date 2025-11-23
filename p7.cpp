#include<iostream>
using namespace std;
struct Node{
	Node* next;
	int data;
	Node(int val){
		data=val;
		next=NULL;
	}
};

class linked{
	Node *head;
	Node *tail;
	public:
	linked(){
		head=tail=NULL;
	}
	
	void addF(int val){
		Node* newnode =new Node(val);
		if(head==NULL){
			head=tail=newnode;
			return;
		}else{
			newnode->next=head;
			head=newnode;
		}
	}
	
	void addE(int val){
		Node *newnode =new Node (val);
		if(head==NULL){
			head=tail=newnode;
			return;
		}else{
			tail->next=newnode;
			tail=newnode;
		}
	}
	
	void addM(int val,int pos){
		Node* newnode  = new Node(val);
		if(pos<0){
			cout<<"Invalid Position!!\n";
			return;
		}else if (pos==0){
			addF(val);
		}else{
			Node *temp=head;
			for(int m=0;m<pos-1;m++){
				temp=temp->next;
			}
			newnode->next= temp->next;
			temp->next=newnode;
		}
		
	}
	
	void delF(){
		Node *temp = head;
		head=head->next;
		delete temp;
	}
	
	void delE(){
		if(head==NULL){
			cout<<"List is empty\n";
			return;
		}else{
		Node *temp=head;
		while(temp->next!=tail){
			temp=temp->next;
		}
		
		delete tail;
		tail=temp;
		temp->next=NULL;
	}
}	
 
	void deleP(int val){
		if(head==NULL){
			cout<<"List is empty\n";
			return;
		}
		if(head->data==val){
			delF();
			return;
		}
		Node * temp = head;
		while(temp->next->data != val){
			temp=temp->next;
		}
		if(temp->next==NULL){
			return;
		}
		Node * delNode =temp->next;

		temp->next=delNode->next;
		delete delNode;
	}

	void search(int val){
		Node *temp=head;
		int i=0;
		while(temp!=NULL){
			if(temp->data==val){
				cout<<"Element "<<val<<" is present in LL at position "<<i<<endl;
			}
			temp=temp->next;
			i++;
		}
	}
	
	void display(){

		Node *temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" -> ";
			temp=temp->next;
		}
		
		cout<<"NULL\n";
	}
	
};

int main(){
	linked l;
	
	cout<<"=============Adding at the beginning===============\n";
	l.addF(24);
	l.addF(108);
	l.display();
	
	cout<<"\n===========Adding at the end=====================\n";
	l.addE(74);
	l.display();
	
	cout<<"\n===========Deleting from first===================\n";
	l.delF();
	l.display();
	
	cout<<"\n===========Deleting from the end=================\n";
	l.delE();
	l.display();
	
	cout<<"\n==========Adding at the specfice position========\n";
	l.addM(111,1);
	l.display();
	
	cout<<"\n==========Searching in LL ========================\n";
	int a;
	cout<<"Enter element you want to search: ";
	cin>>a;
	l.search(a);
	
	cout<<"\n==========Deleting from specfice position=========\n";
	l.deleP(111);
	l.display();
}
