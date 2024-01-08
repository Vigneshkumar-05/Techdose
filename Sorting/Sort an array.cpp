class Solution
{
public:
    void merge(vector<int> &nums, int middle, int low, int high)
    {
        int vec1_size = middle - low + 1;
        int vec2_size = high - middle;
        vector<int> arr1(vec1_size);
        vector<int> arr2(vec2_size);
        for (int iter = 0; iter < vec1_size; iter++)
        {
            arr1[iter] = nums[iter + low];
        }
        for (int iter = 0; iter < vec2_size; iter++)
        {
            arr2[iter] = nums[iter + middle + 1];
        }
        int index = low;
        int left = 0;
        int right = 0;
        while (left < vec1_size && right < vec2_size)
        {
            if (arr1[left] < arr2[right])
            {
                nums[index] = arr1[left];
                left++;
            }
            else
            {
                nums[index] = arr2[right];
                right++;
            }
            index++;
        }
        while (left < vec1_size)
        {
            nums[index] = arr1[left];
            index++;
            left++;
        }
        while (right < vec2_size)
        {
            nums[index] = arr2[right];
            right++;
            index++;
        }
    }
    void mergeSort(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int middle = low + (high - low) / 2;
            mergeSort(nums, low, middle);
            mergeSort(nums, middle + 1, high);
            merge(nums, middle, low, high);
        }
    }
    vector<int> sortArray(vector<int> &nums)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};