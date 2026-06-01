// 3. Best Time to Buy and Sell Stock
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int bestbuy[100000];
        bestbuy[0] = INT_MAX;
        for (int i = 1; i < n; i++)
        {
            bestbuy[i] = min(bestbuy[i - 1], prices[i - 1]);
        }

        int maxvalue = 0;
        for (int i = 0; i < n; i++)
        {
            int currentsum = prices[i] - bestbuy[i];
            maxvalue = max(maxvalue, currentsum);
        }
        return maxvalue;
    }
};
