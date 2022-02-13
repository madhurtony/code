// https://leetcode.com/problems/shuffle-string/
/*
You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.
*/

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string str = s;
        for (int count = 0; count < indices.size(); ++count) {
            str[count] = s[indices[count]];
        }
        return str;
    }
};


int main()
{
    Solution s;
    {
        vector<int> indices = { 4,5,6,7,0,1,2,3 };
        assert(s.restoreString("codeleet", indices) == "leetcode");
    }
    {
        vector<int> indices = { 0,1,2 };
        assert(s.restoreString("abc", indices) == "abc");
    }
}

