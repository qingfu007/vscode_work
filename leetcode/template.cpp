#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:

    int islandPerimeter(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();++i)
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j]==1) return dfs(grid,i,j);
            }
        return 0;
    }

    int dfs(vector<vector<int>>& grid,int row,int col)
    {
        if(row<0||row>grid.size()-1||col<0||col>grid[0].size()-1||grid[row][col]==0) return 1;
        if(grid[row][col]==2) return 0;
        grid[row][col]=2;
        int k= dfs(grid,row+1,col)
               +dfs(grid,row-1,col)
               +dfs(grid,row,col+1)
               +dfs(grid,row,col-1);
        grid[row][col]=1;
        return k;
        

    }
    
    


};

/*
Link: https://leetcode-cn.com/problems/single-number/
date: 2020/10/24
Author: qingfu
*/