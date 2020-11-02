#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};

/*
Link: https://leetcode-cn.com/problems/single-number/
date: 2020/10/24
Author: qingfu
*/