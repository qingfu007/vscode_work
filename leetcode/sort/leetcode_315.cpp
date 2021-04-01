#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>

using namespace std;


namespace merge1{
class Solution {
public:

    //类似习题，327 剑指51。求数组前后两元素差值满足一定条件。
    //以及范围和，可转换为前缀和数组。
    //从51变形，求逆序对总数，此题要求求对应每个元素逆序对，给计数结果加位置编号。
    unordered_map<int,int> dict;
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            dict[i]=i;
        }
        vector<int> res(n,0);
        merge_sort(nums,0,n-1,res);
        return res;
    }

    void merge_sort(vector<int>& nums,int left,int right,vector<int>& res){
        if(left>=right){
            return;
        }else{
            int mid=(left+right)/2;
            merge_sort(nums,left,mid,res);
            merge_sort(nums,mid+1,right,res);
            int l=mid+1;
            int i=left;
            while(i<=mid){
                while(l<=right&&nums[l]<nums[i]) ++l;
                res[dict[i]]+=l-mid-1;
                ++i;              
            }

            vector<int> merged(right-left+1);
            vector<int> dictt(right-left+1);
            int p1=left,p2=mid+1;
            int p=0;
            int t=0;
            while(p1<=mid||p2<=right){
                if(p1>mid){
                    dictt[t++]=dict[p2];
                    merged[p++]=nums[p2++];
                    
                }else if(p2>right){
                    dictt[t++]=dict[p1];
                    merged[p++]=nums[p1++];
                }else{
                    if(nums[p1]<nums[p2]){
                        dictt[t++]=dict[p1];
                        merged[p++]=nums[p1++];
                    }else{
                        dictt[t++]=dict[p2];
                        merged[p++]=nums[p2++];
                    }
                }
            }
            
            for(int i=0;i<merged.size();++i){
                nums[left+i]=merged[i];
                dict[left+i]=dictt[i];
            }
            return;
        }
    }

};
    
    


}

/*
Link: https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/
date: 2020/11/07
Author: qingfu
*/