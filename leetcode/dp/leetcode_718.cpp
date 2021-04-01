#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int findLength(vector<int>& A, vector<int>& B){
        int m=A.size(),n=B.size();
        int res=0;
        for(int i=0;i<m;++i){
            int overlen=min(n,m-i);
            int maxsublen=maxLength(A,B,i,0,overlen);
            res=max(res,maxsublen);
        }

        for(int i=0;i<n;++i){
            int overlen=min(m,n-i);
            int maxsublen=maxLength(A,B,0,i,overlen);
            res=max(res,maxsublen);
        }
        return res;
    }

    int maxLength(vector<int>& A,vector<int>& B,int idxA,int idxB,int overlen){
        int ans=0,k=0;
        for(int i=0;i<overlen;++i){
            if(A[idxA+i]==B[idxB+i]){
                ++k;
            }
            else{
                k=0;
            }
            ans=max(ans,k);
        }
        return ans;
    }
};
/*
Link: https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/
date: 2020/11/28
Author: qingfu
*/