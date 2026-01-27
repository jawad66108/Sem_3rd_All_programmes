////////#include <iostream>
////////#include <vector>
////////using namespace std;
////////void DFS(int node, vector<vector<int> > &adjList, vector<bool> &visited) {
////////    visited[node] = true;
////////    cout << "Department " << node << " visited" << endl;
////////
////////    for (size_t i = 0; i < adjList[node].size(); i++) {
////////    int neighbor = adjList[node][i];
////////    if (!visited[neighbor])
////////        DFS(neighbor, adjList, visited);
////////	}	
////////}
////////int main() {
////////    int n, e;
////////    cout << "Enter number of departments and pathways: ";
////////    cin >> n >> e;
////////
////////    vector<vector<int> > adjList(n);
////////    cout << "Enter pathways (u v):" << endl;
////////    for (int i = 0; i < e; i++) {
////////        int u, v;
////////        cin >> u >> v;
////////        adjList[u].push_back(v);
////////        adjList[v].push_back(u); // Since pathways are bidirectional
////////    }
////////
////////    vector<bool> visited(n, false);
////////    cout << "DFS Traversal starting from Main Gate (0):" << endl;
////////    DFS(0, adjList, visited);
////////
////////    return 0;
////////}
//////
//////
//////#include <iostream>
//////#include <vector>
//////#include <string>
//////using namespace std;
//////void DFS(int page, vector<vector<int> > &links, vector<bool> &visited, vector<string> &pageNames) {
//////    visited[page] = true;
//////    cout << "Visited: " << pageNames[page] << endl;
//////
//////    // Classic for loop instead of range-based for loop
//////    for (size_t i = 0; i < links[page].size(); i++) {
//////        int link = links[page][i];
//////        if (!visited[link]) {
//////            DFS(link, links, visited, pageNames);
//////        }
//////    }
//////}
//////int main() {
//////    int n, e;
//////    cout << "Enter number of web pages and links: ";
//////    cin >> n >> e;
//////    vector<string> pageNames(n);
//////    cout << "Enter page names:" << endl;
//////    for (int i = 0; i < n; i++) cin >> pageNames[i];
//////
//////    vector<vector<int> > links(n); // Added space between >> 
//////    cout << "Enter links (u v) u->v:" << endl;
//////    for (int i = 0; i < e; i++) {
//////        int u, v;
//////        cin >> u >> v;
//////        links[u].push_back(v);
//////    }
//////
//////    vector<bool> visited(n, false);
//////    cout << "DFS Navigation starting from Home Page (0):" << endl;
//////    DFS(0, links, visited, pageNames);
//////
//////    return 0;
////
//////}
////
////#include <iostream>
////using namespace std;
////void insertionSort(int arr[], int n) {
////    for (int i = 1; i < n; i++) {
////        int key = arr[i];
////        int j = i - 1;
////
////        while (j >= 0 && arr[j] > key) {
////            arr[j + 1] = arr[j];
////            j--;
////        }
////
////        arr[j + 1] = key;
////
////        // Display array after each pass
////        cout << "After pass " << i << ": ";
////        for (int k = 0; k < n; k++) cout << arr[k] << " ";
////        cout << endl;
////    }
////}
////
////int main() {
////    int n;
////    cout << "Enter number of students: ";
////    cin >> n;
////
////    int marks[n];
////    cout << "Enter marks of students: ";
////    for (int i = 0; i < n; i++) cin >> marks[i];
////
////    insertionSort(marks, n);
////
////    return 0;
////}
//
//
//#include <iostream>
//using namespace std;
//int partition(int arr[], int low, int high) {
//    int pivot = arr[high];
//    int i = low - 1;
//
//    for (int j = low; j < high; j++) {
//        if (arr[j] < pivot) {
//            i++;
//            swap(arr[i], arr[j]);
//        }
//    }
//    swap(arr[i + 1], arr[high]);
//    return i + 1;
//}
//void quickSort(int arr[], int low, int high) {
//    if (low < high) {
//        int pi = partition(arr, low, high);
//
//        quickSort(arr, low, pi - 1);
//        quickSort(arr, pi + 1, high);
//    }
//}
//int main() {
//    int n;
//    cout << "Enter number of products: ";
//    cin >> n;
//
//    int prices[n];
//    cout << "Enter product prices: ";
//    for (int i = 0; i < n; i++) cin >> prices[i];
//
//    quickSort(prices, 0, n - 1);
//
//    cout << "Sorted product prices: ";
//    for (int i = 0; i < n; i++) cout << prices[i] << " ";
//    cout << endl;
//
//    return 0;
//}



#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    bubbleSort(arr, n);

    return 0;
}

