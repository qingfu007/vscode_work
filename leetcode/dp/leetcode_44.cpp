#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        //dp[i][j]==dp[i-1][j-1]&&match(s[i],p[j]);  表示s[0-i]和p[0-j]是否匹配
        //dp[i][j]==dp[i-1][j]||dp[i][j-1] *要不要和当前字符匹配
        //最优子结构
        int m=s.length(),n=p.length();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;

        for(int j=1;j<=n;++j){
            if(p[j-1]=='*') dp[0][j]=1;
            else
            {
                break;
            }
        }

        for(int i=1;i<=m;++i){
            for(int j=1;j<=n;++j){
                if(p[j-1]!='*'){
                    dp[i][j]=dp[i-1][j-1]&&match(s[i-1],p[j-1]);
                }
                else{
                    dp[i][j]=dp[i-1][j]||dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
    bool match(char c,char d){
        if(d==c||d=='?') return true;
        return false;
    }
};

/*
Link: https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
date: 2020/11/28
Author: qingfu
*/