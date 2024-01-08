class Solution
{
public:
    void allPossibleSubsequenceSum(vector<int> &nums, int start, int end, vector<int> &subsequence, vector<int> &subsequence_sum)
    {
        if (start >= end)
        {
            int total = 0;
            for (int index = subsequence.size() - 1; index >= 0; index--)
            {
                total += subsequence[index];
            }
            subsequence_sum.emplace_back(total);
            return;
        }
        subsequence.emplace_back(nums[start]);
        allPossibleSubsequenceSum(nums, start + 1, end, subsequence, subsequence_sum);

        subsequence.pop_back();
        allPossibleSubsequenceSum(nums, start + 1, end, subsequence, subsequence_sum);
    }
    int splitArray(vector<int> &nums, int start, int middle, int end, int goal)
    {
        int min_value = INT_MAX;
        int lower_bound_index = 0;
        int target = 0;
        vector<int> subsequence;
        vector<int> subsequence_sum1;
        vector<int> subsequence_sum2;

        allPossibleSubsequenceSum(nums, start, middle, subsequence, subsequence_sum1);

        subsequence.clear();

        allPossibleSubsequenceSum(nums, middle, end, subsequence, subsequence_sum2);

        sort(subsequence_sum2.begin(), subsequence_sum2.end());

        for (int index = 0; index < subsequence_sum1.size(); index++)
        {
            target = goal - subsequence_sum1[index];
            lower_bound_index = lower_bound(subsequence_sum2.begin(), subsequence_sum2.end(), target) - subsequence_sum2.begin();

            if (lower_bound_index < subsequence_sum2.size())
            {
                min_value = min(min_value, abs(target - subsequence_sum2[lower_bound_index]));
            }
            if (lower_bound_index > 0)
            {
                min_value = min(min_value, abs(target - subsequence_sum2[lower_bound_index - 1]));
            }
        }

        return min_value;
    }
    int minAbsDifference(vector<int> &nums, int goal)
    {
        return splitArray(nums, 0, nums.size() / 2, nums.size(), goal);
    }
};