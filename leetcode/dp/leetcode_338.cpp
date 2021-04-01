#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
//两个数相差2^m次方时，他们的pop count相差为1.P(x+b)=P(x)+1,b=2^m>x
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        int b=1;
        int i=0;
        while(b<=num){
            while(i<b &&i+b<=num){
                res[i+b]=res[i]+1;
                ++i;
            }
            i=0;
            b<<=1;
        }
        return res;


    }
};


/*
Link: https://leetcode-cn.com/problems/maximum-gap/
date: 2020/11/26
Author: qingfu
*/