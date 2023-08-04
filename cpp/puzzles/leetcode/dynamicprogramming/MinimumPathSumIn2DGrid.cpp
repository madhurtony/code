//https://leetcode.com/problems/minimum-path-sum/description/?source=submission-ac
//Medium

/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12


Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200


*/

#include <iostream>
#include <vector>
#include<cassert>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rowsCount = grid.size();
        int colsCount = grid[0].size();

        vector<vector<int>> dp(rowsCount, vector<int>(colsCount, 0));

        dp[0][0] = grid[0][0];

        // Use dynamic programming to keep track of sum on each [i,j]th position
        // For each [i,j]th position, we need to add minimum of [i-1,j] and [i,j-1] position
        for (int row = 0; row < rowsCount; ++row) {
            for (int col = 0; col < colsCount; ++col) {
                if (row == 0 && col == 0) continue;
                if (row == 0)
                    dp[row][col] += (grid[row][col] + dp[0][col - 1]);
                else if (col == 0)
                    dp[row][col] += (grid[row][col] + dp[row - 1][0]);
                else {
                    dp[row][col] += (grid[row][col] + min(dp[row - 1][col], dp[row][col - 1]));
                }
            }
        }
        return dp[rowsCount - 1][colsCount - 1];
    }
};

int main()
{
    {
        Solution s;
        vector<vector<int>> grid = { {1,3,1} ,{1,5,1},{4,2,1} };
        assert(s.minPathSum(grid) == 7);
    }

    {
        Solution s;
        vector<vector<int>> grid = { {1,2,3} ,{4,5,6} };
        assert(s.minPathSum(grid) == 12);
    }


}

