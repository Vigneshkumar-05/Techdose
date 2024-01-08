class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // Boyer Moore voting algorithm
        int length = nums.size();
        int votes = 0;
        int candidate = -1;

        for (int index = 0; index < length; index++)
        {
            if (votes == 0)
            {
                candidate = nums[index];
                votes = 1;
            }
            else if (nums[index] == candidate)
            {
                votes++;
            }
            else
            {
                votes--;
            }
        }

        return candidate;
    }
};