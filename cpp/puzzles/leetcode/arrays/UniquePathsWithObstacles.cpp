//https://leetcode.com/problems/unique-paths-ii/
// Medium
/*
* You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1


Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/

#include <iostream>
#include <vector>
#include<assert.h>
using namespace std;
class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int number_of_rows = obstacleGrid.size();
        int number_of_cols = obstacleGrid[0].size();

        vector<vector<int>> grid(number_of_rows, vector<int>(number_of_cols, 0));
        // edge case of never reaching the end as grid[number_of_rows][number_of_cols] is obstacle
        if (obstacleGrid[0][0] == 1 || obstacleGrid[number_of_rows - 1][number_of_cols - 1] == 1) return 0;

        grid[0][0] = 1;
        for (int row = 0; row < number_of_rows; ++row) {
            for (int col = 0; col < number_of_cols; ++col) {
                if (obstacleGrid[row][col] == 1) continue;

                if (row > 0) grid[row][col] += grid[row - 1][col];
                if (col > 0) grid[row][col] += grid[row][col - 1];
            }
        }

        return grid[number_of_rows - 1][number_of_cols - 1];
    }
};

int main()
{
    {
        Solution s;
        vector<vector<int>> grid = { {0, 0}, { 0, 1 } };
        assert(s.uniquePathsWithObstacles(grid) == 0);
    }

    {
        Solution s;
        vector<vector<int>> grid = { {0, 0, 0},{0, 1, 0},{0, 0, 0} };
        assert(s.uniquePathsWithObstacles(grid) == 2);
    }

   
}
