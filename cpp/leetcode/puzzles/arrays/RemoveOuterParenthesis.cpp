//https://leetcode.com/problems/remove-outermost-parentheses/
/*
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
*/


#include <iostream>
#include <string>
#include <assert.h>

using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        size_t len = s.length();
        size_t index = 0;
        int openParenCount = 0;

        string final;
        string primitive;

        while (index < len) {
            primitive.push_back(s[index]);
            if (s[index] == '(') ++openParenCount;
            else if (s[index] == ')') --openParenCount;

            if (openParenCount == 0) {
                primitive.erase(0,1); // remove first char
                primitive.erase(primitive.length()-1,1); // remove last char
                final.append(primitive); // add to final string
                primitive.clear();
            }
            ++index;

        }
        return final;
    }
};

int main()
{
    Solution s;
    assert(s.removeOuterParentheses("(()())(())") == "()()()");
    assert(s.removeOuterParentheses("(()())(())(()(()))") == "()()()()(())");
    assert(s.removeOuterParentheses("()()") == "");


}
