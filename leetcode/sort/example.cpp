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

 //   Solution():nums({}){}
 //   Solution(const vector<int>&);

    //选择排序
    vector<int> select_sort(vector<int>& nums){ 
        int N=nums.size();
        for(int i=0;i<N;++i){
            int nmin=i;
            for(int j=i+1;j<N;++j){
                if(nums[j]<nums[nmin]) nmin=j;
            }
            swap(nums[i],nums[nmin]);
        }
        return nums;
    }



    //插入排序
    vector<int> insert_sort(vector<int>& nums){
        int N=nums.size();
        for(int i=1;i<N;++i){
            for(int j=i;j>0&&nums[j]<nums[j-1];--j){
                swap(nums[j],nums[j-1]);
            }
        }
        return nums;
    }
    //希尔排序
    vector<int> shell_sort(vector<int>& nums){
        int N=nums.size();
        int h=1;
        while(h<N/3) h=3*h+1;
        while(h>=1)
        {
            for(int i=h;i<N;++i){
                for(int j=i;j>=h&&nums[j]<nums[j-h];j-=h){
                    swap(nums[j],nums[j-h]);
                }
            }
            h=h/3;
        }
        return nums;
    }


    //归并排序
    void merge_sort(vector<int>& nums,int left,int right)
    {
        if(left<=right) return;
        int mid=(left+right)/2;
        merge_sort(nums,left,mid);
        merge_sort(nums,mid+1,right);

        //归并两个数组
        vector<long> mergred(right-left+1);
            int p1=left,p2=mid+1;
            int p=0;
            while(p1<=mid||p2<=right)
            {
                if(p1>mid){
                    mergred[p++]=nums[p2++];
                }
                else if(p2>right){
                    mergred[p++]=nums[p1++];
                }
                else{
                    if(nums[p1]<nums[p2]){
                        mergred[p++]=nums[p1++];
                    }
                    else{
                        mergred[p++]=nums[p2++];
                    }
                }                
            }
            for(int i=0;i<mergred.size();i++){
                nums[left+i]=mergred[i];
            }
            return;
    }

    //快速排序
    void quick_sort(vector<int>& nums ,int low,int high)
    {
        if(low>=high) return;
        int j =partition(nums,low,high);
        quick_sort(nums,low,j-1);
        quick_sort(nums,j+1,high);
        return;
    }
    // int partition(vector<int>& nums,int low,int high)
    // {
    //     int i=low+1,j=high;
    //     int v=nums[low];
    //     while(i<j){
    //         while(i<j&&nums[j]>v) --j;
    //         while(i<j&&nums[i]<=v) ++i;
             
      
            
    //         if(i<=j) swap(nums[i],nums[j]);
    //     }
    //     swap(nums[low],nums[j]);
    //     return j;

    // }
    // int partition(vector<int>& nums,int low,int high)
    // {
    //     int i=low,j=high+1;
    //     int v=nums[low];
    //     while(i<j){
    //         while(i<j&&nums[--j]>=v); 
    //         while(i<j&&nums[++i]<v);      
    //         if(i<j) swap(nums[i],nums[j]);
    //     }
    //     swap(nums[low],nums[j]);
    //     return j;
    // }
    int partition(vector<int>& arr, int left, int right) {
        int pivot = left;
        int v=arr[left];
        int lt = left + 1;
        int gt = right;
        while (true) {
            while (lt <= right && arr[lt] < v) lt++;
            while (gt >= left && arr[gt] > v) gt--;
            if (lt > gt) break;
            swap(arr[lt], arr[gt]);
            lt++;
            gt--;
        }
        swap(arr[pivot], arr[gt]);
        return gt;
    }
//private:
 //   vector<int> nums;
};

int main(){
    vector<int> nums={1,2,3,4,5,6,7,8,7,6,5,4,3,2,1,3,2,5,7,4,7,4,7,3,6,3,1,5,3,3,1,4,4,5,5,78,9,0,5,0,0,0,0,0,0,0,3,3,3,3,3};
    int n=nums.size();
//    Solution exam(nums);

    vector<int> nums1(nums);
    sort(nums1.begin(),nums1.end());
    cout<<"sort ok!"<<endl;

    vector<int> nums2(nums);
    Solution solution;
    nums2=solution.select_sort(nums2);
    cout<<"select_sort ok!"<<endl;

    vector<int> nums3(nums);
    solution.merge_sort(nums3,0,n-1);
    cout<<"merge_sort ok!"<<endl;

    vector<int> nums4={2,1,1,2,1,3,1};
    int n1=nums4.size()-1;
    solution.quick_sort(nums4,0,n1);
    cout<<"quick_sort ok!"<<endl;

    cout<<"output"<<endl;
    system("pause");
    return 0;
}

/*
Link: https://leetcode-cn.com/problems/single-number/
date: 2020/10/24
Author: qingfu
*/