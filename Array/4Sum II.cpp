class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4)
    {
        int n = nums1.size();
        int count = 0;

        unordered_map<long long, long long> frequency;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                frequency[nums3[i] + nums4[j]]++;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                count += frequency[-(nums1[i] + nums2[j])];
            }
        }

        return count;
    }
};