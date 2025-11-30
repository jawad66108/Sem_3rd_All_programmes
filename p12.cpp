////LAB Objectives
////To understand the concept and structure of a Singly Linked List
////To implement node insertion at:The beginning of the list
////The end of the list
////A specific user-defined position
////To perform traversal for displaying all linked list elements.
////To implement searching for a specific node.
////To perform deletion of a node from the list.
////To implement updating of a node’s value.
////To implement sorting of nodes within the list
//
//#include<iostream>
//using namespace std;
//
//struct Node{
//	int data;
//	Node * next;
//	public:	
//		Node(int val){
//			data=val;
//			next=NULL;
//		}
//};
//
//class Linked{
//	Node * head;
//	Node * tail;
//	public:
//		Linked(){
//			head=tail=NULL;
//		}
//	
//	void ADDFORNT(int val){
//		Node* newnode = new Node(val);
//		if(head==NULL){
//			head=tail=newnode;
//		}else{
//			newnode->next=head;
//			head=newnode;
//		}
//	}
//	
//	void ADDLAST(int val){
//		Node *newnode =new Node(val);
//		if(head==NULL){
//			head=tail=newnode;
//		}else{
//			tail->next =newnode;
//			tail=newnode;
//		}
//	}
//	
//	void ADDATPOS(int val,int pos){
//		Node*newnode = new Node(val);
//		if(pos<0){
//			cout<<"Invaild position";
//			return ; 
//		}else if(pos==1){
//			ADDFORNT(val);
//			return;
//		}else{
//			Node * temp=head;
//			for(int j=0;j<pos-1;j++){
//				temp=temp->next;
//			}
//			newnode->next=temp->next;
//			temp->next=newnode;
//		}
//	}
//	
//	void DELFRONT(){
//		Node *temp =head;
//		head=head->next;
//		delete temp;
//	}
//	
//	void DELLAST(){
//		Node* temp =head;
//		while(temp->next!=tail){
//			temp=temp->next;
//		}
//		tail=temp;
//		temp->next=NULL;
//		delete tail;
//	}
//	
//	void DELATPOS(int val){
//		Node * temp=head;
//		Node *newnode;
//		while(temp->next->data !=val){
//			temp=temp->next;
//		}
//		newnode=temp->next;
//		temp->next=newnode->next;
//		delete newnode;
//	}
//	
//	void search(int val){
//		Node * temp=head;
//		int j;
//		bool p=true;
//		while(temp!=NULL){
//			if(temp->data!=val){
//
//				p=false;
//				break;
//			}
//			temp=temp->next;
//			j+=1;
//		}
//		if(p=true){
//			cout<<val<<" present at index: "<<j<<endl;
//		}else{
//			cout<<val<<" is not in the list\n";
//		}
//	}
//	
//	void sortList() {
//		if (head == NULL) {
//			cout << "List is empty\n";
//			return;
//		}
//		for (Node* i = head; i != NULL; i = i->next) {
//			for (Node* j = i->next; j != NULL; j = j->next) {
//				if (i->data > j->data) {
//					swap(i->data,j->data);
//					
//				}
//			}
//		}
//		cout << "Linked List sorted in ascending order\n";
//	}
//
//	
//	void display(){
//		Node *temp = head;
//		int count=0;
//		while(temp!=NULL){
//			cout<<temp->data<<" -> ";
//			temp=temp->next;
//			count++;
//		}
//		cout<<" NULL\nTotal count :"<<count<<endl;
//		
//	}
//};
//int main(){
//	Linked l;
//	cout<<"==============Adding at first===============\n";
//	l.ADDFORNT(24);
//	l.ADDFORNT(108);
//	l.ADDFORNT(99);
//	l.ADDFORNT(56);
//	l.ADDFORNT(74);
//
//	l.display();
//	
//	cout<<"\n==============Adding in yhe last=============\n";
//	l.ADDLAST(52);
//	l.ADDLAST(46);
//	l.display();
//	
//	cout<<"\n==============Adding at specfice position=============\n";
//	l.ADDATPOS(13,3);
//	l.display();
//	
//	cout<<"\n=========================Deleting from first============\n";
//	l.DELFRONT();
//	l.display();
//	
//	cout<<"\n=========================Deleting from last==============\n";
//	l.DELLAST();
//	l.display();
//	
//	cout<<"\n==========================Delteing any data=================\n";
//	l.DELATPOS(99);
//	l.display();
//	
//	cout<<"\n========================Aranging the list======================\n";
//	l.sortList();
//	l.display();
//	
//	cout<<"\n=======================Seraching===============================\n";
//	l.search(108);
//	l.display();
//}

//#include<iostream>
//using namespace std;
//
//struct roll{
//	int rollno;
//	int session;
//	char dep[20];
//};
//struct st {
//	char name[20];
//	roll n ;
//};
//
//int main(){
//	st s[2];
//	cout<<"Enter name: ";
//	cin>>s[0].name;
//	cout<<"Enter Roll no: ";
//	cin>>s[0].n.rollno;
//	cout<<"Enter dep: ";
//	cin>>s[0].n.dep;
//	cout<<"Enter Session: ";
//	cin>>s[0].n.session;
//	
//	
//	cout<<"Enter name: ";
//	cin>>s[1].name;
//	cout<<"Enter Roll no: ";
//	cin>>s[1].n.rollno;
//	cout<<"Enter dep: ";
//	cin>>s[1].n.dep;
//	cout<<"Enter Session: ";
//	cin>>s[1].n.session;
//	
//	for(int i=0;i<2;i++){
//		cout<<s[i].name<<" "<<s[i].n.dep<<" "<<s[i].n.rollno<<" "<<s[i].n.session<<endl;
//	}
//	
//}




