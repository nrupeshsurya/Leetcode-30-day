// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.size()==0)
        {
            return nums;
        }
        vector<int> ans(nums.size(),1);
        int temp=1;
        for(int i=1;i<nums.size();i++)
        {
            temp = temp*nums[i-1];
            ans[i]=temp;
        }
        temp=1;
        for(int i=nums.size()-2;i>=0;i--)
        {
            temp = temp*nums[i+1];
            ans[i]*=temp;
        }
        // for(int i=0;i<nums.size();i++)
        // {
        //     cout<<ans[i]<<"\n";
        // }
        return ans;
    }
};