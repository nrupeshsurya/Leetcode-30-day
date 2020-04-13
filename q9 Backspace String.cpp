// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

// Example 1:

// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:

// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:

// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:

// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:

// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
// Follow up:

// Can you solve it in O(N) time and O(1) space?

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string func(string s)
    {
        int b=0;
        string o;
        for(int i = s.size()-1; i >= 0; i--)
        {
            if(s[i]=='#')
            {
                b++;
            }
            else if(b>0)
            {
                b--;
            }
            else
            {
                o+=s[i];
            }
        }
        return o;
    }
    bool backspaceCompare(string S, string T) {
        return (func(S)==func(T));
    }
};