#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_set>


using namespace std;

namespace count_sort{
class Solution {
public:
    string reorganizeString(string S) {
        int n=S.length();
        vector<int> counts(26,0);

        for(auto c:S){
            counts[c-'a']+=100;
        }
        for(int i=0;i<26;++i){
            counts[i]+=i;
        }

        sort(counts.begin(),counts.end());

        string res(n,' ');
        int index=1;
        for(const auto code:counts)
        {
           int count=code/100;
           char curchar='a'+code%100;    //重复次数*100，然后加上当前下标i,既可以保存重复次数信息，也可以在排序后直到下标。。思想：编码？？？
           if(count>(n+1)/2) return "";

           for(int i=0;i<count;++i){
               if(index>=n) index=0;   //达不到n;最多n-1.
               res[index]=curchar;
               index+=2;
           }
        }
        return res;
    }
};
}


namespace priority{
struct cmp
{	
	bool operator()(pair<char,int>& a, pair<char,int>& b)
	{
		return a.second < b.second;//数量多的优先
	}
};
	// bool operator<(pair<char,int>& a, pair<char,int>& b)
	// {
	// 	return a.second < b.second;//数量多的优先
	// }
class Solution {
public:
    string reorganizeString(string S) {
    	int maxcount = 0;
    	vector<int> count(26, 0);
    	for(char c : S)
    	{
    		count[c-'a']++;
    		maxcount = max(maxcount, count[c-'a']);
    	}
    	if(maxcount > (S.size()+1)/2)
    		return "";
    	priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> q;
    	for(int i = 0; i < 26; ++i)
    	{
    		if(count[i]>0)
    			q.push({'a'+i, count[i]});
    	}
    	string ans;
    	while(q.size() >= 2)
    	{
    		vector<pair<char,int>> tmp;
    		int dis = 2;
    		while(dis--)
    		{
    			auto tp = q.top();
	    		q.pop();
	    		char c = tp.first;
	    		int num = tp.second;
	    		ans += c;
	    		num--;
	    		if(num > 0)
	    			tmp.push_back({c, num});
	    	}
	    	for(auto& p : tmp)
	    		q.push(p);
    	}
    	while(!q.empty())
    	{
    		if(q.top().second == 1)
    		{
    			ans += q.top().first;
    			q.pop();
    		}
    		else
    			return "";
    	}
    	return ans;
    }
};

}

/*
Link: https://leetcode-cn.com/problems/single-number/
date: 2020/10/24
Author: qingfu
*/