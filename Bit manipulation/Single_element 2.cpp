class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        int sum = 0;
        for (int iter = 0; iter < 32; iter++)
        {
            sum = 0;
            for (int index = 0; index < nums.size(); index++)
            {
                sum += nums[index] >> iter & 1;
            }
            sum %= 3;
            result |= sum << iter;
        }
        return result;
    }
};