#include <iostream>
#include <array>
using namespace std;

int partitionArray(int arr[], int low, int high)
{
    int pivot = (low + rand()) % (high - low + 1);
    int left = low;
    int right = high;

    while (left <= right)
    {
        while (arr[left] <= arr[pivot])
        {
            ++left;
        }
        while (arr[right] > arr[pivot])
        {
            --right;
        }
        if (left < right)
        {
            swap(arr[right], arr[left]);
        }
    }
    swap(arr[pivot], arr[right]);
    return right;
}

void quickSort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int middle = partitionArray(arr, low, high);
    quickSort(arr, low, middle - 1);
    quickSort(arr, middle + 1, high);
}
int main()
{
    int arraySize;
    printf("Enter the array size: \n");
    scanf("%d", &arraySize);

    int nums[arraySize];
    printf("Enter the elements for the array: \n");
    for (int index = 0; index < arraySize; index++)
    {
        scanf("%d", &nums[index]);
    }

    quickSort(nums, 0, arraySize - 1);

    printf("After sorting...\n");
    for (int index = 0; index < arraySize; index++)
    {
        printf("%d ", nums[index]);
    }

    return 0;
}
