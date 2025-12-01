//Write C++ code for the following:
//1. Declare the variables int quantity, float price, and totalBill for the inventory section.
//2. Take input from the user for quantity and price, compute the total bill using totalBill =
//quantity * price, and display the result.
//3. Using two sample integer values, perform and display addition, subtraction,
//multiplication, division, and modulus.
#include<iostream>
using namespace std;
int main(){
//	int quantity;
//	float price;
//	double totalBill;
//	double a=0,b=0;
//	
//	cout<<"Enter Quantity: ";
//	cin>>quantity;
//	cout<<"Enter Price: ";
//	cin>>price;
//	totalBill=quantity*price;
//	cout<<"Your Total Bill is: "<<totalBill;
//	
//	cout<<"\nEnter 2 integers: ";
//	cin>>a,b;
//	
//	cout<<"\nAddition: "<<a+b;
//	cout<<"\nSubtraction: "<<a-b;
//	cout<<"\nMultiplication: "<<a*b;
//	if(a<b){
//		cout<<"2 integer should be greater: ";
//		cout<<"B: ";
//		cin>>b;
//	}else{
//	cout<<"\nDivision: "<<a/b;
//	}	
//	cout<<"\nModulus%: "<<a%b;


//Input marks of a student and display the grade using if-else or switch-case.
//2. Use a for loop to print numbers from 1 to 10.
//3. Use a while loop to calculate and display the sum of numbers from 1 to N, where N is
//entered by the user.
//Use a do-while loop to display the multiplication table of a number entered by the user.

	int marks[3];
	cout<<"Enter marks of three subjects: ";
	
	for(int i=0;i<3;i++){
		cin>>marks[i];
	}
	int sum=0;
	for(int i=0;i<3;i++){
		cout<<i+1<<marks[i];
		sum+=marks[i];
	}
	double avg = sum/3;
	
	cout<<"Avg: "<<avg;
	
	if(avg>85){
		cout<<"You got A grade";
	}else if(avg>75 && avg<85){
		cout<<"You got B grade";
	}else{
		cout<<"Failed!!1\nbetter luck next time";
	}
	
	int n;
	cout<<"Enter n: ";
	cin>>n;
	int i=0,sum1=0;
	while(i<n){
		sum1+=i;
		i++;
	}
	cout<<"Sum is: "<<sum;
}
