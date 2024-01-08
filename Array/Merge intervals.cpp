class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> nonOverlappingIntervals;
        int intervalsSize = intervals.size();

        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        int index = 1;

        for (; index < intervalsSize; index++)
        {
            if (end < intervals[index][0])
            {
                nonOverlappingIntervals.push_back({start, end});
                start = intervals[index][0];
                end = intervals[index][1];
            }
            else
            {
                end = max(intervals[index][1], end);
            }
        }
        nonOverlappingIntervals.push_back({start, end});

        return nonOverlappingIntervals;
    }
};