#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i]存储着长度为i的最长上升子序列中的最小末尾值。
        if(nums.empty()) return 0;
        int n=nums.size();
        vector<int> dp;
        dp.push_back(nums[0]);
        int len=0;
        for(int i=1;i<n;++i){
            if(nums[i]>dp[len]){
                dp.push_back(nums[i]);
                ++len;
            }
            else{
                int left=0,right=len;
                
                while(left<right){//左闭右闭区间
                    int mid=left+(right-left)/2;
                    if(dp[mid]>=nums[i]){
                        right=mid;
                    }
                    else{
                        left=mid+1;
                    }
                }
            dp[right]=nums[i];
            }
            
        }
        return len+1;
    }
};

/*
Link: https://leetcode-cn.com/problems/longest-increasing-subsequence/
date: 2020/11/28
Author: qingfu
*/