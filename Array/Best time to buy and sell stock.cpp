class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int pricesSize = prices.size();
        int profit = 0;
        int minimumPrice = prices[0];

        for (int index = 1; index < pricesSize; index++)
        {
            if (prices[index] < minimumPrice)
            {
                minimumPrice = prices[index];
            }
            else if (prices[index] - minimumPrice > profit)
            {
                profit = prices[index] - minimumPrice;
            }
        }

        return profit;
    }
};