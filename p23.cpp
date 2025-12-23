//#include<iostream>
//using namespace std;
//
//	const int N =5 ;
//	int q[N];
//	int front =-1 ,rear=-1;
//	void enqueue(int data){
//		if(rear==N-1){
//			cout<<"Overflow";
//			return ;
//		}if(front==-1){
//			front = 0 ;
//		}
//		rear = rear+1;
//		q [rear] =data;
//	}
//	
//	void dequeue(){
//		if (front == -1 || front > rear){
//			cout<<"Underflow";
//			return ;
//		}else{
//			int d = q[front];
//			front = front +1;
//		}
//	}
//void display() {
//    if (front == -1) {
//        cout << "Queue is empty\n";
//        return;
//    }
//
//    for (int i = front; i <= rear; i++) {
//        cout << q[i] << " ";
//    }
//    cout << endl;
//}
//
//int main() {
//    enqueue(10);
//    enqueue(20);
//    enqueue(30);
//
//    display();
//
//    dequeue();
//    display();
//
//    return 0;
//}


#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next ;
};

class qe{
	Node * front ;
	Node *rear;
	public:
		qe(){
			front = rear = NULL;
		}


void enqueue(int dat){
	Node * newnode = new Node;
	if(front == NULL){
	
		newnode -> data = dat ;
		newnode -> next =NULL;
		front = rear = newnode;
		
	}
	else {
		newnode -> data = dat ;
		newnode -> next = NULL;
		rear ->next =newnode;
		rear = newnode;
		
	}
}

void dequeue(){
	Node * temp = front ;
	if (front == NULL){
		cout<<"Underflow";
		return;
	}
	front = front -> next;
	delete temp;
}
 void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    qe q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.display();

    return 0;
}
