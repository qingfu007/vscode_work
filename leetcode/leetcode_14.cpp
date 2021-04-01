#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string comp=strs[0];
        for(int i=0;i<strs.size();++i){
            comp=comString(comp,strs[i]);
            if(comp.empty()) break;
        }
        return comp;
        

    }
    string comString(const string& str1,const string& str2){
        int i;
        for(i=0;i<str1.size()&&i<str2.size();++i){
            if(str1[i]!=str2[i]) break;
        }
        return str1.substr(0,i);

    }
};

/*
Link: https://leetcode-cn.com/problems/longest-common-prefix/
date: 2020/11/28
Author: qingfu
*/