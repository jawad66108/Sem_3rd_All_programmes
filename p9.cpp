#include<iostream>
using namespace std;

struct Node{
	int data;
	Node * next;
	public:
		Node(int val){
			data=val;
			next=NULL;
		}
};

class Clist{
	Node * head ;
	Node * tail ;
	public:
		Clist(){
			head=tail=NULL;
		}
		
	void tarverse(){
		Node * temp =head;
		do{
			cout<<temp->data<< " ";
			temp=temp->next;
		}while(temp!=head);
	}
	
	void search(int val){
		Node * newnode= head;
		int j=0;
		do{
			if(newnode->data== val){
			
			newnode=newnode->next;
			j++;}
		}while(newnode!=head);
		cout<<val<<" is present at pos "<<j;
	}
};

int main(){
	
}
