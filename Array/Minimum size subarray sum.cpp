class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int numsSize = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int length = INT_MAX;
        for (right = 0; right < numsSize; right++)
        {
            sum += nums[right];
            while (sum >= target)
            {
                sum -= nums[left++];
                length = min(right - left + 1, length);
            }
        }
        return (length == INT_MAX) ? 0 : length + 1;
    }
};