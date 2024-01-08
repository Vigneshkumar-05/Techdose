#include <iostream>
#include <array>
#include <vector>
using namespace std;

void merge_function(int arr[], int low, int high, int mid) {
    int arr1_size = mid - low + 1;
    int arr2_size  = high - mid;
    int leftArray[arr1_size];
    int rightArray[arr2_size];

    for (int iter = 0; iter < arr1_size; iter++) {
        leftArray[iter] = arr[low + iter];
    }

    for (int iter = 0; iter < arr2_size; iter++) {
        rightArray[iter] = arr[mid + iter + 1];
    }
    int right = 0;
    int left = 0;
    int index = low;
    while (left < arr1_size && right < arr2_size) {
        if (leftArray[left] <= rightArray[right]) {
            arr[index++] = leftArray[left++];
        } else {
            arr[index++] = rightArray[right++];
        }
    }
    while (left < arr1_size) {
        arr[index++] = leftArray[left++];
    }
    while (right < arr2_size) {
        arr[index++] = rightArray[right++];
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr,mid + 1, high);
    merge_function(arr, low, high, mid);
}
int main() {
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter the array elements: " << endl;
    for (int index = 0; index < n; index++) {
        cin >> arr[index];
    }

    mergeSort(arr, 0, n-1);

    cout << "After sorting..." << endl;
    for (int index = 0; index < n; index++) {
        cout << arr[index] << " ";
    }
    cout << endl;
    return 0;
}
