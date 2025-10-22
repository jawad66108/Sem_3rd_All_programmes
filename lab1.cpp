//#include <iostream>
//using namespace std;
//int main() {
//    string name = "Jawad Hussain";
//    string regNo = "BSCS-108";
//    int semester = 3;
//    int joinYear = 2023;
//    int currentYear = 2025;
//    int yearsStudied = currentYear - joinYear;
//    cout << "Name: " << name << endl;
//    cout << "Reg No: " << regNo << endl;
//    cout << "Semester: " << semester << endl;
//    cout << "Join Year: " << joinYear << endl;
//    cout << "Years Studied: " << yearsStudied << endl;
//    return 0;
//}


//#include <iostream>
//using namespace std;
//int main() {
//    int a, b;
//    cout << "Enter two integers: ";
//    cin >> a >> b;
//    cout << "Sum: " << a + b << endl;
//    cout << "Difference: " << a - b << endl;
//    cout << "Product: " << a * b << endl;
//    cout << "Quotient: " << a / b << endl;
//    cout << "Remainder: " << a % b << endl;
//    if (a > b)
//        cout << a << " is greater." << endl;
//    else if (b > a)
//        cout << b << " is greater." << endl;
//    else
//        cout << "Both are equal." << endl;
//    return 0;
//}
//
//
//#include <iostream>
//using namespace std;
//int main() {
//    float width, height;
//    cout << "Enter width and height: ";
//    cin >> width >> height;
//    float area = width * height;
//    float perimeter = 2 * (width + height);
//    cout << "Area: " << area << endl;
//    cout << "Perimeter: " << perimeter << endl;
//    if (width == height)
//        cout << "It is a square." << endl;
//    else
//        cout << "It is a rectangle." << endl;
//    return 0;
//}
//
//#include <iostream>
//using namespace std;
//int main() {
//    float a, b, c;
//    cout << "Enter three numbers: ";
//    cin >> a >> b >> c;
//    float avg = (a + b + c) / 3;
//    cout << "Average: " << avg << endl;
//    if (avg >= 50)
//        cout << "Pass" << endl;
//    else
//        cout << "Fail" << endl;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//int main() {
//    float s1, s2, s3;
//    cout << "Enter marks of three subjects: ";
//    cin >> s1 >> s2 >> s3;
//    float total = s1 + s2 + s3;
//    float avg = total / 3;
//    float percentage = (total / 300) * 100;
//    cout << "Total: " << total << endl;
//    cout << "Average: " << avg << endl;
//    cout << "Percentage: " << percentage << "%" << endl;
//    if (percentage >= 80)
//        cout << "Grade: A" << endl;
//    else if (percentage >= 70)
//        cout << "Grade: B" << endl;
//    else if (percentage >= 60)
//        cout << "Grade: C" << endl;
//    else if (percentage >= 50)
//        cout << "Grade: D" << endl;
//    else
//        cout << "Fail" << endl;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//int main() {
//    char choice;
//    do {
//        float a, b;
//        char op;
//        cout << "Enter first number: ";
//        cin >> a;
//        cout << "Enter operator (+, -, *, /, %): ";
//        cin >> op;
//        cout << "Enter second number: ";
//        cin >> b;
//        switch (op) {
//            case '+': cout << "Result: " << a + b; break;
//            case '-': cout << "Result: " << a - b; break;
//            case '*': cout << "Result: " << a * b; break;
//            case '/': cout << "Result: " << a / b; break;
//            case '%': cout << "Result: " << (int)a % (int)b; 
//			break;
//            default: cout << "Invalid operator."; break;
//        }
//        cout << "\nDo another calculation? (y/n): ";
//        cin >> choice;
//    } while (choice == 'y' || choice == 'Y');
//    return 0;
//}


#include <iostream>
using namespace std;
int main() {
    int N;
    cout << "Enter number of elements: ";
    cin >> N;
    int arr[N];
    int sum = 0;
    cout << "Enter " << N << " numbers: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    cout << "Squares of elements:\n";
    for (int i = 0; i < N; i++) {
        int sq = arr[i] * arr[i];
        cout << sq << " ";
        sum += sq;
    }
    cout << "\nSum of squares: " << sum;
    return 0;
}

