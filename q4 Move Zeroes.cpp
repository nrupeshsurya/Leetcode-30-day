// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Example:

// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Note:

// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> a;
    int zeros=0;
    for(int i=0;i<n;i++)
    {
        int j;
        cin>>j;
        if(j==0)
        {
            zeros++;
        }
        a.push_back(j);
    }
    cout<<endl;
    remove(a.begin(),a.end(),0);
    for(int i=0;i<zeros;i++)
    {
        a.pop_back();
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}