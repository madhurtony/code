
//https://leetcode.com/problems/minimum-time-visiting-all-points/
/*
* On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:

In 1 second, you can either:
move vertically by one unit,
move horizontally by one unit, or
move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
You have to visit the points in the same order as they appear in the array.
You are allowed to pass through points that appear later in the order, but these do not count as visits.

Example 1:
Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]
Time from [1,1] to [3,4] = 3 seconds
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds

Example 2:

Input: points = [[3,2],[-2,2]]
Output: 5

Constraints:

points.length == n
1 <= n <= 100
points[i].length == 2
-1000 <= points[i][0], points[i][1] <= 1000

*/

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;
/*
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        // Should have at least 2 points
        if (points.size() <= 1) return 0;
        size_t index = 0;
        int stepsCount = 0;

        while (index < (points.size() - 1)) {
            vector<int> point1 = points[index];
            vector<int> point2 = points[index + 1];

            // Move diagonally till at least one of x or y coordinates is same
            while ((point1[0] != point2[0]) && (point1[1] != point2[1])) {
                if (point2[0] > point1[0]) ++point1[0];
                else --point1[0];
                if (point2[1] > point1[1])  ++point1[1];
                else --point1[1];
                ++stepsCount;
            }
            // make x cooridinate same
            while (point1[0] != point2[0]) {
                if (point2[0] > point1[0]) ++point1[0];
                else --point1[0];
                ++stepsCount;
            }
            // make y cooridinate same
            while (point1[1] != point2[1]) {
                if (point2[1] > point1[1]) ++point1[1];
                else --point1[1];
                ++stepsCount;
            }

            ++index;

        }

        return stepsCount;
    }
};
*/

// Improved solution - we just need to find greater difference between points x or y coordinates and thats the distance between two points
class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        size_t size = points.size();
        if (size == 1) return 0;
        int totalNumberOfSteps = 0;
        for (size_t count = 0; count < size - 1; ++count)
            totalNumberOfSteps +=
            max(abs(points[count][0] - points[count + 1][0]), abs(points[count][1] - points[count + 1][1]));

        return totalNumberOfSteps;
    }
};


int main()
{
    // TestCase 1
    {
        Solution s;
        vector<vector<int>> points = { {1,1},{3,4},{-1,0} };
        assert(s.minTimeToVisitAllPoints(points) == 7);
    }

    // TestCase 2
    {
        Solution s;
        vector<vector<int>> points = { {3,2},{-2,2} };
        assert(s.minTimeToVisitAllPoints(points) == 5);
    }

    // TestCase 3
    {
        Solution s;
        vector<vector<int>> points = { {3,2} };
        assert(s.minTimeToVisitAllPoints(points) == 0);
    }
    return 0;
}

