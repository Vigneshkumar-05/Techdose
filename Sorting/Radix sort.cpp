// Uses counting sort on digits
// Max element's digit count

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int arr[10] = {0};
    int freq[10] = {0};
    int res[10] = {0};
    int max_digit_count = 0;

    for (int index = 0; index < 10; index++)
    {
        cin >> arr[index];

        // log function return the value in double type
        // max funtion takes same data type values only
        max_digit_count = max((int)log10(arr[index]) + 1, max_digit_count);
    }

    int count = 1;
    while (count <= max_digit_count)
    {
        for (int index = 0; index < 10; index++)
        {
            freq[(arr[index] / (int)pow(10, count - 1)) % 10]++;
        }
        for (int index = 1; index < 10; index++)
        {
            freq[index] += freq[index - 1];
        }
        for (int index = 9; index >= 0; index--)
        {
            res[--freq[(arr[index] / (int)pow(10, count - 1)) % 10]] = arr[index];
        }
        for (int index = 0; index < 10; index++)
        {
            arr[index] = res[index];
            freq[index] = 0;
        }
        count++;
    }
    for (int index = 0; index < 10; index++)
    {
        cout << arr[index] << " ";
    }

    return 0;
}