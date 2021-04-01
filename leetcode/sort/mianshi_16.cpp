#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        //两遍扫描够了。从左往右，某个元素左侧的最大值大于元素值,为n,不断遍历
        //从右往左，某个元素右侧的最小值小于元素值，为m，不断遍历
        int maxx=INT_MIN,minn=INT_MAX;
        int m=-1,n=-1;
        for(int i=0;i<array.size();++i){

            if(array[i]<maxx){
                n=i;
            } 
            maxx=max(maxx,array[i]);            
        }

        for(int i=array.size()-1;i>=0;--i){

            if(array[i]>minn){
                m=i;

            } 
            minn=min(minn,array[i]);            
        }
        return {m,n};

    }
};
    
    




/*
Link: https://leetcode-cn.com/problems/sub-sort-lcci/
date: 2020/11/13
Author: qingfu
*/