class NumArray
{
public:
    vector<int> numArray;
    NumArray(vector<int> &nums)
    {
        numArray = nums;

        for (int iter = 1; iter < nums.size(); iter++)
        {
            numArray[iter] += numArray[iter - 1];
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
        {
            return numArray[right];
        }
        return numArray[right] - numArray[left - 1];
    }
};