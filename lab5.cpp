//#include<iostream>
//using namespace std;
//int main(){
//	int n=7,tag;
//	int arr[n]={2,4,6,8,10,12,14};
//	cout<<"Enter element you want to find: ";
//	cin>>tag;
//	bool p=false;
//	int st=0,end=n-1,mid;
//	while(st<=end){
//		mid=(st+end)/2;
//		if(arr[mid]==tag){
//			cout<<"Element found at index: "<<mid;
//			p=true;
//			break;
//		}else if(tag<arr[mid]){
//			end=mid-1;
//		}else if(tag>arr[mid]){
//			st=mid+1;
//		}
//	}
//	if(!p){
//		cout<<tag<<" is not present in the array!";
//	}
//}

//#include<iostream>
//using namespace std;
//int main(){
//	int n=5;
//	int arr[n]={5,3,8,4,2};
//	
//	for(int i=0;i<n-1;i++){
//		for(int j=0;j<n-i-1;j++){
//			if(arr[j]>arr[j+1]){
//				swap(arr[j],arr[j+1]);
//			}
//		}
//	}
//	
//	cout<<"========updated array===============\n";
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//	}
//}

//#include<iostream>
//using namespace std;
//
//int main() {
//	int a,b;
//	cout<<"Enter two numbers: ";
//	cin>>a>>b;
//    int *ptr1 = &a;
//    int *ptr2 = &b;
//    
//    int temp=*ptr1;
//    *ptr1=*ptr2;
//    *ptr2=temp;
//    
//    cout<<a<<" "<<b;
//}

//#include<iostream>
//using namespace std;
//int main(){
//	int arr1[2][3]={{1,2,3},{4,5,6}};
//	int arr2[3][2]={{11,22},{44,55},{77,88}};
//	
//	for(int i=0;i<2;i++){
//		for(int j=0;j<3;j++){
//			cout<<arr1[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	cout<<"\n";
//	for(int i=0;i<3;i++){
//		for(int j=0;j<2;j++){
//			cout<<arr2[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	
//	int arr3[2][2];
//	for(int i=0;i<2;i++){
//		for(int j=0;j<3;j++){
//			
//		}
//	}
//	
//}


//#include<iostream>
//#include<cstring>
//using namespace std;
//
//struct Employee{
//		string name;
//		float salary;
//	};
//	
//
//int main(){
//	Employee emp[3]={{"Jawad",20500},{"Mohsin",20000},{"Ali",35800}};
//	
//	for(int i=0;i<3;i++){
//		if(emp[i].name=="Mohsin"){
//			cout<<"Employee "<<emp[i].name<<" is present "<<emp[i].salary<<endl;
//		}
//	}
//	
//	
//	for(int i=0;i<3;i++){
//		for(int j=0;j<2;j++){
//			if(emp[j].salary<emp[j+1].salary){
//				swap(emp[j],emp[j+1]);
//			}
//		}
//	}
//	
//	for(int i=0;i<3;i++){
//		cout<<emp[i].name<<" "<<emp[i].salary<<endl;
//	}
//}
//#include<iostream>
//using namespace std;
//
//struct rollno{
//	char dep[20];
//	int sess;
//	int regNo;
//	char deg[20];
//};
//struct student{
//	char name[20];
//	int age;
//	rollno r;
//};
//
//int main(){
//	student st;
//	cout<<"Enter name: ";
//	cin>>st.name;
//	
//	cout<<"Enter age: ";
//	cin>>st.age;
//	
//	cout<<"Enter RegNo: ";
//	cin>>st.r.regNo;
//	
//	cout<<"Enter session: ";
//	cin>>st.r.sess;
//	
//	cout<<"Enter Department: ";
//	cin>>st.r.dep; 
//	
//	cout<<"Enter Degree: ";
//	cin>>st.r.deg;
//	
//	cout<<"Name: "<<st.name<<" Age: "<<st.age<<" Department: "<<st.r.dep<<" \nDegree: "<<st.r.deg<<" RollNo: "<<st.r.regNo<<" Session: "<<st.r.sess;
//	
//}


