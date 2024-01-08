class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int length = nums.size();

        if (length == 1)
        {
            return;
        }

        int index = 1;
        int lastPeak = -1;

        for (index = 1; index < length; index++)
        {
            if (nums[index] > nums[index - 1])
            {
                lastPeak = index;
            }
        }

        // If the array is sort in decreasing order the lastPeak will be -1
        if (lastPeak == -1)
        {
            // The given array should be sorted
            int left = 0;
            int right = length - 1;
            while (left < right)
            {
                swap(nums[left], nums[right]);
                right--;
                left++;
            }
            return;
        }

        // Special case [3, 5, 4] should be swapped with 4 to get the next lexographically next permutation
        int swapIndex = -1;
        for (int iter = lastPeak + 1; iter < length; iter++)
        {
            if (nums[iter] > nums[lastPeak - 1] and nums[iter] < nums[lastPeak])
            {
                swapIndex = iter;
            }
        }
        if (swapIndex == -1)
        {
            swapIndex = lastPeak;
        }
        swap(nums[swapIndex], nums[lastPeak - 1]);
        sort(nums.begin() + lastPeak, nums.end());
    }
};