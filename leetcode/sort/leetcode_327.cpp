#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_set>

using namespace std;

namespace violent_solu{
//暴力解法，对每个起始点，计算1-n的长度和，满足则结果加一
//时间复杂度：O(n^2);
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res=0;
        for(int i=0;i<nums.size();++i)
        {
            long sum=0;
            for(int j=i;j<nums.size();++j)
            {
                
                sum+=nums[j];
                
                if(sum>=lower&&sum<=upper) ++res;                
            }
        }
        return res;
    }
};

}


namespace merge_sort{
//解题思路：前缀和+归并排序
//前缀和：每个元素表示前n个元素之和。
//计算前缀和之后，题目变成求解前后两元素之差为范围之内。
//利用归并排序的思想：分为两个数组，各自升序排列时，计算后一数组元素和前一数组元素的差值满足要求的个数。
//关键在于排序不影响数量！！！
//最后递归获得左右子数组的计数量。

//两个升序数组，求满足条件的差值数目：左边遍历数组，右边双指针，每次右移找到上下界。右边上下界结果根据左边遍历变化只可能是右移的。

//问题，转化为了递归求解。递归，请将子问题视为已知结果。
//求解总数组结果，等于左数组结果+右数组结果+当前结果。

class Solution {
public:
    int merge_count(vector<long>& sum,int lower,int upper,int left,int right)
    {
        if(left==right)
        {
            return 0; //    问题的最底层
        }
        else
        {
            int mid=(left+right)/2;
            int n1=merge_count(sum,lower,upper,left,mid);
            int n2=merge_count(sum,lower,upper,mid+1,right);
            int res=n1+n2;
            //运行到当前位置，左右已经是升序数组了。

            //递归计算下标对数量
            int i=left;
            int l=mid+1;
            int r=mid+1;
            while(i<=mid){
                while(l<=right&&sum[l]-sum[i]<lower) ++l;
                while(r<=right&&sum[r]-sum[i]<=upper) ++r;
                res+=(r-l);
                i++;

            }

            //计算完成下标对数量后，合并数组便于递归的返回
            vector<long> sorted(right-left+1);
            int p1=left,p2=mid+1;
            int p=0;
            while(p1<=mid||p2<=right)
            {
                if(p1>mid){
                    sorted[p++]=sum[p2++];
                }
                else if(p2>right){
                    sorted[p++]=sum[p1++];
                }
                else
                {
                    if(sum[p1]<sum[p2]){
                        sorted[p++]=sum[p1++];
                    }
                    else{
                        sorted[p++]=sum[p2++];
                    }
                }                
            }
            for(int i=0;i<sorted.size();i++)
            {
                sum[left+i]=sorted[i];
            }

            return res;


        }
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long s=0;
        vector<long> sum;
        sum.push_back(0);
        for(auto& c:nums)
        {
            s+=c;
            sum.push_back(s);
        }
        return merge_count(sum,lower,upper,0,sum.size()-1);
        
    }

};

}



/*
Link: https://leetcode-cn.com/problems/count-of-range-sum/
date: 2020/11/07
Author: qingfu
*/
