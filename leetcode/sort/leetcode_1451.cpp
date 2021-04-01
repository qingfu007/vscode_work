#include<headfile.h>

using namespace std;
class Solution {
public:
    string arrangeWords(string text) {
        //字符串流
        stringstream ss(text);
        vector<string> words;
        string temp;
        while(ss>>temp){
            words.push_back(temp);
            
        }
        if(!words.empty()){
            words[0][0]=tolower(words[0][0]);
        }
        stable_sort(words.begin(),words.end(),[](const string&s1,const string&s2){
            return s1.length()<s2.length();
        });
        string res;
        for(auto& s:words){
            res+=(s+" ");
        }
        if(!res.empty()){
            res[0]=toupper(res[0]);
        }
        res.pop_back();
        return res;
        
        

    }
};
    




/*
Link: https://leetcode-cn.com/problems/rearrange-words-in-a-sentence/
date: 2020/11/13
Author: qingfu
*/