#include<iostream>
using namespace std;

const int N =4;
int front = -1 , rear =-1;
int queue[N];

void enqueue(int val){
	if((rear+1)%N == front){
		 cout<<"Queue is full";	
		 return  ;
	}
	if(front == -1 )
		front = rear = 0 ;
	else {
		rear = (rear +1) % N;
		
	}
	queue[rear] = val;
}

void dequeue(){
	if(front == -1){
		cout<< "Queue is empty";
		return ;
	}
	else if(front == rear ){
		front = rear = -1 ;
	}
	else{
		front = (front + 1 ) % N;
	}
}

void dis(){
	  if (front == -1) {
        cout << "Queue Empty\n";
        return;
    }

    int i = front;
    while (i != rear) {
        cout << queue[i] << " ";
        i = (i + 1) % N;
    }
    cout << queue[i] << endl;
}

int main(){
	enqueue(520);
	enqueue(55);
	enqueue(5);
	enqueue(50);

	dequeue();
	
	dis();
}
