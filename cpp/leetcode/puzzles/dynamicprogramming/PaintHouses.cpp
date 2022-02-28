// https://leetcode.com/problems/paint-house/
/*
* There is a row of n houses, where each house can be painted one of three colors: red, blue, or green. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by an n x 3 cost matrix costs.

For example, costs[0][0] is the cost of painting house 0 with the color red; costs[1][2] is the cost of painting house 1 with color green, and so on...
Return the minimum cost to paint all houses.

 

Example 1:

Input: costs = [[17,2,17],[16,16,5],[14,3,19]]
Output: 10
Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue.
Minimum cost: 2 + 5 + 3 = 10.
*/

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int size = costs.size();
        if (size == 1) return min(costs[0][0], min(costs[0][1], costs[0][2]));
        int rmin = costs[0][0];
        int bmin = costs[0][1];
        int gmin = costs[0][2];
        for (int i = 1; i < costs.size(); ++i) {
            int rminNew = costs[i][0] + min(bmin, gmin);
            int bminNew = costs[i][1] + min(rmin,gmin);
            int gminNew = costs[i][2] + min(rmin,bmin);
            rmin = rminNew;
            bmin = bminNew;
            gmin = gminNew;
        }

        return min(rmin, min(bmin, gmin));
    }
};
int main()
{
    {
        Solution s;
        vector<vector<int>> v = { {17,2,17},{16,16,5},{14,3,19} };
        cout << s.minCost(v);
        assert(s.minCost(v) == 10);
    }
    {
        Solution s;
        vector<vector<int>> v = { {18,15,9},{20,17,18},  {10,5,1} };
        cout << s.minCost(v);
        assert(s.minCost(v) == 27);
    }
}

