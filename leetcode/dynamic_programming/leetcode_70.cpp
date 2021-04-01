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

//动态规划问题：最后一次，爬一步还是爬两步。
//dp[n] 表示n个台阶有dp[n]种方法
//状态转移方程为：  dp[n]=dp[n-1]+dp[n-2];
//边界条件：        dp[0]=0;dp[1]=1;dp[2]=2;dp[3]=3;dp[4]=dp[3]+dp[2];
    int climbStairs(int n) {
        vector<int> dp(n+1,1);
        if(n>=2)
        {
            for(int i=2;i<=n;++i)
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
        }
        return dp[n];
    }
};

/*
Link: https://leetcode-cn.com/problems/climbing-stairs/
date: 2020/11/06
Author: qingfu
*/