//#include<iostream>
//using namespace std;
//struct Node{
//	int data;
//	Node *next;
//};
//
//class Linkedlist{
//	Node *head;
//	Node *tail;
//	
//	public:
//		Linkedlist(){
//		head=NULL;
//		tail=NULL;
//	}
//
//
//Node *newnode(int value){
//	Node *temp=new Node;
//	if(temp==NULL){
//		return NULL;
//	}
//	temp->data =value;
//	temp->next=NULL;
//	return temp;
//	
//}
//
//Node beinsert(int value){
//	Node *temp = newnode(value);
//	if(head==NULL){
//		head=tail=temp;
//	}else{
//		temp->next=head;
//		head=temp;
//	}
//	cout<<"value: "<<value<<" is inserted!!";
//}
//
//Node endinsert(int value){
//	Node *temp = newnode(value); 
//	if (head==NULL){
//		head=tail=temp;
//	}else{
//		tail->next=temp;
//		tail=temp;
//	}
//	cout<<"Inserted at end "<<value;
//	}
//	
//};
//
//int main(){
//	Linkedlist list;
//	int value,value1;
//	cout<<"Enter number you want to enter: ";
//	cin>>value;
//	list.beinsert(value);
//	cout<<"\nEnter number you want to enter: ";
//	cin>>value1;
//	list.endinsert(value1);
//	
//	
//	
//}
//

