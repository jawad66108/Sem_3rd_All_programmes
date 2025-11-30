//#include <iostream>
//#include<cstring>
//using namespace std;
//
//struct job {
//    int id;       
//    char dept[20];   
//    float salary;    
//};
//
//struct employee {
//    char name[20]; 
//    job info;        
//};
//	
//	void LinaerS(employee e[]){
//		char A[20];
//		cout<<"Enter name you are looking for: ";
//		cin>>A;
//		bool p=true;
//		for(int j=0;j<3;j++){
//			if(strcmp(e[j].name , A )==0){
//				cout<<"\n---------Details-------------\n"<<e[j].info.id<<" "<<e[j].info.dept<<" "<<e[j].info.salary;
//				p=false;
//			}
//		}
//		if(p==true){
//			cout<<A<<" is not present!!";
//			return;
//		}
//	}
//	
//	void bubble(employee e[]){
//		for(int i=0;i<3-1;i++){
//			for(int j=0;j<3-i-1;j++){
//				if(e[j].info.salary< e[j+1].info.salary){
//					swap(e[j].info.salary , e[j+1].info.salary);
//				}
//			}
//		}
//		cout<<"--------salary in particular order-------\n";
//		for(int j=0;j<3;j++){
//			cout<<"Name: "<<e[j].name<<" Salary: "<<e[j].info.salary<<endl;
//		}
//	}
//	
//int main() {
//    employee e[3]; 
//
//    for (int i = 0; i < 3; i++) {
//        cout << "Enter name: ";
//        cin >> e[i].name;
//
//        cout << "Enter ID: ";
//        cin >> e[i].info.id;
//
//        cout << "Enter Department: ";
//        cin >> e[i].info.dept;
//
//        cout << "Enter Salary: ";
//        cin >> e[i].info.salary;
//    }
//
//    cout << "\n--- Employee Records ---\n";
//    for (int i = 0; i < 3; i++) {
//        cout << e[i].name << " "
//             << e[i].info.id << " "
//             << e[i].info.dept << " "
//             << e[i].info.salary << endl;
//    }
//    
//    LinaerS(e);
//    bubble(e);
//
//    return 0;
//}

//#include<iostream>
//using namespace std;
//int main(){
//	int c1,r1,c2,r2;
//	cout<<"Row 1 and col 1";
//	cin>>r1>>c1;
//	
//	cout<<"Row 2 and col 2";
//	cin>>r2>>c2;
//	
//	if(c1!=r2){
//		cout<<"Voilates the rule of matix multipliction!!!";
//		return;
//	}
//	
//	int A[10][10],B[10][10],C[10][10];
//	
//	for(int i=0;i<r1;i++){
//		for(int j=0;j<c2;j++){
//			for(int k=0;k<c1;k++){
//				C[i][j]+=A[i][k]*B[k][j];
//			}
//		}
//	}
//}
