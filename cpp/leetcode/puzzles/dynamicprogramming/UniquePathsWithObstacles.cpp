// UniquePaths.cpp : This file contains the 'main' function. Program execution begins and ends there.
//https://leetcode.com/problems/unique-paths-ii/
/*
* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.
*/

#include <iostream>
#include <vector>
#include<assert.h>
using namespace std;
class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int rowsCount = grid.size();
        int colsCount = grid[0].size();
        vector<vector<int>> gridValues(rowsCount, vector<int>(colsCount, 0));
        

        for (int row = 0; row < rowsCount; ++row) {
            for (int col = 0; col < colsCount; ++col) {

                if (grid[row][col] == 1) continue;

                if (row == 0 && col == 0) gridValues[row][col] = 1;
                else {
                    if (row > 0) gridValues[row][col] += gridValues[row - 1][col];
                    if (col > 0) gridValues[row][col] += gridValues[row][col-1];
                }
            }
        }
        return gridValues[rowsCount-1][colsCount-1];
        
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
