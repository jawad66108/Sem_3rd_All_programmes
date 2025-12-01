//Consider the array below representing stock quantities:
//int stock[10] = {5, 15, 22, 35, 40, 55, 65, 70, 85, 95};
//Write C++ code for the following:
//1. Implement linear search to find a specific quantity.
//2. Insert a new quantity at a specific position in the array.
//3. Delete an element from a given position in the array.
//4. Find and display the maximum and minimum quantity in the updated array.
//5. Display the total size of the array using sizeof().

#include<iostream>
using namespace std;

int main(){
	int n=10;
	int stock[10] = {5, 15, 22, 35, 40, 55, 65, 70, 85, 95};
	int tag;

	cout<<"Enter target: ";
	cin>>tag;
	for(int j=0;j<n;j++){
		if(stock[j]==tag){
			cout<<"Element found at index: "<<j<<endl;
			break;
		}
	}
	int pos, val;
	cout<<"Enter pos and stock: ";
	cin>>pos>>val;
	for(int i=n;i>pos;i--){
		stock[i]=stock[i-1];
	}
	
	stock[pos]=val;
	n++;
	
	for(int i=0;i<n;i++){
		cout<<stock[i]<<" ";
	}
	cout<<endl;
	
	int po1;
	cout<<"Enter position you want to delete: ";
	cin>>po1;
	for(int i=po1;i<n;i++){
		stock[i]=stock[i+1];	
	}
	n--;
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<stock[i]<<" ";
	}
	
	cout<<endl;
	int min=stock[0];
	int max=stock[0];
	
	for(int i=0;i<n;i++){
		if(max>stock[i]){
			max=stock[i];
		}else if(min<stock[i]){
			min=stock[i];
		}
	}
	cout<<"\nMax: "<<max<<" Min: "<<min;
	
	int len=sizeof(stock)/sizeof(stock[0]);
	cout<<"Total size of array: "<<len;

}

