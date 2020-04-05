// Given a non-empty array of integers, every element appears twice except for one. Find that single one.

// Note:

// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

// Example 1:

// Input: [2,2,1]
// Output: 1
// Example 2:

// Input: [4,1,2,1,2]
// Output: 4
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        {
            ans^=nums[i];
        }
        return ans;
    }
};


int main()
{
    vector<int> a;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int j;
        cin>>j;
        a.push_back(j);
    }
    Solution b;
    int ans = b.singleNumber(a);
    cout<<ans;
    return 0;
}