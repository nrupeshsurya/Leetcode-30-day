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

int main()
{
    vector <pair<string,int>> a;
    for(int i=0;i<6;i++)
    {
        string p;
        cin>>p;
        a.push_back({p,i});
    }
    vector <string> temp;
    for (int i = 0; i < 6; i++)
    {
        temp.push_back(a[i].first);
    }
    for(int i=0;i<6;i++)
    {
        sort(a[i].first.begin(),a[i].first.end());
    }
    sort(a.begin(),a.end());
    vector<vector<string>> ans;
    int k=0;
    vector<string> ans2;
    ans2.push_back(temp[a[0].second]);
    for(int i=1;i<6;i++)
    {
        if(a[i].first==a[i-1].first)
        {
            ans2.push_back(temp[a[i].second]);
        }
        else
        {
            k++;
            ans.push_back(ans2);
            ans2.clear();
            ans2.push_back(temp[a[i].second]);
        }
    }
    if(ans2.size()>0)
    {
        ans.push_back(ans2);
        k++;
    }   
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
