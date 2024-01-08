class Solution
{
public:
    void radixSort(vector<int> &nums, int digit_count, int nums_size)
    {
        int count = 1;
        int digit = 0;
        int freq[10] = {0};
        vector<int> result(nums_size);

        while (count <= digit_count)
        {
            digit = pow(10, count - 1);

            for (int index = 0; index < nums_size; index++)
            {
                freq[nums[index] / digit % 10]++;
            }

            for (int index = 1; index < 10; index++)
            {
                freq[index] += freq[index - 1];
            }

            for (int index = nums_size - 1; index >= 0; index--)
            {
                result[freq[nums[index] / digit % 10] - 1] = nums[index];
                freq[nums[index] / digit % 10] -= 1;
            }

            for (int iter = 0; iter < 10; iter++)
            {
                freq[iter] = 0;
            }

            count++;
            nums = result;
        }
    }

    int maximumGap(vector<int> &nums)
    {
        int nums_size = nums.size();

        if (nums.size() < 2)
        {
            return 0;
        }

        int max_digit_count = log10(*max_element(nums.begin(), nums.end())) + 1;

        radixSort(nums, max_digit_count, nums_size);

        int value = 0;
        for (int index = 1; index < nums_size; index++)
        {
            value = max(nums[index] - nums[index - 1], value);
        }

        return value;
    }
};