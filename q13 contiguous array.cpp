// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

// Example 1:
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
// Example 2:
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// Note: The length of the given binary array will not exceed 50,000.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map <int,int> a;
        int ans = 0;
        int c = 0;
        a[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                c--;
            }
            else
            {
                c++;
            }
            // cout<<"c is "<<c<<"\n";
            auto it = a.find(c);
            if(it!=a.end())
            {
                ans = max(ans,i-it->second);
                // cout<<i<<" "<<it->second<<"\n";
            }
            else
            {
                a[c]=i;
            }
        }
        return ans;
    }
};


