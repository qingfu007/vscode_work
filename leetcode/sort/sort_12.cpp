#include<bits/stdc++.h>

using namespace std;

/*
Link: https://leetcode-cn.com/problems/top-k-frequent-elements/
date: 2020/12/15
Author: qingfu
*/
class Solution {
public:

    static bool cmp(const pair<int,int>& m,const pair<int,int>& n){
        return m.second>n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(const auto& num:nums){
            ++mp[num];
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(&cmp)> q(cmp);
        for(const auto& p:mp){
            q.emplace(p);
            if(q.size()>k){
                q.pop();
            }  
        }
        vector<int> res;
        while(!q.empty()){
            res.emplace_back(q.top().first);
            q.pop();
        }
        return res;
    }
};
    
    




