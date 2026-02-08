#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
cd "C:\Users\SiliCon\Desktop\Sem3_Programms\Information Security\Project\ProtectX_Gateway"
python -m streamlit run login.py
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;
    quickSort(arr, 0, n - 1);

    cout << "Sorted Array with Indexing:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Index " << i << ": " << arr[i] << endl;
    }
    return 0;
}
