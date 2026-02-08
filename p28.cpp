//#include<iostream>
//using namespace std;
//
//void insertion(int arr[],int n){
//	for(int i=1;i<n;i++){
//		int curr=arr[i];
//		int j = i-1;
//		while(j>=0 && arr[j]<curr){
//			arr[j+1]=arr[j];
//			j--;
//		}
//
//		swap(arr[j+1],curr);
//	}
//	for(int i=0;i<n;i++){
//		cout<<arr[i]<<" ";
//	}
//}
//int main(){
//	int n=4;
//	int arr[n]={213,123,34,2};
//	
//	insertion(arr,n);
//}


//#include <iostream>
//using namespace std;
//
//int partition(int arr[], int low, int high) {
//    int pivot = arr[high];
//    int i = low - 1;
//    for (int j = low; j < high; j++) {
//        if (arr[j] <= pivot) {
//            i++;
//            swap(arr[i], arr[j]);
//        }
//    }
//    
//    swap(arr[i + 1], arr[high]);
//    return i + 1;
//}
//
//void quickSort(int arr[], int low, int high) {
//    if (low < high) {
//        int pi = partition(arr, low, high);
//        quickSort(arr, low, pi - 1);
//        quickSort(arr, pi + 1, high);
//    }
//}
//
//int main() {
//    int arr[] = {10, 7, 8, 9, 1, 5};
//    int n = 6;
//    quickSort(arr, 0, n - 1);
//    cout << "Sorted Array: ";
//    for (int i = 0; i < n; i++)
//        cout << arr[i] << " ";
//    return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector< int> >& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < graph[node].size(); i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    int n = 6;
    vector<vector< int > > graph(n);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    graph[2].push_back(5);
    graph[4].push_back(5);

    vector<bool> visited(n, false);

    cout << "DFS Traversal starting from node 0: ";
    dfs(0, graph, visited);
    cout << endl;

    return 0;
}
