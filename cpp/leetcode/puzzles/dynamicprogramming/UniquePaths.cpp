// UniquePaths.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://leetcode.com/problems/unique-paths/
/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
*/

#include <iostream>
#include <vector>
#include<assert.h>
using namespace std;
class Solution {
public:

    int uniquePaths(int rowsCount, int colsCount) {
        vector<vector<int>> gridValues(rowsCount, vector<int>(colsCount, 1));
        for (int row = 1; row < rowsCount; ++row) {
            for (int col = 1; col < colsCount; ++col) {
                gridValues[row][col] = gridValues[row - 1][col] + gridValues[row][col - 1];
            }
        }
        return gridValues[rowsCount - 1][colsCount - 1];

    }
};

int main()
{
    {
        Solution s;
        assert(s.uniquePaths(3,2) == 3);
    }

    {
        Solution s;
        assert(s.uniquePaths(3,7) == 28);
    }


}
