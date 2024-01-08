class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> temp_array;
        int left = 0;
        int right = nums.size() - 1;
        for (int iter = nums.size() - 1; iter >= 0; iter--)
        {
            temp_array.push_back({nums[iter], iter});
        }
        sort(temp_array.begin(), temp_array.end());
        while (left < right)
        {
            if (temp_array[left].first + temp_array[right].first == target)
            {
                return {temp_array[left].second, temp_array[right].second};
            }
            else if (temp_array[left].first + temp_array[right].first > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return {0, 0};
    }
};