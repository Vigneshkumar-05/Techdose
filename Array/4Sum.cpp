class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int numsSize = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        int left = 0;
        int right = numsSize - 1;
        long long int sum = 0LL;

        for (int index = 0; index < numsSize; index++)
        {
            if (index > 0 && nums[index] == nums[index - 1])
            {
                continue;
            }
            for (int iter = index + 1; iter < numsSize; iter++)
            {
                if (iter > index + 1 && nums[iter] == nums[iter - 1])
                {
                    continue;
                }

                left = iter + 1;
                right = numsSize - 1;

                while (left < right)
                {
                    sum = (long long)nums[index] + nums[iter] + nums[left] + nums[right];

                    if (sum > target)
                    {
                        right--;
                    }
                    else if (sum < target)
                    {
                        left++;
                    }
                    else
                    {
                        result.push_back({nums[index], nums[iter], nums[left], nums[right]});
                        left++;
                        right--;

                        while (left < right && nums[right] == nums[right + 1])
                        {
                            right--;
                        }
                        while (left < right && nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                    }
                }
            }
        }

        return result;
    }
};