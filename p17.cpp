#include<iostream>
using namespace std;


struct Node{
	public:
		Node * next;
		int data;
	
};

class ll{
	Node * front ;
	Node * rear ;
	public:
		ll(){
			front =rear = NULL;
		}
		
	void enqueue(int dat){
			Node * newnode = new Node;
			newode ->data = dat;
			newnode -> next = NULL;
		if (front == NULL){
		
			front = rear = NULL;
		}
		else {
			rear ->next = newnode;
			newnode -> next = NULL;
			rear = newnode; 
		}
	}
	
	void dequeue (){
		 if (front == NULL) {
            cout << "Underflow\n";
            return;
        }
        
		Node  * temp = front ;
		front = front ->next;
		delete temp;
	}
};

int main(){
//	const int N=8;
//	int queue[N]= {20 , 30 ,60 ,80 ,50};
//	int rear = -1, front =0;
	
//	int a;
//	cout<<"Enter elenment you want to add: ";
//	cin>>a;
//	
//	if (rear == N-1){
//		cout<<"Overflow";
//		return 0 ;
//	}
//	if (front >rear){
//		cout<<"Underflow";
//		return 0;
//	}
//	else{
//		front ++;
//		
//	}
//	else{
//		rear = rear +1;
//		queue [rear] = a;
//		
//	}
//	for(int i=front ; i<=rear ; i++){
//		cout<<queue[i]<<" ";
//	}
}
