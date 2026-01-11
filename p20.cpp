//#include<iostream>
//using namespace std;
//
//	const int N=8;
//	int queue[N];
//	int data=56;
//	int front = -1 , rear =-1;
//	
//	void enqueue(int data){
//		if((rear + 1) %N == front){
//			cout<<"Overflow";
//		}
//		else if (front ==-1){
//			front=rear=0;
//		}else{
//			rear = (rear + 1)%N ;
//		}
//		queue[N]=data;
//	}
//	
//	void dequeue(){
//		if(front == -1 ){
//			cout<<"Underflow";
//		}
//		else if (front == rear){
//			front = rear =-1;
//		}else{
//			front = (front+1)%N ;
//		}
//	}
//	
//int main(){
//	
//}

#onclude<iosatream>
using namespace std;

struct Node{
	int data;
	Node * next;
	Node *pri;
};

class queue{
	Node* front ;
	
	public:
		queue(){
			front == NULL;	
		}
		
	void enqueue()
};
