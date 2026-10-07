#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& arr, int n){
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
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

    insertion_sort(arr, n);

    cout << "Sorted array: " << endl;
    for(int x : arr){
        cout << x << "\t";
    }
    cout << endl;
}