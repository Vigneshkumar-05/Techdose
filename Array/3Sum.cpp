class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // Sorting + Two pointer
        int numsSize = nums.size();
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        int index = 0;
        int left = 0;
        int right = numsSize - 1;

        int sum = 0;

        while (index < numsSize)
        {
            left = index + 1;
            right = numsSize - 1;

            while (left < right)
            {
                sum = nums[index] + nums[left] + nums[right];

                if (sum == 0)
                {
                    result.push_back({nums[index], nums[left], nums[right]});

                    while (right > left && nums[right] == sum - (nums[index] + nums[left]))
                    {
                        right--;
                    }

                    while (left < right && nums[left] == sum - (nums[index] + nums[right]))
                    {
                        left++;
                    }
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
            index++;

            while (index < numsSize && nums[index - 1] == nums[index])
            {
                index++;
            }
        }

        return result;

        // Time Complexity : O(N^2) + [n*log(n) -> sorting]
        // Space complexity : O(number of unique triplets)
    }
};
