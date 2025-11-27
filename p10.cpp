#include<iostream>
using namespace std;
int main(){
	int a;
	cout<<"Enter 1 for Linear\n2 for Binary\n=";
	cin>>a;
	
	switch(a){
		case 1:{
			
			int n=5, tag=8;
			int arr[n]={1,2,3,4,5};
			
			bool p=true;
			for(int j=0;j<n;j++){
				if(arr[j]==tag){
					cout<<tag<<" present at index: "<<j<<endl;
					p=false;
					break;
				}
			}
			if(p)
			cout<<tag<<" is not present in the array\n";
			break;
		}
		case 2:{
			int n=5, tag=3;
			int arr[n]={1,2,3,4,5};
			int st=0,end=n-1,mid=0;
			while(st<=end){
				mid=(st+end)/2;
				if(arr[mid]==tag){
					cout<<tag<<" present at index: "<<mid<<endl;
					return 0;
				}else if(tag<arr[mid]){
					end = mid-1;
				}else{
					st=mid+1;
				}
			}
			return -1;
		}
}
}
