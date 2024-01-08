#include <iostream>
#include <vector>
using namespace std;

// Recursion
void subsequence(int arr_length, vector<int> &arr, vector<int> &ds, int current_length)
{
    if (current_length == arr_length)
    {
        cout << "{ ";
        for (auto num : ds)
        {
            cout << num << " ";
        }
        cout << "}" << '\n';
        return;
    }
    ds.emplace_back(arr[current_length]);
    subsequence(arr_length, arr, ds, current_length + 1);

    ds.pop_back();
    subsequence(arr_length, arr, ds, current_length + 1);
    return;
}

int main()
{
    int arr_length;
    cin >> arr_length;

    vector<int> arr(arr_length);
    for (int index = 0; index < arr_length; index++)
    {
        cin >> arr[index];
    }

    vector<int> ds;
    subsequence(arr_length, arr, ds, 0);
    return 0;
}

/*
Bit manipulation
int main()
{
    string str;
    cin >> str;

    // printing all the subsequence with bit manipulation
    set<string> subsequence;
    int end_range = pow(2, (str.size())) - 1;
    string new_substring;
    int bit_mask{};
    int count{};

    cout << end_range << endl;

    for (int iter = 0; iter <= end_range; iter++)
    {
        new_substring = "";
        bit_mask = iter;
        count = 0;
        while (bit_mask > 0)
        {
            if (bit_mask & 1)
            {
                new_substring += str[count];
            }
            bit_mask >>= 1;
            count++;
        }
        subsequence.insert(new_substring);
    }

    cout << subsequence.size() << endl;
    for (string s : subsequence)
    {
        cout << s << endl;
    }
    return 0;
} */