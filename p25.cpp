#include<iostream>
using namespace std;
//====================bubble sort=================
void bubblesort(int arr[], int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1-i;j++){
			if(arr[j]<arr[j+1]){
				swap(arr[j],arr[j+1]);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}

void insertion(int arr[],int n){
	for(int i=1;i<n;i++){
		int curr = arr[i];
		int pre = i-1;
		
		while(pre>=0 && arr[pre]>curr){
			arr[pre+1]=arr[pre];
			pre--;
		}
		arr[pre+1] = curr;
	}
	
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
int main(){
	int n=5;
	int arr[n]={23,34,25,62,66};
	
	bubblesort(arr,n);
	cout<<"\n";
	insertion(arr,n);
}
