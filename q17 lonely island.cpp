// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:

// Input:
// 11110
// 11010
// 11000
// 00000

// Output: 1
// Example 2:

// Input:
// 11000
// 11000
// 00100
// 00011

// Output: 3

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int answer = 0;
        int h = grid.size();
        int w = grid[0].size();
        vector<pair<int,int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<bool>> visited(h,vector<bool>(w));
        auto inside = [&](int row, int col)
        {
            return 0<=row && row<h && 0<=col && col<w;
        };
        for(int row=0;row<h;row++)
        {
            for(int col=0;col<w;col++)
            {
                // cout<<"w"<<" ";
                if(!visited[row][col]&&grid[row][col]=='1')
                {
                    answer++;
                    queue<pair<int,int>> q;
                    q.push({row,col});
                    visited[row][col]=true;
                    while(!q.empty())
                    {
                        pair<int,int> p = q.front();
                        q.pop();
                        for(pair<int,int> dir:directions)
                        {
                            int new_row = p.first + dir.first;
                            int new_col = p.second + dir.second;
                            if(inside(new_row,new_col)&& !visited[new_row][new_col] && grid[new_row][new_col]=='1')
                            {
                                q.push({new_row,new_col});
                                visited[new_row][new_col]=true;
                            }
                        }
                    }
                }
            }
        }
        return answer;
    }
};