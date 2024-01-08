class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // Quickselect
        int left = 0;
        int right = nums.size() - 1;

        int pivotElement = 0;
        int start;
        int end;

        while (left < right)
        {
            // Random pivot
            pivotElement = nums[rand() % (right - left + 1) + left];

            start = left;
            end = right;

            do
            {
                while (nums[start] > pivotElement)
                {
                    start++;
                }
                while (nums[end] < pivotElement)
                {
                    end--;
                }
                if (start <= end)
                {
                    swap(nums[start], nums[end]);
                    start++;
                    end--;
                }
            } while (start <= end);

            if ((k - 1) < start)
            {
                right = end;
            }
            else
            {
                left = start;
            }
        }

        return nums[k - 1];
    }
};