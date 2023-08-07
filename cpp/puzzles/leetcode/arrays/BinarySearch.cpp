// https://leetcode.com/problems/binary-search/
// Easy
/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1


Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.
*/

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binarysearch(nums, 0, nums.size() - 1, target);
    }

    int binarysearch(vector<int>& nums, int beg, int end, int target) {
        if (beg > end) return -1;
        int mid = (beg + end) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) return binarysearch(nums, beg, mid - 1, target);
        else return binarysearch(nums, mid + 1, end, target);
    }
};
int main()
{
    {
        Solution s;
        vector<int> nums{ -1 };
        assert(s.search(nums, -1) == 0);
    }

    {
        Solution s;
        vector<int> nums{ -1 };
        assert(s.search(nums, 2) == -1);
    }

    {
        Solution s;
        vector<int> nums{ -1,0,3,5,9,12 };
        assert(s.search(nums, -1) == 0);
    }

    {
        Solution s;
        vector<int> nums{ -1,0,3,5,9,12 };
        assert(s.search(nums, 12) == 5);
    }

    {
        Solution s;
        vector<int> nums{ -1,0,3,5,9,12 };
        assert(s.search(nums, 9) == 4);
    }

    {
        Solution s;
        vector<int> nums{ -1,0,3,5,9,12 };
        assert(s.search(nums, 2) == -1);
    }

    {
        Solution s;
        vector<int> nums{ -1,0,3,5,9,12, 16 };
        assert(s.search(nums, 12) == 5);
    }

}

