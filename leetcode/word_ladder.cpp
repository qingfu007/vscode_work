#include <string>
#include <iostream>
#include <vector>
#include<unordered_set>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    //单向bfs
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(),wordList.end());

        queue<pair<string,int>>   q;

        q.push({beginWord,1});
        while(!q.empty()){
            if(q.front().first==endWord) return q.front().second;

            string tmp=q.front().first;
            int count=q.front().second;
            q.pop();

            char ch;
            for(int i=0;i<tmp.length();++i){
                ch=tmp[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    //从'a'-'z'尝试一次
                    if ( ch == c) continue;
                    tmp[i] = c ;
                    //如果找到的到
                    if (  dict.find(tmp) != dict.end() ){
                        q.push({tmp, count+1});
                        dict.erase(tmp) ; //删除该节点
                    }
                tmp[i] = ch; //复原
                }
            }
        }
        return 0;
    }
};
namespace bfs1{

class Solution {
public:
    unordered_map<string, int> wordId;  //用Id代替word能够节省空间。
    vector<vector<int>> edge;
    int Id = 0;

    void addWord(string& word) {
        if (!wordId.count(word)) {
            wordId[word] = Id++;
            edge.emplace_back();
        }
    }

    void addEdge(string& word) {
        addWord(word);
        int id1 = wordId[word];
        for (char& it : word) {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (string& word : wordList) {
            addEdge(word);
        }
        addEdge(beginWord);
        if (!wordId.count(endWord)) {
            return 0;
        }
        vector<int> path(Id, INT_MAX);
        int beginId=wordId[beginWord],endId=wordId[endWord];
        path[beginId]=0;

        queue<int> q;
        q.push(beginId);
        while(!q.empty())
        {
            for(int t=q.size();t>0;--t)
            {
                int cur=q.front();
                q.pop();
                if(cur==endId) return path[endId]/2+1;

                for(int& it:edge[cur])  //对于x所连接的点，如果未访问过，则路径值加一保存
                {
                    if(path[it]==INT_MAX)
                    {
                        path[it]=path[cur]+1;
                        q.push(it);
                    }
                }
            }
        }
        return 0;


    }

};


}

namespace bfs2{
    
    //双向bfs思路，使用两个队列进行迭代。顺着遍历+反着遍历。层次化（for循环当前队列所有元素）

class Solution {
public:
    unordered_map<string, int> wordId;  //用Id代替word能够节省空间。
    vector<vector<int>> edge;
    int Id = 0;

    void addWord(string& word) {
        if (!wordId.count(word)) {
            wordId[word] = Id++;
            edge.emplace_back();
        }
    }

    void addEdge(string& word) {
        addWord(word);
        int id1 = wordId[word];
        for (char& it : word) {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for (string& word : wordList) {
            addEdge(word);
        }
        addEdge(beginWord);
        if (!wordId.count(endWord)) {
            return 0;
        }
        //正向bfs
        vector<int> path1(Id, INT_MAX);
        int beginId=wordId[beginWord];
        path1[beginId]=0;
        queue<int> q1;
        q1.push(beginId);


        //反向bfs
        vector<int> path2(Id, INT_MAX);
        int endId=wordId[endWord];
        path2[endId]=0;

        queue<int> q2;
        q2.push(endId);



        while(!q1.empty()&&!q2.empty())
        {
            for(int t=q1.size();t>0;--t)
            {
                int cur=q1.front();
                q1.pop();
                // if(cur==endId) return path1[endId]/2+1;
                if(path2[cur]!=INT_MAX) return (path1[cur]+path2[cur])/2+1;

                for(int& it:edge[cur])  //对于x所连接的点，如果未访问过，则路径值加一保存
                {
                    if(path1[it]==INT_MAX)
                    {
                        path1[it]=path1[cur]+1;
                        q1.push(it);
                    }
                }
            }
            for(int t=q2.size();t>0;--t)
            {
                int cur=q2.front();
                q2.pop();
                // if(cur==beginId) return path1[endId]/2+1;
                if(path1[cur]!=INT_MAX) return (path1[cur]+path2[cur])/2+1;


                for(int& it:edge[cur])  //对于x所连接的点，如果未访问过，则路径值加一保存
                {
                    if(path2[it]==INT_MAX)
                    {
                        path2[it]=path2[cur]+1;
                        q2.push(it);
                    }
                }
            }
        }
        return 0;


    }

    //双向bfs思路，使用两个队列进行迭代。顺着遍历+反着遍历。层次化（for循环当前队列所有元素）
};


}




/*
Link: https://leetcode-cn.com/problems/word-ladder/
date: 2020/11/05
Author: qingfu
*/

