#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low;j<high;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

void quick_sort(vector<int>& arr, int low, int high){
    if(low >= high){
        return;
    }

    int p = partition(arr, low, high);

    quick_sort(arr, low, p-1);
    quick_sort(arr, p+1, high);
}



int main(){
    int n;

    cout <<"enter no: of elements: ";
    cin >> n;
    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cout << "Enter element: ";
        cin >> arr[i];
    }

    quick_sort(arr, 0, n-1);

    cout << "Sorted array: " << endl;
    for(int x : arr){
        cout << x << "\t";
    }
    cout << endl;
}