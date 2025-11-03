#include<iostream>
using namespace std;
int main(){
	int n,ch,pos;
	bool p=true;
	cout<<"Enter numbers of students: ";
	cin>>n;
	int arr[n];
	cout<<"Enter marks of each student\n";
	for(int i=0;i<n;i++){
		cout<<i+1<<" ) ";
		cin>>arr[i];
		
    }
	
	cout<<"\nEnter marks you want to see that wether it is present in the array: ";
	cin>>ch;
	
	for(int j=0;j<n;j++){
		if(ch==arr[j]){
			cout<<"Found at index: "<<j;
			p=false;
			break;
			
		}
	}
	if(p){
		cout<<ch<<" is not present!!\n";
	}
	
	cout<<"\nEnter marks you want to delete: ";
	cin>>pos;
	
	for(int j=0;j<n;j++){
		if(pos==arr[j]){
			for(int i=j;i<n-1;i++){
		        arr[i]=arr[i+1];
		}
		n--;
		break;
		}
	}
	cout << "\nTotal memory used by the array: "<< sizeof(arr)<<" bytes";
	cout << "\nNumber of elements stored: "<< sizeof(arr)/sizeof(arr[0])<<"\n";

	
	for(int j=0;j<n;j++){
		cout<<arr[j]<<" ";
	}

}


//#include <iostream>
//using namespace std;
//
//int main() {
//    int n, search;
//
//    cout<<"Enter number of products: ";
//    cin>>n;
//	int products[n];
//    cout<< "Enter quantity of each product:\n";
//    for(int i=0;i<n;i++){
//        cout<<"Product "<<i+1<<": ";
//        cin>>products[i];
//    }
//
//    cout << "\nEnter quantity to search: ";
//    cin >>search;
//
//    bool found = false;
//    for (int i = 0; i < n; i++) {
//        if (products[i] == search) {
//            cout << "Quantity "<< search<<" found at index "<<i<< endl;
//            found=true;
//            break;
//        }
//    }
//
//    if (!found){
//        cout<<"Quantity "<< search<< " not found \n";
//    }
//
//    for (int j=0; j<n; j++) {
//        if (products[j] <= 0) {
//            for (int k = j; k < n - 1; k++) {
//                products[k] = products[k + 1];
//            }
//            n--;      
//        }
//    }
//
//    cout << "\nTotal memory allocated for array: " << sizeof(products) << " bytes" << endl;
//    cout << "Memory used by one product quantity: " << sizeof(products[0]) << " bytes" << endl;
//    cout << "Number of possible elements in array: " << sizeof(products) / sizeof(products[0]) << endl;
//
//    cout << "\nUpdated Inventory \n";
//    for (int i=0;i<n;i++) {
//        cout<< products[i]<<" ";
//    }
//
//    return 0;
//}

