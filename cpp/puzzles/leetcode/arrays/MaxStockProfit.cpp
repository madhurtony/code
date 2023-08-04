// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
/* You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

*/

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
    int maxProfitBruteForced(vector<int>& prices) {
        size_t size = prices.size();
        int max = 0;
        for (size_t i = 0; i < size; ++i) {
            int bestPrice = 0;
            for (size_t j = i + 1; j < size; ++j) {
                if (prices[j] > prices[i] && prices[j] > bestPrice) {
                    bestPrice = prices[j];
                    if (bestPrice - prices[i] > max) max = bestPrice - prices[i];
                }
            }

        }
        return max;
    }

    /*
    We just need to keep track of minimum price. if prices[i] > minimum price then check if profit > maxprofit
    */
    int maxProfit(vector<int>& prices) {
        size_t size = prices.size();
        if (size == 0) return 0;

        int max = 0;
        int min = prices[0];
        for (size_t i = 1; i < size; ++i) {
            if (prices[i] < min) min = prices[i];
            else if ((prices[i] - min) > max) max = prices[i] - min;
        }
        return max;
    }
};


int main()
{
    {
        Solution s;
        vector<int> prices = { 7,1,5,3,6,4 };
        assert(s.maxProfitBruteForced(prices) == 5);
        assert(s.maxProfit(prices) == 5);

    }

    {
        Solution s;
        vector<int> prices = { 7,6,4,3,1 };
        assert(s.maxProfitBruteForced(prices) == 0);
        assert(s.maxProfit(prices) == 0);

    }

}
