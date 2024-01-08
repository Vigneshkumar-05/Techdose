// Linear sorting algorithm
// When the range of values are less and the frequency of the elements are high

#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {0};
    int freq[10] = {0};
    int res[10] = {0};

    for (int index = 0; index < 10; index++)
    {
        cin >> arr[index];
        freq[arr[index]]++;
    }
    // cumulative freq sum to maintain stability
    for (int index = 1; index < 10; index++)
    {
        freq[index] += freq[index - 1];
    }
    for (int index = 9; index >= 0; index--)
    {
        res[--freq[arr[index]]] = arr[index];
    }

    for (int index = 0; index < 10; index++)
    {
        cout << res[index] << " ";
    }

    return 0;
}