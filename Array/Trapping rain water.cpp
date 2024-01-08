class Solution
{
public:
    int trap(vector<int> &height)
    {
        // Two pointer approach
        int heightSize = height.size();
        int left = 0;
        int right = heightSize - 1;
        int leftMax = 0;
        int rightMax = 0;
        int result = 0;

        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (leftMax < height[left])
                {
                    leftMax = height[left];
                }
                else
                {
                    result += leftMax - height[left];
                }
                left++;
            }
            else
            {
                if (rightMax < height[right])
                {
                    rightMax = height[right];
                }
                else
                {
                    result += rightMax - height[right];
                }
                right--;
            }
        }
        return result;
    }
};