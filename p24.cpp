#include<iostream>
using namespace std;

void heap(int arr[],int i ,int n){
	int largest = i;
	int left = (2*i)+1;
	int right = (2*i)+2;
	
	if(left<n && arr[left] > arr[largest]){
		largest = left;
	}
	if (right<n && arr[right] > arr[largest]){
		largest = right;
	}
	if(largest != i){
		swap(arr[i],arr[largest]);
		heap(arr,largest,n);
		
	}
}

int main() {
    int arr[] = {10, 20, 15, 30, 40};
    int n = 5;

    // Build Max Heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heap(arr, n, i);
    }

    cout << "Max Heap: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Delete root (max element)
    cout << "\nDeleted root: " << arr[0];

    arr[0] = arr[n - 1];
    n--;

    heap(arr, n, 0);

    cout << "\nHeap after deletion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}


