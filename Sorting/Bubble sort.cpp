#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int arr_size{};
    cout << "Enter the size of the array" << '\n';
    cin >> arr_size;

    // default value of vector be zero
    vector<int> array(arr_size);
    cout << "Enter the elements for the array" << '\n';
    for (int index = 0; index < arr_size; index++)
    {
        cin >> array[index];
    }

    // Optimised
    bool check = false;
    for (int index = 0; index < arr_size; index++)
    {
        check = false;
        for (int cmp = 0; cmp < arr_size - index - 1; cmp++)
        {
            if (array[cmp] > array[cmp + 1])
            {
                swap(array[cmp], array[cmp + 1]);
                check = true;
            }
        }
        if (!check)
        {
            break;
        }
    }

    for (int number : array)
    {
        cout << number << " ";
    }
    return 0;
}