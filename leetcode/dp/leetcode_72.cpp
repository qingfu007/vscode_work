#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2) {
        //插入 删除 替换
        //递归
        //dfs(i,j)为0-i,0-j长度待匹配时候的最小操作数
        int i=word1.size()-1,j=word2.size()-1;
        return dfs(word1,word2,i,j);
    }
    int dfs(string& word1,string& word2,int i,int j){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(word1[i]==word2[j]) return dfs(word1,word2,i-1,j-1);
        else
        {
            return min(dfs(word1,word2,i,j-1)+1,  //word1插入字符，则匹配dfs(i,j-1)
                min(dfs(word1,word2,i-1,j)+1,     //word1删除字符，则匹配dfs(i-1,j)
                dfs(word1,word2,i-1,j-1)+1        //word1替换字符，则匹配的dfs(i-1,j-1)
            ));
        }
    }
};


class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,500));
        //dp[i-1][j-1] 数组s1[0...i]和s2[0...j]的最小编辑距离
        for (int i = 0; i <= m; i++) 
            dp[i][0] = i;
        for (int j = 1; j <= n; j++) 
            dp[0][j] = j;
        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=min(dp[i][j-1]+1,
                    min(dp[i-1][j]+1,dp[i-1][j-1]+1));
                }
            }
        }
        return dp[m][n];
    }
};
    
    




/*
Link: https://leetcode-cn.com/problems/edit-distance/
date: 2020/11/18
Author: qingfu
*/