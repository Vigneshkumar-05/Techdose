#include <iostream>
#include <vector>
#include <string>
using namespace std;

void heapify(vector<int> &arr, int arr_size, int current_index)
{
    int left_child = 2 * current_index + 1;
    int right_child = 2 * current_index + 2;
    int largest = current_index;

    if (left_child < arr_size and arr[left_child] > arr[largest])
    {
        swap(arr[left_child], arr[largest]);
    }
    if (right_child < arr_size and arr[right_child] > arr[largest])
    {
        swap(arr[right_child], arr[largest]);
    }
    heapify(arr, arr_size, largest - 1);
}
int main()
{
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int index = 0; index < size; index++)
    {
        cin >> arr[index];
    }

    heapify(arr, size, size - 1);

    for (int index = 0; index < size; index++)
    {
        cout << arr[index] << " ";
    }
    cout << '\n';
    return 0;
}