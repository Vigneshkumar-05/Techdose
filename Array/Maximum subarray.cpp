class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // Kadane's Algorithm
        int currentSum = 0;
        int subarrayMaxSum = INT_MIN;

        for (int index = nums.size() - 1; index >= 0; index--)
        {
            currentSum += nums[index];
            if (currentSum < nums[index])
            {
                currentSum = nums[index];
            }
            subarrayMaxSum = max(subarrayMaxSum, currentSum);
        }

        return subarrayMaxSum;
    }
};