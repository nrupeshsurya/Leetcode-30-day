// Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
// An empty string is also valid.
// Example 1:
// Input: "()"
// Output: True
// Example 2:
// Input: "(*)"
// Output: True
// Example 3:
// Input: "(*))"
// Output: True
// Note:
// The string size will be in the range [1, 100].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack <int> st1;
        stack <int> st2;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st1.push(i);
            }
            else if(s[i]=='*')
            {
                st2.push(i);
            }
            else if(s[i]==')')
            {
                if(!st1.empty())
                {
                    st1.pop();
                }
                else if(!st2.empty())
                {
                    st2.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if(st1.empty())
        {
            return true;
        }
        while(!st1.empty())
        {
            if(st2.empty())
            {
                return false;
            }
            int a = st1.top();
            int b = st2.top();
            if(b<a)
            {
                return false;
            }
            st1.pop();
            st2.pop();
        }
        return true;
    }
};