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
//动态规划问题，回文串去掉两端也为回文串
//dp[i][j]表示i到j的字串是否为回文串
//状态转移方程：dp[i][j]=dp[i+1][j-1]&&(s[i]==s[j])
//边界条件：    if(i==j) dp[i][j]=true;
//             if(j-i==1) dp[i][j]=(s[i]==s[j])
//循环顺序：大循环是串的长度，内循环是依次遍历当前长度的串。

//vector<bool>比vector<int>慢！！！！！！！！！！！！！！
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n));
        string ans;
        for(int len=0;len<n;++len){     //len表示子串长度,i和j的间距
            for(int i=0;i+len<n;++i)
            {
                int j=i+len;
                if(len==0){
                    dp[i][j]=true;
                }
                else if(len==1){
                    dp[i][j]=(s[i]==s[j]);
                }
                else{
                    dp[i][j]=dp[i+1][j-1]&&(s[i]==s[j]);
                }
                if(dp[i][j]&& len+1>ans.size()){
                    ans=s.substr(i,len+1);
                }

            }
        }
        return ans;

    }
};

/*
Link: https://leetcode-cn.com/problems/longest-palindromic-substring/
date: 2020/11/06
Author: qingfu
*/