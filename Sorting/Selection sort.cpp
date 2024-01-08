#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int arr_size;
    cin >> arr_size;

    vector<int> arr(arr_size, 0);
    for (int index = 0; index < arr_size; index++)
    {
        cin >> arr[index];
    }

    // If I take the min value, I can't able to swap it with two indices of an array.
    // Time complexity : O(n * n)

    int min_element_index{};
    for (int start = 0; start < arr_size; start++)
    {
        min_element_index = start;
        for (int iter = start; iter < arr_size; iter++)
        {
            if (arr[min_element_index] > arr[iter])
            {
                min_element_index = iter;
            }
        }
        if (min_element_index != start)
        {
            arr[min_element_index] ^= arr[start];
            arr[start] = arr[min_element_index] ^ arr[start];
            arr[min_element_index] ^= arr[start];
        }
    }

    // Optimised selection sort : find both minimum and maximum element and swapping
    // It will reduce the half of its time complexity
    /*
    for (int i = 0, j = n - 1; i < j; j--, i++)
    {
        minIndex = i;
        min = arr[i];
        maxIndex = i;
        max = arr[i];
        for (int k = i; k <= j; k++)
        {
            if (arr[k] < arr[minIndex])
            {
                minIndex = k;
                min = arr[k];
            }
            if (arr[k] > arr[maxIndex])
            {
                maxIndex = k;
                max = arr[k];
            }
        }
        swap(arr[i], arr[minIndex]);
        if (arr[minIndex] == max)
            swap(arr[maxIndex], arr[minIndex]);
        else
            swap(arr[maxIndex], arr[j]);
    }
    */
    for (int num : arr)
    {
        cout << num << " ";
    }

    return 0;
}