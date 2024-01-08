class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // Insertion sort
        m = nums1.size();
        n = nums2.size();
        int index = 0;
        int iter = 0;
        for (int i = m - n; i < m; i++)
        {
            iter = i - 1;
            while (iter >= 0 && nums1[iter] > nums2[index])
            {
                nums1[iter + 1] = nums1[iter];
                iter--;
            }
            nums1[iter + 1] = nums2[index++];
        }
    }
};