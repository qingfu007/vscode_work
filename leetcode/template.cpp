#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if(K>=points.size()){
            return points;
        }else if(K<=0){
            return {};
        }else
        {
            int low=0,high=points.size()-1;
            while(true){
                int j =partition(points,low,high);
                if(j==K) break;
                else if(j>K) high=j-1;
                else low=j+1;
            }
            return {points.begin(),points.begin()+K};
        }
    }
    // int partition(vector<vector<int>>& nums,int low,int high)
    // {
    //     int i=low,j=high+1;
    //     int v=nums[low][0]*nums[low][0]+nums[low][1]*nums[low][1];
    //     while(i<j){
    //         while((i++)<j&&nums[j][0]*nums[j][0]+nums[j][1]*nums[j][1]>=v); 
    //         while(i<(j--)&&nums[i][0]*nums[i][0]+nums[i][1]*nums[i][1]<v);      
    //         if(i<j) swap(nums[i],nums[j]);
    //     }
    //     swap(nums[low],nums[j]);
    //     return j;
    // }
        int partition(vector<vector<int>>& nums,int low,int high)
    {
        int i=low+1,j=high;
        int v=nums[low][0]*nums[low][0]+nums[low][1]*nums[low][1];
        while(true){
            while(i<=high&&(nums[i][0]*nums[i][0]+nums[i][1]*nums[i][1]<v)) i++;
            while(j>=low&&(nums[j][0]*nums[j][0]+nums[j][1]*nums[j][1]>=v)) j--;       
            if(i>j) break;
             swap(nums[i],nums[j]);
             i++;
             j--;
        }
        swap(nums[low],nums[j]);
        return j;

    }
};

int main(){
    vector<vector<int>> points={{1,3},{-2,2}};
    vector<vector<int>> res;
    Solution solution;
    res=solution.kClosest(points,1);

    cout<<"end";

    system("pause");
    return 0;


}

/*
Link: https://leetcode-cn.com/problems/single-number/
date: 2020/10/24
Author: qingfu
*/