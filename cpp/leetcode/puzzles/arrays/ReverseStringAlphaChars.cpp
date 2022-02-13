// ReverseStringAlphaChars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static string reverseOnlyLetters(string s) {
        if (s.length() <= 1) return s;
        int first = 0;
        int last = s.length() - 1;

        while (first <= last) {
            if (!isalpha(s[first++])) continue;
            if (!isalpha(s[last--])) {
                --first;
                continue;
            }

            swap(s[first - 1], s[last + 1]);

        }
        return s;

    }
};
int main()
{
    std::cout << "Hello World!\n";
    string s = "a-bC-dEf-ghIj";
    cout << Solution::reverseOnlyLetters(s);
}

