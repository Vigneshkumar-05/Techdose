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

    int iter = 0;
    for (int index = 0; index < arr_size; index++)
    {
        cin >> array[index];
        iter = index - 1;

        if (index > 0)
        {
            while (iter >= 0 and array[iter] > array[index])
            {
                swap(array[index], array[iter]);
                iter--;
            }
        }
    }

    for (int number : array)
    {
        cout << number << " ";
    }
    return 0;
}
