#include<iostream>
using namespace std;

struct student{
	char name [20];
	int roll;
	int marks;
	
};

void sort(student s[]){
	for(int i=0;i<3-1;i++){
		for(int j=0;j<3-i-1;j++){
			if(s[i].marks<s[i+1].marks){
				swap(s[i].marks,s[i+1].marks);
			}
		}
	}
	
	for(int i=0;i<3;i++){
		cout<<s[i].marks<<" "<<s[i].name<<" "<<s[i].roll<<endl;
	}
}

int main(){
	int marks[3][3]={};
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<"["<< i<<"]"<<" ["<<j<<"] : ";
			cin>>marks[i][j];
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<marks[i][j]<<" ";
		}
		cout<<endl;
	}

	
	student s[3];
	cout<<"Enter name roll and marks: ";
	for(int i=0;i<3;i++){
		cin>>s[i].name>>s[i].roll>>s[i].marks;
	}
	
	sort(s);
	
}


