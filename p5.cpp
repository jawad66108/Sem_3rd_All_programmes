//#include <iostream>
//using namespace std;
//
//// Define a node structure
//struct Node {
//    int data;
//    Node* next;
//};
//
//int main() {
//    // Creating nodes
//    Node* head = new Node();
//    Node* second = new Node();
//    Node* third = new Node();
//
//    // Assign data and link nodes
//    head->data = 10;
//    head->next = second;
//
//    second->data = 20;
//    second->next = third;
//
//    third->data = 30;
//    third->next = NULL;
//
//    // You will write your traversal code below this line ??
//    Node* ptr = head;
//    while(ptr!=NULL){
//    	cout<<ptr->data<<" ";
//    	ptr=ptr->next;
//	}
//
//    return 0;
//}


//#include<iostream>
//using namespace std;
//
//struct Node{
//	int data;
//	Node *next;
//};
//
//int main(){
//	Node* head = new Node();
//	Node* second =new Node();
//	Node* tail =new Node();
//	
//	head->data = 30;
//	head->next=second;
//	
//	second->data = 35;
//	second->next=tail;
//	
//	tail->data = 40;
//	tail->next=NULL;
//	
//	Node* temp = head;
//	while(temp!=NULL){
//		cout<<temp->data<<" -> ";
//		temp=temp->next;
//	}
//	cout<<"NULL";
//	
//	temp= head;
//	int n;
//	cout<<"\nEnter element you want to find: ";
//	cin>>n;
//	int i=0;
//	while(temp!=NULL){
//		if(temp->data==n){
//			cout<<"\nElement found at index: "<<i;
//			break;
//		}
//		temp=temp->next;
//		i++;
//		if(temp==NULL){
//			cout<<"Element is not present in it";
//		}
//	}
//	
//	Node* newnode= new Node();
//	newnode->data=23;
//	newnode->next=head;
//	head=newnode;
//	
//	cout<<"\n==========Updated linked list===============\n";
//	temp = head;
//	while(temp!=NULL){
//		cout<<temp->data<<" -> ";
//		temp=temp->next;
//	}
//	cout<<"NULL";
//	
//	
//}
//


#include<iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
};
int main(){
	Node *head=new Node();
	Node *second=new Node();
	Node *tail=new Node();
	
	head->data=10;
	head->next=second;
	
	second->data=20;
	second->next=tail;
	
	tail->data=30;
	tail->next=NULL;
	
	Node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
	
	Node *newnode=new Node();
	newnode->data=108;
	newnode->next=head;
	head=newnode;
	
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"NULL"<<endl;
	
//	int n,i=0;
//	cout<<"\nEnter element you want to search: ";
//	cin>>n;
//	temp=head;
//	while(temp!=NULL){
//		if(temp->data==n){
//			cout<<"\nElemnt present in list at index: "<<i<<endl;
//			break;
//		}
//		temp=temp->next;
//		i=i+1;
//	}
	
	Node *neode=head;
	while(neode!=NULL){
	neode=neode->next;
	}
	
	
	temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<"NULL";
}
