// Given an array of strings, group anagrams together.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:

// All inputs will be in lowercase.
// The order of your output does not matter.

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<pair<string,int>> a;
        for(int i=0;i<strs.size();i++)
        {
            a.push_back({strs[i],i});
        }
        for(int i=0;i<a.size();i++)
        {
            sort(a[i].first.begin(),a[i].first.end());
        }
        sort(a.begin(),a.end());
        vector<vector<string>> ans;
        int k=0;
        vector <string> ans2;
        ans2.push_back(strs[a[0].second]);
        for(int i=1;i<a.size();i++)
        {
            if(a[i].first==a[i-1].first)
            {
                ans2.push_back(strs[a[i].second]);
            }
            else
            {
                k++;
                ans.push_back(ans2);
                ans2.clear();
                ans2.push_back(strs[a[i].second]);
            }
        }
        if(ans2.size()>0)
        {
            k++;
            ans.push_back(ans2);
        }
        return ans;
    }
};

