//#include<iostream>
//using namespace std;
//
//void heapify(int arr[] , int n ,int i){
//	int largest = i;
//	int left = 2*i + 1;
//	int right = 2*i + 2;
//	
//	if(left<n && arr[left]>arr[largest]){
//		largest = left;
//	}
//	else if (right<n && arr[right]>arr[largest]){
//		largest = right;
//	}
//	if(largest!=i){
//		swap (arr[i],arr[largest]);
//		heapify(arr,n,largest);
//	}
//}
//
//int main(){
//	int arr[] = {10, 20, 15, 30, 40};
//    int n = 5;
//
//    // Build heap
//    for (int i = n / 2 - 1; i >= 0; i--)
//        heapify(arr, n, i);
//
//    cout << "Heapified array: ";
//    for (int i = 0; i < n; i++)
//        cout << arr[i] << " ";
//}

#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

int main() {
    int n;
    cout << "Enter number of tasks: ";
    cin >> n;

    int arr[100];
    cout << "Enter task priorities:\n";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    buildMaxHeap(arr, n);

    cout << "Task Execution Order (High Priority First): ";

    for(int i = n - 1; i >= 0; i--) {
        cout << arr[0] << " ";
        swap(arr[0], arr[i]);     
        heapify(arr, i, 0);        
    }

    return 0;
}

