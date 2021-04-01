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
    int findRotateSteps(string ring, string key) {
        //动态规划，用 dp[i][j] 表示从游戏开始到拼接完成 key[0:i] 在 ring[j]==key[i] 的时候最小步数
        //思考：为什么是二维的？
        //回答：因为可能有不止一个rang[j]==key[i]

        //对于key[i]，其最小步数必然是从rang[j]==key[i-1]从12点钟方向开始的最小值。计算每个rang[j]==key[i]对应的dp[i][j]。 
        //一种多对多的状态转移
        //dp[i][j]=min(dp[i−1][k]+min{abs(j−k),n−abs(j−k)}+1)  k为key[i-1]在rang中的位置。
        //j为key[i]在rang中的位置。

        int n=ring.size(),m=key.size();
        vector<vector<int>> pos(26,vector<int>());  //存储每个单词出现的位置。
        for(int i=0;i<n;++i){
            pos[ring[i]-'a'].push_back(i);  //pos[i]表示每个元素所在的位置。
        }
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));   //dp[i][j]初始值设为INT_MAX

        for(const auto& i:pos[key[0]-'a']){                 //边界条件，第一个字母的最小步数。
            dp[0][i]=min(i,n-i)+1;
        }
        int res=INT_MAX;
        for(int i=1;i<m;++i){//大循环，依次遍历key的每个单词
            for(auto& j:pos[key[i]-'a']){//中循环，依次遍历ring内等于key[i]的rang[j],记录dp[i][j]
                for(auto& k:pos[key[i-1]-'a']){//内循环，取dp[i-1][j]到dp[i][j]的最小值。
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+min(abs(j-k),n-abs(j-k))+1);
                }
            if(i==m-1) res=min(dp[i][j],res); //终点时，取最小的dp[m-1][j];
            }
            
        }
        return res;
        

    }
};

/*
Link: https://leetcode-cn.com/problems/freedom-trail/
date: 2020/11/11
Author: qingfu
*/