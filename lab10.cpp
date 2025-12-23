#include <iostream>
using namespace std;

struct Student {
    int id;
    char name[50];
};

class AdmissionQueue {
public:
    int front;
    int rear;
    int capacity;
    Student* arr;

    AdmissionQueue(int cap) {
        capacity = cap;
        arr = new Student[capacity];
        front = 0;
        rear = -1;
    }

    ~AdmissionQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front > rear;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void enqueue(Student s) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear++;
        arr[rear] = s;
        cout << "Student added\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No student to process\n";
            return;
        }
        cout << "Student processed: " << arr[front].id << " " << arr[front].name << "\n";
        front++;
    }

    void currentStudent() {
        if (isEmpty()) {
            cout << "No student is being served\n";
            return;
        }
        cout << "Current student: " << arr[front].id << " " << arr[front].name << "\n";
    }

    int count() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }
};

int main() {
    AdmissionQueue q(5);
    int choice;

    do {
        cout << "\n1. Add new student\n";
        cout << "2. Process student\n";
        cout << "3. Show current student\n";
        cout << "4. Show total waiting students\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Student s;
            cout << "Enter ID: ";
            cin >> s.id;
            cout << "Enter Name (no spaces): ";
            cin >> s.name;
            q.enqueue(s);
        } else if (choice == 2) {
            q.dequeue();
        } else if (choice == 3) {
            q.currentStudent();
        } else if (choice == 4) {
            cout << "Total waiting: " << q.count() << "\n";
        }

    } while (choice != 0);

    return 0;
}

