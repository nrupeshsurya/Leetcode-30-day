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