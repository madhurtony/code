// https://leetcode.com/problems/excel-sheet-column-number/

/*
Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

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

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701


Constraints:

1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].

*/

#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        size_t length = columnTitle.length();
        int number = 0;
        for (size_t count = 0; count < length; ++count)
            number = 26 * number + (columnTitle[count] - 'A' + 1);

        return number;
    }
};

int main()
{
    {
        Solution s;
        assert(s.titleToNumber("A") == 1);
    }

    {
        Solution s;
        assert(s.titleToNumber("AB") == 28);
    }

    {
        Solution s;
        assert(s.titleToNumber("ZY") == 701);
    }

}