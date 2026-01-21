#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end) {
    vector<int> temp;

    int i = st;
    int j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int idx = 0; idx < temp.size(); idx++) {
        arr[st + idx] = temp[idx];
    }
}

void mergeSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;

        mergeSort(arr, st, mid);      
        mergeSort(arr, mid + 1, end);  
        merge(arr, st, mid, end);      
    }
}

int main() {
    vector<int> arr1 = {12, 11, 13, 5, 6, 7};
    vector<int> arr2 = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(arr1, 0, arr1.size() - 1);
    mergeSort(arr2, 0, arr2.size() - 1);

    cout << "Sorted Array 1: ";
    for (int x : arr1)
        cout << x << " ";
    cout << endl;

    cout << "Sorted Array 2: ";
    for (int x : arr2)
        cout << x << " ";
    cout << endl;

    return 0;
}