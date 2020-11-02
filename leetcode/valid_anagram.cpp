#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};

/*
Link: https://leetcode-cn.com/problems/valid-anagram/
date: 2020/10/27
Author: qingfu
*/