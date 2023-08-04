// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Hard problem
/*You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105

*/

#include <iostream>
#include <vector>
#include <assert.h>
#include<set>
using namespace std;

// doest not work in some test cases
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t first = 0, second = 1;
        size_t size = prices.size();
        
        int maxProfit1 = 0, maxProfit2 = 0;
        // we will take two pointers
        // first will keep pointing to lowest buy price and second will keep moving till prices are increasing
        // if price on T is less than T-1, we will sell on T-1 and buy on T again

        while (second < size) {
            if (prices[second] < prices[second - 1]) {
                int profit = prices[second - 1] - prices[first];
                if (profit > min(maxProfit1, maxProfit2)) {
                    if (maxProfit1 < maxProfit2) maxProfit1 = profit;
                    else maxProfit2 = profit;
                }
                first = second;
            }
            ++second;
        }
        // in case prices keep increasing from first till end of range
        if ((second - 1) != first) {
            int profit = prices[second - 1] - prices[first];
            if (profit > min(maxProfit1, maxProfit2)) {
                if (maxProfit1 < maxProfit2) maxProfit1 = profit;
                else maxProfit2 = profit;
            }
        }

        return maxProfit1 + maxProfit2;

    }
};

// doest not work in some test cases
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        size_t size = prices.size();

        if (size == 1) return 0;
        int profit1 = 0;
        int profit2 = 0;
        int profit = 0;
        for (size_t count = 1; count < size; ++count) {
            if (prices[count] > prices[count - 1]) {
                profit += (prices[count] - prices[count - 1]);
            }
            else {
                if ((profit1 <= profit2) && (profit > profit1))
                    profit1 = profit;
                else if ((profit2 <= profit1) && (profit > profit2))
                    profit2 = profit;
                profit = 0;
            }
        }
        if ((profit1 <= profit2) && (profit > profit1))
            profit1 = profit;
        else if ((profit2 <= profit1) && (profit > profit2))
            profit2 = profit;
        return profit1 + profit2;


    }
};


// works in all test cases
/*
 We are going to divide in two sub ranges and then find out max profit for left of ith position and right of ith position
 For this we are going to take 2 arrays
 For 1st array, we traverse from left to right and find max profit on left of each ith position
 For 2nd array, we traverse from right to left and find max profit on right of each ith position

 e.g
                        1      2       4       2       5       7       2       2       4       9
1st (left->right)       0      1       3       3       4       6       6       6       6       8
2nd(right->left)        8      7       7       7       7       7       7       7       5       0
*/
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        size_t size = prices.size();

        if (size == 1) return 0;
        
        vector<int> left_to_right(size,0);
        vector<int> right_to_left(size+1,0); // better to take one extra as it will ease in looping

        int min_price = prices[0];
        for (size_t count = 1; count < size; ++count) {
            left_to_right[count] = max(left_to_right[count - 1], prices[count] - min_price);
            min_price = min(prices[count], min_price);            
        }

        int max_price = prices[size-1];

        // need to use int here else goes into infinite loop
        for (int count = size - 2; count >= 0; --count) {
            right_to_left[count] = max(right_to_left[count + 1], max_price - prices[count]);
            max_price = max(prices[count], max_price);
        }


        int max_profit = 0;
        for (size_t count = 0; count < size; ++count) {
            max_profit = std::max(left_to_right[count] + right_to_left[count + 1], max_profit);
        }

        return max_profit;
    }
};


int main()
{
    {
        Solution3 s;
        vector<int> prices = { 1,2,4,2,5,7,2,4,9,0 };
        assert(s.maxProfit(prices) == 13);

    }
    {
        Solution3 s;
        vector<int> prices = { 6,1,3,2,4,7 };
        assert(s.maxProfit(prices) == 7);

    }

    {
        Solution3 s;
        vector<int> prices = { 3,3,5,0,0,3,1,4 };
        assert(s.maxProfit(prices) == 6);

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
