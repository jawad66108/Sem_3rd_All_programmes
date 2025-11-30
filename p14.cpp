//#include<iostream>
//using namespace std;
//struct Node{
//	int data;
//	Node *next;
//	public:
//		Node(int val){
//			data=val;
//			next=NULL;
//		}
//};
//
//class linkedlist{
//	Node *head;
//	Node* tail;
//	public:
//		linkedlist(){
//			head=tail=NULL;
//		}
//	
//	void ADDFRONT(int val){
//		Node * newnode = new Node(val);
//		if(head==NULL){
//			head=tail=newnode;
//		}
//		newnode->next=head;
//		head=newnode;
//	}
//	
//	void ADDLAST(int val){
//		Node * newnode = new Node(val);
//		if(head==NULL){
//			head=tail=newnode;
//		}
//		tail->next=newnode;
//		tail=newnode;		
//	}
//	
//	void ADDATPOS(int val,int pos){
//		Node * newnode = new Node(val);
//		Node * temp=head;
//		
//		for(int i=0;i<pos-1;i++){
//			temp=temp->next;
//		}
//		newnode->next=temp->next;
//		temp->next=newnode;
//		
//	}
//	
//	void DELFIRST(){
//		Node * temp = head;
//		head=head->next;
//		delete temp;
//	}
//	
//	void DELLAST(){
//		Node * temp = head;
//		while(temp->next!=tail){
//			temp = temp -> next;
//		}
//		delete tail;
//		tail=temp;
//		tail->next=NULL;
//	}
//	
//	void DELATPOS(int val){
//		Node * temp = head;
//		while(temp->next->data != val){
//			temp = temp->next;
//		}
//		Node *newnode;
//		newnode= temp->next;
//		temp->next= newnode->next;
//		delete newnode;
//	}
//	
//	void search(int val){
//		Node * temp = head;
//		int j=1;
//		while(temp != NULL){
//			if(temp->data == val){
//				cout<<"element found at index: "<<j;
//				break;
//			}
//			temp=temp->next;
//			j++;
//		}
//	}
//	
//	void display(){
//		Node * temp=head;
//		while(temp!=NULL){
//			cout<<temp->data<<" ";
//			temp=temp->next;
//		}
//	}
//	
//};
//
//
//int main(){
//	linkedlist l;
//	l.ADDFRONT(24);
//	l.ADDLAST(44);
//	l.ADDLAST(111);
//	l.ADDLAST(46);
//	l.display();
//	cout<<endl;
//	l.ADDATPOS(108,1);
//	l.display();
//	cout<<endl;
//	l.DELFIRST();
//	l.display();
//	cout<<endl;
//	l.DELLAST();
//	l.display();
//	cout<<endl;
//	l.DELATPOS(44);
//	l.display();
//	cout<<endl;
//	l.search(111);
//}

//#include <iostream>
//#include <string>
//#include<cstring>
//using namespace std;
//
//struct Address {
//    char city[50];
//    string street;
//};
//
//struct Student {
//    int rollNo;
//    string name;
//    Address addr;   
//    int marks;
//};
//
//void linearSearch(Student students[]){
//	char a [20];
//	cout<<"Enter city you want to search: ";
//	cin>>a;
//	for(int i=0;i<5;i++){
//		if(strcmp(students[i].addr.city , a) == 0){
//			cout<<students[i].rollNo<<" "<<students[i].name<<" "<<students[i].marks<<" "<<students[i].addr.city<<" "<<students[i].addr.street;
//		}
//	}
//}
//
//void bubble(Student students[]){
//	for(int i=0;i<5-1;i++){
//		for(int j=0;j<5-i-1;j++){
//			if(students[j].marks< students[j+1].marks){
//				swap(students[j],students[j+1]);
//			}
//		}
//	}
//	
//	for (int i = 0; i < 5; i++) {
//		cout<<endl<<"\n";
//        cout << students[i].rollNo << " "
//             << students[i].name << " "
//             << students[i].addr.city << " "
//             << students[i].addr.street << " "
//             << students[i].marks << endl;
//    }
//}
//int main() {
//    Student students[5] = {
//        {101, "Ali", {"Lahore", "Street 1"}, 85},
//        {102, "Sara", {"Karachi", "Street 2"}, 90},
//        {103, "Ahmed", {"Islamabad", "Street 3"}, 75},
//        {104, "Fatima", {"Multan", "Street 4"}, 95},
//        {105, "Bilal", {"Peshawar", "Street 5"}, 80}
//    };
//
//    cout << "Initial Student Data:\n";
//    for (int i = 0; i < 5; i++) {
//        cout << students[i].rollNo << " "
//             << students[i].name << " "
//             << students[i].addr.city << " "
//             << students[i].addr.street << " "
//             << students[i].marks << endl;
//    }
//    
//    linearSearch(students);
//    bubble(students);
//}

//for(int i=0;i<r1;i++){
//	for(int j=0;j<c2;j++){
//		for(int k=0;k<c1;k++){
//			c[i][j]*=a[i][k]+b[k][j];
//		}
//	}
//}

//#include<iostream>
//using namespace std;
//int main(){
//	int n=5;
//	int arr[n]={24,56,77,45,34};
//	int pos,val;
//	cout<<"Enter pos and val: ";
//	cin>>pos>>val;
//	for(int j=n;j>pos;j--){
//		arr[j]=arr[j-1];
//	}
//	arr[pos]=val;
//	n++;
//	
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//	}
//	cout<<endl;
//	int pos1;
//	cout<<"Enter pos to delete: ";
//	cin>>pos1;
//	for(int j=pos1-1;j<n-1;j++){
//		arr[j]=arr[j+1];
//	}
//	n--;
//	
//	cout<<endl;
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//	}
//}

//#include<iostream>
//using namespace std;
//int main(){
//	int n=12,tag=42;
//	int arr[n] = {3, 7, 12, 18, 25, 31, 42, 56, 63, 78, 89, 95};
//	int st=0 ,end=n-1 ,mid=0;
//	while(st<=end){
//		mid =(st+end)/2;
//		if(tag==arr[mid]){
//			cout<<"Element present at: "<< mid;
//			break;
//		}else if (tag>arr[mid]){
//			st=mid+1;
//		}else{
//			end=mid-1;
//		}
//	}
//	
//}


