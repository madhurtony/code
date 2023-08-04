// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
/* 
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
 

Constraints:

1 <= prices.length <= 3 * 104
0 <= prices[i] <= 104
*/

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        size_t first = 0, second = 1;
        size_t size = prices.size();
        int maxprofit = 0;
        
        // we will take two pointers
        // first will keep pointing to lowest buy price and second will keep moving till prices are increasing
        // if price on T is less than T-1, we will sell on T-1 and buy on T again

        while (second < size) {
            if (prices[second] < prices[second - 1]) {
                maxprofit += prices[second - 1] - prices[first];
                first = second;
            }
            ++second;
        }
        // in case prices keep increasing from first till end of range
        if ((second-1) != first) maxprofit += prices[second - 1] - prices[first];
        return maxprofit;
    }
};

class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minPrice = prices[0];
        int maxPrice = prices[0];
        int profit = 0;
        size_t size = prices.size();
        for (size_t count = 1; count < size; ++count) {
            int price = prices[count];
            if (price < prices[count - 1]) {
                maxprofit += profit;
                profit = 0;
                minPrice = maxPrice = price;
            }
            else {
                maxPrice = price;
                profit = maxPrice - minPrice;
            }

        }
        return maxprofit + profit;
    }
};

/*
This is the most efficient solution.
We just need to keep on adding price increases in steps when they increase from i to i+1. No need to keep track of min or max price or profit
*/
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        size_t size = prices.size();
        if (size == 1) return 0;
        int maxprofit = 0;
        for (size_t count = 1; count < size; ++count) {
            if (prices[count] > prices[count - 1])
                maxprofit += prices[count] - prices[count - 1];
        }
        return maxprofit;
    }
};
int main()
{
    {
        Solution3 s;
        vector<int> prices = { 7,1,5,3,6,4 };
        assert(s.maxProfit(prices) == 7);

    }

    {
        Solution3 s;
        vector<int> prices = { 7,6,4,3,1 };
        assert(s.maxProfit(prices) == 0);

    }

    {
        Solution3 s;
        vector<int> prices = { 1,2,3,4,5 };
        assert(s.maxProfit(prices) == 4);

    }


}
