#include <iostream>
#include <vector>
#include <string>
using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int pivot = left;
    int low = left;
    int high = right;
    while (low <= high)
    {
        while (arr[low] <= arr[pivot] and low <= right)
        {
            low++;
        }
        while (arr[high] > arr[pivot] and high >= left)
        {
            high--;
        }
        if (low < high)
        {
            swap(arr[low], arr[high]);
        }
    }
    swap(arr[high], arr[pivot]);
    return high;
}
int quickSelect(vector<int> &arr, int left, int right, int target)
{
    if (left >= right)
    {
        return arr[left];
    }
    int middle = partition(arr, left, right);
    if (middle == target)
    {
        return arr[middle];
    }
    else if (middle > target)
    {
        quickSelect(arr, left, middle - 1, target);
    }
    else if (middle < target)
    {
        quickSelect(arr, middle + 1, right, target);
    }
}
int main()
{
    int testCase;
    cin >> testCase;
    while (testCase--)
    {
        int n{};
        cin >> n;
        vector<int> arr(n);
        for (int index = 0; index < n; index++)
        {
            cin >> arr[index];
        }
        int target{};
        cin >> target;
        for (auto iter : arr)
        {
            cout << iter << " ";
        }
        cout << '\n';
        cout << quickSelect(arr, 0, n - 1, n - target);
        cout << '\n';
    }
    return 0;
}
