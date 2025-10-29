//#include<iostream>
//using namespace std;
//int main(){
//	int num[9]={1,2,3,4,5,6,7,8,9};
//	int n=9;
//	int pos =1;
//	int val =8;
//	for( int i=n;i>pos;i--){
//		num[i] = num[i-1];
//	}
//	num[pos]=val;
//	n++;
//	
//	for(int i=0;i<n;i++){
//		cout<<num[i]<<" ";
//	}
//}


//#include<iostream>
//using namespace std;
//int main(){
//	int n=5;
//	int num[n]={1,2,3,4,5};
//	int pos=3;
//	
//	for(int i=pos;i<n-1;i++){
//		num[i]=num[i+1];
//	}
//	n--;
//	for(int i=0;i<n;i++){
//		cout<<num[i]<<" ";
//	}
//}

//#include<iostream>
//using namespace std;
//int main(){
//	
//	int n=5;
//	int num[n]={23,24,2,5,26};
//	int pos=3,val=108;
//	
//	for( int i=n;i>pos;i--){
//		num[i]=num[i-1];
//		
//	}
//	num[pos]=val;
//	n++;
//	cout<<"============= ADDING ========================\n";
//	for (int i=0;i<n;i++){
//		cout<<num[i]<<" ";
//	}
//	
//	int po=2;
//	
//	for(int i=po;i<n-1;i++){
//		num[i]= num[i+1];
//	}
//	n--;
//	cout<<"\n============= REMOVING ========================\n";
//	for (int i=0;i<n;i++){
//		cout<<num[i]<<" ";
//	}
//
//}




#include<iostream>
using namespace std;
int main(){
	int n=5,tag=66;
	int num[n]={23,25,66,88,93};
	int st=0,end=n-1,mid=0;
	while(st<=end){
		mid= st+end/2;
		if(tag==num[mid]){
			cout<<"The target is at index: "<<mid;
			break;
		}
		else if(tag<num[mid]){
			end=mid-1;
		}
		else{
			st=mid+1;
		}
	}
}


//#include<iostream>
//using namespace std;
// int main(){
// 	int n=5;
// 	int arr[]={12,24,52,44,66};
// 	int pos =4,val=108;
// 	
// 	cout<<"==========Current array=====================\n";
// 	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//	}
// 	for(int i=n;i>pos;i--){
// 		arr[i]=arr[i-1];
//	}
//	arr[pos]=val;
//	n++;
//	cout<<"\n=======================After adding=================\n";
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//	}
//	
//	int po=2;
//	for(int i=po;i<n-1;i++){
//		arr[i]=arr[i+1];
//	}
//	n--;
//	
//	cout<<"\n=======================After removing=================\n";
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//	}
// }
