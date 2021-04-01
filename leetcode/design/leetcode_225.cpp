#include<bits/stdc++.h>
using namespace std;
class MyStack {
public:

//设计思路：两个队列，一个存top（queue1)，另一个存剩余元素(queue2)。
//入栈，queue1入队
//出栈，queue1不为空：入队，出队。queue1空，queue2不为空，queue2出队
    /** Initialize your data structure here. */
    MyStack() {
        

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int n=q.size();
        q.push(x);
        for(int i=0;i<n;++i){
            q.push(q.front());
            q.pop();
        }

    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res=q.front();
        q.pop();
        return res;

    }
    
    /** Get the top element. */
    int top() {
        int res=q.front();
        return res;

    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();

    }

private:
    queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/*
Link: https://leetcode-cn.com/problems/maximum-gap/
date: 2020/11/26
Author: qingfu
*/