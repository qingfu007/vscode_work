#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& A) {

        bool climb=true;
        int length=1,res=0;
        for(int i=0;i<A.size()-1;i++)
        {
            if(A[i]<A[i+1])    
            {
                if(climb) length++;  //上山
                else                 //准备上山
                {
                    i--;
                    climb=true;
                    length=1;
                }
            }
            else if(A[i]>A[i+1])
            {
                if(length>1)
                {
                    climb=false;
                    length++;
                    res=max(res,length);
                }
                else
                {
                    climb=true;
                    length=1;
                }
                
            }
            else if(A[i]==A[i+1])
            {
                if(climb==false)
                {
                    i--;
                }
                length=1;
                climb=true;
            }

        }
        return res>2?res:0;


    }
};

/*
Link: https://leetcode-cn.com/problems/longest-mountain-in-array/
date: 2020/10/25
Author: qingfu
*/