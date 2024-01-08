class Solution
{
public:
    void merge(vector<pair<int, int>> &nums, vector<int> &count, int low, int mid, int high)
    {
        vector<pair<int, int>> leftSubarray;
        vector<pair<int, int>> rightSubarray;

        for (int iter = low; iter <= mid; iter++)
        {
            leftSubarray.push_back(nums[iter]);
        }
        for (int iter = mid + 1; iter <= high; iter++)
        {
            rightSubarray.push_back(nums[iter]);
        }

        int leftPtr = 0;
        int rightPtr = 0;
        int index = low;

        while (leftPtr < leftSubarray.size() && rightPtr < rightSubarray.size())
        {
            if (leftSubarray[leftPtr].first > rightSubarray[rightPtr].first)
            {
                nums[index++] = rightSubarray[rightPtr++];
            }
            else
            {
                nums[index++] = leftSubarray[leftPtr];
                count[leftSubarray[leftPtr++].second] += rightPtr;
            }
        }
        while (leftPtr < leftSubarray.size())
        {
            nums[index++] = leftSubarray[leftPtr];
            count[leftSubarray[leftPtr++].second] += rightPtr;
        }
        while (rightPtr < rightSubarray.size())
        {
            nums[index++] = rightSubarray[rightPtr++];
        }
    }

    void mergeSort(vector<pair<int, int>> &nums, vector<int> &count, int low, int high)
    {
        if (low >= high)
        {
            return;
        }
        int mid = low + (high - low) / 2;
        mergeSort(nums, count, low, mid);
        mergeSort(nums, count, mid + 1, high);
        merge(nums, count, low, mid, high);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return {0};
        }

        // Counting inversion using merge sort
        vector<int> count(nums.size(), 0);
        vector<pair<int, int>> numsCount;
        for (int index = 0; index < nums.size(); index++)
        {
            numsCount.push_back(make_pair(nums[index], index));
        }
        mergeSort(numsCount, count, 0, nums.size() - 1);
        return count;
    }
};