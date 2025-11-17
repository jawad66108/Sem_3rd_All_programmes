//#include <stdio.h>
//
//void swap(int *a, int *b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//int main() {
//    int x, y;
//
//    printf("Enter two numbers: ");
//    scanf("%d %d", &x, &y);
//
//    printf("Before Swap: x = %d, y = %d\n", x, y);
//
//    swap(&x, &y);
//
//    printf("After Swap:  x = %d, y = %d\n", x, y);
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//struct Employee {
//    int id;
//    string name;
//    float salary;
//};
//
//// Bubble Sort (ascending salary)
//void bubbleSort(Employee e[], int n) {
//    for(int i = 0; i < n - 1; i++) {
//        for(int j = 0; j < n - 1 - i; j++) {
//            if(e[j].salary > e[j + 1].salary) {
//                Employee temp = e[j];
//                e[j] = e[j + 1];
//                e[j + 1] = temp;
//            }
//        }
//    }
//}
//
//// Linear Search by ID
//int linearSearch(Employee e[], int n, int key) {
//    for(int i = 0; i < n; i++) {
//        if(e[i].id == key)
//            return i;
//    }
//    return -1;
//}
//
//int main() {
//    const int n = 3;
//    Employee emp[n];
//
//    cout << "Enter Employee details (ID Name Salary):\n";
//    for(int i = 0; i < n; i++) {
//        cout << "Employee " << i + 1 << ": ";
//        cin >> emp[i].id >> emp[i].name >> emp[i].salary;
//    }
//
//    // Sort employees by salary
//    bubbleSort(emp, n);
//
//    cout << "\nEmployees Sorted by Salary:\n";
//    for(int i = 0; i < n; i++) {
//        cout << emp[i].id << "  " << emp[i].name << "  " << emp[i].salary << endl;
//    }
//
//    // Search
//    int searchID;
//    cout << "\nEnter Employee ID to search: ";
//    cin >> searchID;
//
//    int index = linearSearch(emp, n, searchID);
//
//    if(index != -1) {
//        cout << "\nEmployee Found:\n";
//        cout << emp[index].id << "  " << emp[index].name << "  " << emp[index].salary << endl;
//    }
//    else {
//        cout << "\nEmployee Not Found.\n";
//    }
//
//    return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//struct Employee {
//    string name;
//    float salary;
//};
//
//void sortBySalary(Employee emp[], int n) {
//    for(int i = 0; i < n - 1; i++) {
//        for(int j = 0; j < n - 1 - i; j++) {
//            if(emp[j].salary > emp[j + 1].salary) {
//                Employee temp = emp[j];
//                emp[j] = emp[j + 1];
//                emp[j + 1] = temp;
//            }
//        }
//    }
//}
//
//void sortByName(Employee emp[], int n) {
//    for(int i = 0; i < n - 1; i++) {
//        for(int j = 0; j < n - 1 - i; j++) {
//            if(emp[j].name > emp[j + 1].name) {
//                Employee temp = emp[j];
//                emp[j] = emp[j + 1];
//                emp[j + 1] = temp;
//            }
//        }
//    }
//}
//
//int searchByName(Employee emp[], int n, string key) {
//    for(int i = 0; i < n; i++) {
//        if(emp[i].name == key)
//            return i;
//    }
//    return -1;
//}
//
//int main() {
//    Employee emp[3];
//
//    cout << "Enter 3 Employees (Name Salary):\n";
//    for(int i = 0; i < 3; i++) {
//        cout << "Employee " << i + 1 << ": ";
//        cin >> emp[i].name >> emp[i].salary;
//    }
//
//    sortBySalary(emp, 3);
//    cout << "\nSorted by Salary:\n";
//    for(int i = 0; i < 3; i++)
//        cout << emp[i].name << "  " << emp[i].salary << endl;
//
//    sortByName(emp, 3);
//    cout << "\nSorted by Name:\n";
//    for(int i = 0; i < 3; i++)
//        cout << emp[i].name << "  " << emp[i].salary << endl;
//
//    string key;
//    cout << "\nEnter name to search: ";
//    cin >> key;
//
//    int idx = searchByName(emp, 3, key);
//    if(idx != -1)
//        cout << "\nEmployee Found: " << emp[idx].name << "  " << emp[idx].salary << endl;
//    else
//        cout << "\nEmployee Not Found.\n";
//
//    return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//struct Marks {
//    int sub1, sub2, sub3;
//};
//
//struct Student {
//    int reg;
//    string name;
//    Marks m;
//    float gpa;
//};
//
//float calcGPA(Marks m) {
//    float avg = (m.sub1 + m.sub2 + m.sub3) / 3.0;
//    return avg / 25.0;
//}
//
//void sortByGPA(Student s[], int n) {
//    for(int i = 0; i < n - 1; i++) {
//        for(int j = 0; j < n - i - 1; j++) {
//            if(s[j].gpa < s[j + 1].gpa) {
//                Student temp = s[j];
//                s[j] = s[j + 1];
//                s[j + 1] = temp;
//            }
//        }
//    }
//}
//
//// Search by Registration Number
//int searchByReg(Student s[], int n, int key) {
//    for(int i = 0; i < n; i++) {
//        if(s[i].reg == key)
//            return i;
//    }
//    return -1;
//}
//
//int main() {
//    Student s[3];
//
//    cout << "Enter 3 Students (Reg Name Marks1 Marks2 Marks3):\n";
//    for(int i = 0; i < 3; i++) {
//        cout << "Student " << i + 1 << ": ";
//        cin >> s[i].reg >> s[i].name >> s[i].m.sub1 >> s[i].m.sub2 >> s[i].m.sub3;
//
//        s[i].gpa = calcGPA(s[i].m);
//    }
//
//    sortByGPA(s, 3);
//    cout << "\nStudents Sorted by GPA (High ? Low):\n";
//    for(int i = 0; i < 3; i++)
//        cout << s[i].reg << "  " << s[i].name << "  GPA: " << s[i].gpa << endl;
//
//    int key;
//    cout << "\nEnter Registration Number to search: ";
//    cin >> key;
//
//    int idx = searchByReg(s, 3, key);
//    if(idx != -1)
//        cout << "\nFound: " << s[idx].reg << "  " << s[idx].name << "  GPA: " << s[idx].gpa << endl;
//    else
//        cout << "\nStudent Not Found.\n";
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//    int r1, c1, r2, c2;
//
//    cout << "Enter rows and columns of Matrix A: ";
//    cin >> r1 >> c1;
//
//    cout << "Enter rows and columns of Matrix B: ";
//    cin >> r2 >> c2;
//
//    if(c1 != r2) {
//        cout << "\nMatrix multiplication not possible!";
//        return 0;
//    }
//
//    int A[10][10], B[10][10], C[10][10] = {0};
//
//    cout << "\nEnter elements of Matrix A:\n";
//    for(int i = 0; i < r1; i++) {
//        for(int j = 0; j < c1; j++) {
//            cin >> A[i][j];
//        }
//    }
//
//    cout << "\nEnter elements of Matrix B:\n";
//    for(int i = 0; i < r2; i++) {
//        for(int j = 0; j < c2; j++) {
//            cin >> B[i][j];
//        }
//    }
//
//    for(int i = 0; i < r1; i++) {
//        for(int j = 0; j < c2; j++) {
//            C[i][j] = 0;
//            for(int k = 0; k < c1; k++) {
//                C[i][j] += A[i][k] * B[k][j];
//            }
//        }
//    }
//
//    cout << "\nResultant Matrix (A × B):\n";
//    for(int i = 0; i < r1; i++) {
//        for(int j = 0; j < c2; j++) {
//            cout << C[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//    int a = 10;
//    float b = 5.5;
//    void* ptr;
//
//    ptr = &a;
//    cout << *(int*)ptr << endl;
//
//    ptr = &b;
//    cout << *(float*)ptr << endl;
//
//    return 0;
//}


#include <iostream>
#include <string>
using namespace std;

struct Address {
    string city;
    string country;
};

struct Student {
    int roll;
    string name;
    Address addr;
};

int main() {
    Student s;

    cin >> s.roll;
    cin >> s.name;
    cin >> s.addr.city;
    cin >> s.addr.country;

    cout << s.roll << " " << s.name << " " 
         << s.addr.city << " " << s.addr.country;

    return 0;
}

