#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
         vector<int> dp(T + 1, INT_MAX - 1);
         dp[0]=0;
         for(int i=1;i<=T;i++)
         {
             for(auto& it:clips)
             {
                 if(it[0]<i&&i<=it[1])
                    dp[i]=min(dp[i],dp[it[0]]+1);
             }
         }
         return dp[T] == INT_MAX - 1 ? -1 : dp[T];
    }
};

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
         vector<int> maxn(T);
         //找到每个left对应的最大right
         for(auto it:clips)
         {
             if(it[0]<T) maxn[it[0]]=max(maxn[it[0]],it[1]); 
         }
         //0 2
         //1 9
         //4 6
         //5 9
         //8 10
         int left=0,right=0,res=0;
         while(right<T)
         {
             for(int i=0;i<=left;i++)
                right=max(maxn[i],right);
            if(right>left){
                left=right;
                res++;
            }
            else{
                res=-1;
                break;
            }

         }
         /*
         for(int i=0;i<T;i++)
         {
            right=max(right,maxn[i]);//找到前i个左值对应的最大右值。
            if(i==right)            //  左值等于右值，代表前i个左值连接不到T,-1退出
                return -1;
            if(i==left)            //  i等于前一右值，片段+1；
            {
                res++;
                left=right;
            }
         }
         */
         return res;



    }
};


/*
Link: https://leetcode-cn.com/problems/video-stitching/
date: 2020/10/24
Author: qingfu
*/

