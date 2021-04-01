#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {

        //dp[i][j]表示前i种硬币凑齐金额j的方法
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));

        for(int i=0;i<=n;++i){
            dp[i][0]=1;
        }

        for(int i=1;i<=n;++i){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]>=0)
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }

        }
        return dp[n][amount];
    } 
};

class Solution {
public:
    int change(int amount, vector<int>& coins) {

        int n=coins.size();
        int dp[amount+1];
         memset(dp, 0, sizeof(dp));
         dp[0]=1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]>=0)
                    dp[j]=dp[j]+dp[j-coins[i-1]];
            }
        }
        return dp[amount];
    }
};
    
    




/*
Link: https://leetcode-cn.com/problems/coin-change-2/
date: 2020/11/18
Author: qingfu
*/