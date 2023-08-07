// https://leetcode.com/problems/excel-sheet-column-title/

/*
Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...


Example 1:

Input: columnNumber = 1
Output: "A"
Example 2:

Input: columnNumber = 28
Output: "AB"
Example 3:

Input: columnNumber = 701
Output: "ZY"


Constraints:

1 <= columnNumber <= 2^31 - 1
*/

#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string title{};

        while (columnNumber != 0) {
            title += (char)((columnNumber - 1) % 26 + 65);
            columnNumber = (columnNumber - 1) / 26;
        }
        size_t length = title.length();
        for (size_t index = 0; index < length / 2; ++index) {
            swap(title[index], title[length - index - 1]);
        }
        return title;
    }
};


int main()
{
    {
        Solution s;
        assert(s.convertToTitle(26) == "Z");
    }

    {
        Solution s;
        assert(s.convertToTitle(27) == "AA");
    }

    {
        Solution s;
        assert(s.convertToTitle(28) == "AB");
    }

    {
        Solution s;
        assert(s.convertToTitle(701) == "ZY");
    }



}

