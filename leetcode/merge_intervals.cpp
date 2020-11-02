#include<vector>
#include<iostream>
#include<algorithm>


using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int> >& intervals) {
        //similar to video_stitching
        //排序，合并，输出！
        vector<vector<int> > res;
        if(intervals.size()==0||intervals[0].size()==0) return res;
        sort(intervals.begin(), intervals.end()); //二维数组的左快排
        for(int i=0;i<intervals.size();i++)
        {
            int L=intervals[i][0],R=intervals[i][1];
            if(res.size()==0) res.push_back(intervals[i]);
            if(res.back()[1]<L) res.push_back(intervals[i]);
            else
            {
                res.back()[1]=max(res.back()[1],R);
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> input={{1,3},{2,6},{8,10},{15,18}},output;
    Solution answer;
    int s=0;
    vector<int> a={1,2,3,4};
    output=answer.merge(input);

 //   cout<<"input"<<endl;
    int pause;
    cin >> pause;
    return 0;


}

/*
Link: https://leetcode-cn.com/problems/merge-intervals/
date: 2020/10/24
Author: qingfu
*/