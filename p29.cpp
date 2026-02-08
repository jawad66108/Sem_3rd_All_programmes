//#include<iostream>
//using namespace std;
//void heap(int arr[], int n , int i){
//	int largest = i;
//	int left = 2*i+1;
//	int right = 2*i+2;
//	
//	if(left<n &&arr[left]>arr[largest]){
//		largest = left;
//	}
//	if(right<n && arr[right]>arr[largest]){
//		largest = right;
//	}
//	
//	if(largest!=i){
//		swap(arr[i],arr[largest]);
//		heap(arr,n,largest);
//		
//	}
//}
//
//int main(){
//	int n=5;
//	int arr[n]={1,2,3,4,5};
//	
//	for(int i=n/2-1; i>=0 ; i--){
//		heap(arr,n,i);
//	}
//	cout<<"\nMax heap: ";
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//	}
//	return 0;
//}

//#include<iostream>
//using namespace std;
//const int n=5;
//int queue[n];
//int front = -1,rear = -1;
//
//void enqueue(int val){
//	if(rear == n-1){
//		cout<<"FULL";
//		return;
//	}else{
//		if(front == -1) front = 0;
//		rear++;
//		queue[rear] = val;
//	}
//}
//
//void dequeue(){
//	if(front==-1 || front>rear){
//
//		return;
//		
//	}else{
//		cout<<"\nDeleted element: "<<queue[front];
//		front++;
//	}
//}
//
//void display(){
//	cout << "\nQueue elements: ";
//    for (int i = front; i <= rear; i++) {
//        cout << queue[i] << " ";
//
//}
//}
//
//int main(){
//enqueue(10);
//enqueue(20);
//enqueue(30);
//display();
//dequeue();
//dequeue();
//display();
//}

#include <iostream>
using namespace std;
#define SIZE 5

int cqueue[SIZE];
int front = -1, rear = -1;

void insertCQ(int val) {
    if ((rear + 1) % SIZE == front) {
        cout << "Queue Full\n";
        return;
    }
    if (front == -1) front = 0; 
    rear = (rear + 1) % SIZE;
    cqueue[rear] = val;
    cout << "Inserted " << val << endl;
}

void deleteCQ() {
    if (front == -1) {
        cout << "Queue Empty\n";
        return;
    }
    cout << "Deleted: " << cqueue[front] << endl;
    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % SIZE;
    }
}

void displayCQ() {
    if (front == -1) {
        cout << "Queue Empty\n";
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (i != rear) {
        cout << cqueue[i] << " ";  
        i = (i + 1) % SIZE;
    }
    cout << cqueue[i] << "\n";     
}

int main() {
    insertCQ(10);
    insertCQ(20);
    insertCQ(30);
    displayCQ();
    deleteCQ();
    displayCQ();
    insertCQ(40);
    insertCQ(50);
    displayCQ();
    return 0;
}


//void insert(int item, int priority)
//{
//	Node *temp;
//	Node *newNode = new Node();
//	newNode->data = item;
//	newNode->priority = priority;
//
//	if( front == NULL || priority < front->priority )
//	
//	{
//		newNode->next = front;
//		front = newNode;
//	}
//	else
//	{
//		temp = front;
//		while( temp->next != NULL && temp->next->priority <= priority ){
//            temp = temp->next;
//		}
//
//		newNode->next = temp->next;
//		temp->next = newNode;
//	}
//}


