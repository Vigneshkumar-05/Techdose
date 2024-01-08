class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int right = nums.size() - 1;
        int left = 0;
        int middle = 0;
        while (left <= right)
        {
            middle = left + (right - left) / 2;
            if (target == nums[middle])
            {
                return middle;
            }
            else if (nums[middle] >= nums[left])
            {
                if (target >= nums[left] && target < nums[middle])
                {
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
            else
            {
                if (target > nums[middle] && target <= nums[right])
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle - 1;
                }
            }
        }
        return -1;
    }
};