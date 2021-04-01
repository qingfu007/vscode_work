#include<headfile.h>

using namespace std;

//贪心，结束时间早的能先参加就先参加！！！
namespace baotanxin{
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if(events.size()==0) return 0;
        //先排序，排序后递归？动归？//贪心。//超时
        sort(events.begin(),events.end(),[](const vector<int>& num1,const vector<int>& num2){
           return num1[1]<num2[1];
        });
        int res=0;
        unordered_set<int> flag;
        for(int i=0;i<events.size();++i)
        {
            for(int j=events[i][0];j<=events[i][1];++j){
                if(flag.find(j)==flag.end()){
                    res++;
                    flag.insert(j);
                    break;
                }
            }
          
        }
        return res;
    }
};

}

namespace youxianduilie{

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),[](const vector<int>& num1,const vector<int>& num2){ return num1[1]<num2[1];});
        priority_queue<int,vector<int>,greater<int>> pq;
        int res=0,last=1,i=0,n=events.size();  //结果，会议开始时间，优先队列里存的是同一天开始的会议，最早结束的排在最上面。
        while(i<n||!pq.empty()){
            while(i<n&&events[i][0]==last){
                pq.push(events[i++][1]);
            }

            while(!pq.empty()&&pq.top()<last){
                pq.pop();
            }

            if(!pq.empty()){
                pq.pop();
                res++;
            }
            last++;
        }
        return res;

    }
};
}

namespace set{
class Solution {
public:
    #define N 100010
    #define MP make_pair
    multiset<pair<int,int> >S;
    vector<int>in[N],out[N];
    int maxEvents(vector<vector<int>>& events) {
        int mx=0,cnt=0;
        for (auto x:events){
            int l=x[0],r=x[1];
            mx=max(mx,r);
            in[l].push_back(cnt);
            out[r+1].push_back(cnt);
            cnt++;
        }
        int ans=0;
        for (int i=1;i<=mx;++i){
            for (auto x:in[i]) S.insert(MP(events[x][1],x));
            for (auto x:out[i]){
                auto it=S.find(MP(events[x][1],x));
                if (it!=S.end()) S.erase(it);
            }
            if (!S.empty()){
                S.erase(S.begin());
                ans++;
            }
        }
        return ans;
    }
};
}
    




/*
Link: https://leetcode-cn.com/problems/rearrange-words-in-a-sentence/
date: 2020/11/13
Author: qingfu
*/