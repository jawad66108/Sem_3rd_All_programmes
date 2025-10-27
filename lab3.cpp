//#include<iostream>
//#include<ctime>
//#include<cstdlib>
//using namespace std;
//
//int re(int n){
//	int fc=1;
//	for(int i=1;i<=n;i++){
//		fc*=i; 
//	}
//	return fc;
//}
//int main(){
//	int m[20];
//	float avg=0,sum=0;
//	int min =m[0];
//	int max=m[0];
//	srand(time(0));
//	for (int i=0;i<20;i++){
//		m[i]=rand()%100;	
//	}
//	
//	for (int i=0;i<20;i++){
//		cout<<m[i]<<" ";
//		if(min>m[i]){
//			min=m[i];
//		}
//		else if(max<m[i]){
//			max=m[i];
//		}
//		sum+=m[i];
//	}
//	avg =sum/20;
//	cout<<"\nMin: "<<min<<" "<<" \nMax: "<< max<<" \navg: "<<avg;
//	
//	int j[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//	
//	cout<<"\n2nd row and 3rd coloum number is: "<<j[1][2];
//	cout<<"\n"<<re(5);
//	
//	for(int i=0;i<=6;i++){
//		cout<<i<<") "<<rand()%6<<"\n";
//	}
//}

//#include <iostream>
//using namespace std;
//int main() {
//    int arr[]={12,14,15,16,17,181};
//    int n=sizeof(arr)/sizeof(arr[0]);
//    cout<<"Size: "<<n<<endl;
//    int st=0,end=n-1,mid=0,tag=17;
//    while(st<=end){
//        mid=(st+end)/2;
//        if(tag==arr[mid]){
//            cout<<"Target found at index: "<<mid;
//            break;
//        }else if(tag<arr[mid]){
//            end=mid-1;
//        }else{
//            st=mid+1;
//        }
//    }
//
//    return 0;
//}


//Question 2 – 2D Array 
//Write a C++ program that inputs a 3×3 matrix and: 
//1. Displays the matrix in table form. 
//2. Calculates and prints the sum of each row and each column. 
//3. Displays the main diagonal elements. 

//#include<iostream>
//using namespace std;
//int main(){
//	int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//
//	for(int i=0;i<3;i++){
//		int sumR=0;
//		for(int j=0;j<3;j++){
//		cout<<arr[i][j]<<" ";
//		sumR+=arr[i][j];
//	}
//	cout<<"  ->Sum of row "<<i+1<<" is: "<<sumR<<endl;
//}
//cout<<"\n==============Each columns sum =========================\n";
//	for(int j=0;j<3;j++){
//		int sumC=0;
//		for(int i=0;i<3;i++){
//		cout<<arr[j][i]<<" ";
//		sumC+=arr[i][j];
//	}
//	cout<<"  ->Sum of colomn "<<j+1<<" is: "<<sumC<<endl;
//}
//cout<<"\n===============Diagonal elements are===============\n";
//cout<<arr[0][0]<<" ";
//cout<<arr[1][1]<<" ";
//cout<<arr[2][2]<<" ";
//}

//#include<iostream>
//using namespace std;
//int main(){
//	int arr[10];
//	cout<<"Enter 10 integers:\n";
//	for(int i=0;i<10;i++)
//	cin>>arr[i];
//	cout<<"\nAll numbers entered: ";
//	for(int i=0;i<10;i++)
//	cout<<arr[i]<<" ";
//	cout<<"\nEven numbers: ";
//	for(int i=0;i<10;i++)
//	if(arr[i]%2==0)
//	cout<<arr[i]<<" ";
//}

//#include<iostream>
//using namespace std;
//int main(){
//	int num;
//	cout<<"Enter a number: ";
//	cin>>num;
//	
//	cout<<"\nUsing for loop:\n";
//	for(int i=1;i<=10;i++)
//	cout<<num<<" x "<<i<<" = "<<num*i<<endl;
//	
//	cout<<"\nUsing while loop:\n";
//	int j=1;
//	while(j<=10){
//	cout<<num<<" x "<<j<<" = "<<num*j<<endl;
//	j++;
//	}
//	cout<<"\nUsing do-while loop:\n";
//	int k=1;
//	do{
//	cout<<num<<" x "<<k<<" = "<<num*k<<endl;
//	k++;
//	}
//	while(k<=10);
//}


//#include<iostream>
//using namespace std;
//void takeInput(int arr[],int size){
//	cout<<"Enter "<<size<<" integers:\n";
//	for(int i=0;i<size;i++)
//	cin>>arr[i];
//}
//void classifyNumbers(int arr[],int size,int &even,int &odd,int &zero){
//	for(int i=0;i<size;i++){
//		if(arr[i]==0)zero++;
//		else if(arr[i]%2==0)
//		even++;
//		else 
//		odd++;
//	}
//}
//void displayResults(int even,int odd,int zero){
//	cout<<"\nEven numbers: "<<even;
//	cout<<"\nOdd numbers: "<<odd;
//	cout<<"\nZeros: "<<zero;
//}
//int main(){
//	int arr[10],even=0,odd=0,zero=0;
//	takeInput(arr,10);
//	classifyNumbers(arr,10,even,odd,zero);
//	displayResults(even,odd,zero);
//}


//#include<iostream>
//using namespace std;
//int main(){
//	int n;
//	cout<<"Enter number of elements: ";
//	cin>>n;
//	int arr[n];
//	cout<<"Enter "<<n<<" integers:\n";
//	for(int i=0;i<n;i++)
//	cin>>arr[i];
//	cout<<"Reversed array: ";
//	for(int i=n-1;i>=0;i--)
//	cout<<arr[i]<<" ";
//}


//
//#include<iostream>
//using namespace std;
//int main(){
//	int arr[5];
//	cout<<"Enter 5 integers:\n";
//	for(int i=0;i<5;i++)
//	cin>>arr[i];
//	cout<<"\nNumbers entered: ";
//	for(int i=0;i<5;i++)
//	cout<<arr[i]<<" ";
//	int max=arr[0],min=arr[0];
//	for(int i=1;i<5;i++){
//		if(arr[i]>max)
//		max=arr[i];
//		if(arr[i]<min)
//		min=arr[i];
//	}
//	cout<<"\nMaximum: "<<max;
//	cout<<"\nMinimum: "<<min;
//	cout<<"\nDifference: "<<max-min;
//}
//
//
//#include<iostream>
//using namespace std;
//int factorial(int n){
//	int fact=1;
//	for(int i=1;i<=n;i++)
//	fact*=i;
//	return fact;
//}
//int main(){
//	int num;
//	cout<<"Enter a number: ";
//	cin>>num;
//	cout<<"Factorial of "<<num<<" = "<<factorial(num);
//}
//
//
//#include<iostream>
//using namespace std;
//int main(){
//	int n;
//	cout<<"Enter number of elements: ";
//	cin>>n;
//	int arr[n];
//	cout<<"Total size of array in bytes: "<<sizeof(arr);
//	cout<<"\nAn int takes "<<sizeof(int)<<" bytes.";
//	cout<<"\nNumber of int elements that can fit in 100 bytes: "<<100/sizeof(int);
//}

