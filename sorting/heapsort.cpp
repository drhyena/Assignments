#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int size, int root){
    int largest = root;
    int left = 2*root + 1;
    int right = 2*root + 2;

    if(left < size && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < size && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != root){
        swap(arr[root], arr[largest]);
        heapify(arr, size, largest);
    }
}

void heap_sort(vector<int>& arr, int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr, n, i);
    }

    for(int i=n-1;i>0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
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

    heap_sort(arr, n);

    cout << "Sorted array: " << endl;
    for(int x : arr){
        cout << x << "\t";
    }
    cout << endl;
}