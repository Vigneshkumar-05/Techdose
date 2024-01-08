class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int freq[3] = {0};
        vector<int> result(nums.size());
        for (int iter = nums.size() - 1; iter >= 0; iter--)
        {
            freq[nums[iter]]++;
        }
        for (int iter = 1; iter < 3; iter++)
        {
            freq[iter] += freq[iter - 1];
        }
        for (int iter = nums.size() - 1; iter >= 0; iter--)
        {
            result[--freq[nums[iter]]] = nums[iter];
        }
        nums = result;
    }
};