//#include <iostream>
//using namespace std;
//
//struct Node {
//    int data;
//    Node* next;
//};
//
//class LinkedList {
//private:
//    Node* head;
//    Node* tail;
//
//public:
//    LinkedList() {
//        head = NULL;
//        tail = NULL;
//    }
//
//    Node* createNode(int value) {
//        Node* temp = new Node;
//        if (temp == NULL) {
//            cout << "Memory not allocated!" << endl;
//            return NULL;
//        }
//        temp->data = value;
//        temp->next = NULL;
//        return temp;
//    }
//
//    void insertBegin(int value) {
//        Node* temp = createNode(value);
//        if (head == NULL) {
//            head = tail = temp;
//        } else {
//            temp->next = head;
//            head = temp;
//        }
//        cout << "Inserted " << value << " at beginning.\n";
//    }
//
//    void insertLast(int value) {
//        Node* temp = createNode(value);
//        if (head == NULL) {
//            head = tail = temp;
//        } else {
//            tail->next = temp;
//            tail = temp;
//        }
//        cout << "Inserted " << value << " at end.\n";
//    }
//
//    void insertPos(int value, int pos) {
//        Node* temp = createNode(value);
//
//        if (pos < 1) {
//            cout << "Position should be >= 1\n";
//            return;
//        }
//        if (pos == 1) {
//            temp->next = head;
//            head = temp;
//            if (tail == NULL) tail = temp;
//            cout << "Inserted " << value << " at position " << pos << endl;
//            return;
//        }
//
//        Node* current = head;
//        for (int i = 1; i < pos - 1; i++) {
//            if (current == NULL) {
//                cout << "Position out of range\n";
//                return;
//            }
//            current = current->next;
//        }
//
//        if (current == NULL) {
//            cout << "Position out of range\n";
//            return;
//        }
//
//        temp->next = current->next;
//        current->next = temp;
//
//        if (temp->next == NULL)
//            tail = temp;
//
//        cout << "Inserted " << value << " at position " << pos << endl;
//    }
//    void display() {
//    if (head == NULL) {
//        cout << "List is empty!\n";
//        return;
//    }
//
//    Node* temp = head;
//    cout << "Linked List: ";
//    while (temp != NULL) {
//        cout << temp->data << " -> ";
//        temp = temp->next;
//    }
//    cout << "NULL\n";
//}
//
//};
//
//int main() {
//    LinkedList list;
//    int choice, value, pos;
//
//    do {
//        cout << "\n\n--- Linked List Operations ---\n";
//        cout << "1. Insert at Beginning\n";
//        cout << "2. Insert at End\n";
//        cout << "3. Insert at Position\n";
//        cout << "4. Exit\n";
//        cout << "5. Display List\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//        case 1:
//            cout << "Enter value: ";
//            cin >> value;
//            list.insertBegin(value);
//            break;
//
//        case 2:
//            cout << "Enter value: ";
//            cin >> value;
//            list.insertLast(value);
//            break;
//
//        case 3:
//            cout << "Enter value: ";
//            cin >> value;
//            cout << "Enter position: ";
//            cin >> pos;
//            list.insertPos(value, pos);
//            break;
//
//        case 4:
//            cout << "Exiting...\n";
//            break;
//            
//        case 5:
//    		list.display();
//    		break;
//
//
//        default:
//            cout << "Invalid choice!\n";
//        }
//
//    } while (choice != 4);
//
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//struct Node {
//    int data;
//    Node* next;
//};
//
//class LinkedList {
//private:
//    Node* head;
//    Node* tail;
//
//public:
//    LinkedList() {
//        head = NULL;
//        tail = NULL;
//    }
//    void deletePos(int pos) {
//        if (head == NULL) {
//            cout << "List is empty\n";
//            return;
//        }
//
//        if (pos < 1) {
//            cout << "Invalid position\n";
//            return;
//        }
//
//        Node* temp;
//
//        if (pos == 1) {
//            temp = head;
//            head = head->next;
//
//            if (head == NULL)
//                tail = NULL;
//
//            delete temp;
//            cout << "Deleted node at position 1\n";
//            return;
//        }
//
//        Node* current = head;
//
//        for (int i = 1; i < pos - 1; i++) {
//            if (current == NULL) {
//                cout << "Position out of range\n";
//                return;
//            }
//            current = current->next;
//        }
//
//        if (current->next == NULL) {
//            cout << "Position out of range\n";
//            return;
//        }
//
//        temp = current->next;
//        current->next = temp->next;
//
//        if (current->next == NULL)
//            tail = current;
//
//        delete temp;
//        cout << "Deleted node at position " << pos << endl;
//    }
//
//    void searchElement(int value) {
//        Node* current = head;
//        int pos = 1;
//        bool found = false;
//
//        while (current != NULL) {
//            if (current->data == value) {
//                cout << "Element " << value << " found at position " << pos << endl;
//                found = true;
//                break;
//            }
//            current = current->next;
//            pos++;
//        }
//
//        if (!found)
//            cout << "Element " << value << " not found\n";
//    }
//
//    void display() {
//        if (head == NULL) {
//            cout << "List is empty\n";
//            return;
//        }
//
//        Node* current = head;
//        cout << "Linked List: ";
//        while (current != NULL) {
//            cout << current->data << " -> ";
//            current = current->next;
//        }
//        cout << "NULL\n";
//    }
//
//    void createNode(int value) {
//        Node* temp = new Node;
//        temp->data = value;
//        temp->next = NULL;
//
//        if (head == NULL) {
//            head = tail = temp;
//        } else {
//            tail->next = temp;
//            tail = temp;
//        }
//    }
//};
//
//int main() {
//    LinkedList list;
//
//    list.createNode(10);
//    list.createNode(20);
//    list.createNode(30);
//    list.createNode(40);
//
//    int choice, pos, value;
//
//    do {
//        cout << "\n\n--- Linked List Operations ---\n";
//        cout << "1. Delete at Position\n";
//        cout << "2. Search Element\n";
//        cout << "3. Display List\n";
//        cout << "4. Exit\n";
//        cout << "Enter your choice: ";
//        cin >> choice;
//
//        switch (choice) {
//
//        case 1:
//            cout << "Enter position to delete: ";
//            cin >> pos;
//            list.deletePos(pos);
//            break;
//
//        case 2:
//            cout << "Enter element to search: ";
//            cin >> value;
//            list.searchElement(value);
//            break;
//
//        case 3:
//            list.display();
//            break;
//
//        case 4:
//            cout << "Exiting...\n";
//            break;
//
//        default:
//            cout << "Invalid choice!\n";
//        }
//
//    } while (choice != 4);
//
//    return 0;
//}


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    Node* create_node(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = NULL;
        return temp;
    }

    void insert_begin(int value) {
        Node* temp = create_node(value);
        if (head == NULL) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
    }

    void insert_last(int value) {
        Node* temp = create_node(value);
        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void insert_pos(int value, int pos) {
        if (pos < 1) return;
        Node* temp = create_node(value);

        if (pos == 1) {
            temp->next = head;
            head = temp;
            if (tail == NULL) tail = temp;
            return;
        }

        Node* current = head;
        for (int i = 1; i < pos - 1; i++) {
            if (current == NULL) return;
            current = current->next;
        }

        if (current == NULL) return;

        temp->next = current->next;
        current->next = temp;

        if (temp->next == NULL) tail = temp;
    }

    void delete_pos(int pos) {
        if (head == NULL || pos < 1) return;

        Node* temp;

        if (pos == 1) {
            temp = head;
            head = head->next;
            if (head == NULL) tail = NULL;
            delete temp;
            return;
        }

        Node* current = head;
        for (int i = 1; i < pos - 1; i++) {
            if (current == NULL) return;
            current = current->next;
        }

        if (current->next == NULL) return;

        temp = current->next;
        current->next = temp->next;

        if (current->next == NULL) tail = current;

        delete temp;
    }

    void sort() {
        if (head == NULL) return;
        Node* i = head;
        while (i != NULL) {
            Node* j = i->next;
            while (j != NULL) {
                if (i->data > j->data) {
                    int t = i->data;
                    i->data = j->data;
                    j->data = t;
                }
                j = j->next;
            }
            i = i->next;
        }
    }

    void search(int value) {
        Node* current = head;
        int pos = 1;
        while (current != NULL) {
            if (current->data == value) {
                cout << "Found at position " << pos << endl;
                return;
            }
            current = current->next;
            pos++;
        }
        cout << "Not found" << endl;
    }

    void update(int pos, int newValue) {
        if (pos < 1) return;
        Node* current = head;
        for (int i = 1; i < pos; i++) {
            if (current == NULL) return;
            current = current->next;
        }
        if (current != NULL) current->data = newValue;
    }

    void display() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int choice, value, pos, newValue;

    do {
        cout << "\n1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Position\n";
        cout << "5. Sort\n";
        cout << "6. Search\n";
        cout << "7. Update\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cin >> value;
            list.insert_begin(value);
            break;
        case 2:
            cin >> value;
            list.insert_last(value);
            break;
        case 3:
            cin >> value >> pos;
            list.insert_pos(value, pos);
            break;
        case 4:
            cin >> pos;
            list.delete_pos(pos);
            break;
        case 5:
            list.sort();
            break;
        case 6:
            cin >> value;
            list.search(value);
            break;
        case 7:
            cin >> pos >> newValue;
            list.update(pos, newValue);
            break;
        case 8:
            list.display();
            break;
        case 9:
            break;
        }
    } while (choice != 9);

    return 0;
}

