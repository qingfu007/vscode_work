#include<vector>
#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#include<unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode dummyhead(0);
        dummyhead.next=head;
        auto p=head;
        int length=0;
        while(p)
        {
            ++length;
            p=p->next;
        }
        for(int size=1;size<length;size<<=1){
            auto cur =dummyhead.next;
            auto tail=&dummyhead;
            while(cur)
            {
                ListNode* left=cur;
                ListNode* right=cut(left,size);
                cur=cut(right,size);
                tail->next=merge(left,right);
                while(tail->next)
                {
                    tail=tail->next;
                }
            }
        }
        return dummyhead.next;
    }
    ListNode* cut(ListNode* head,int n)
    {
        ListNode* p=head;
        while(--n&&p)
        {
            p=p->next;
        }
        if(p==nullptr) return nullptr;
        ListNode* next=p->next;
        p->next=nullptr;
        return next;
    }

    ListNode* merge(ListNode* left,ListNode* right)
    {
        ListNode dummpyhead(-1);
        ListNode* p=&dummpyhead;
        while(left&&right)
        {
            if(left->val<right->val)
            {
                p->next=left;
                p=p->next;
                left=l1->next;

            }
            else
            {
                p->next=right;
                p=p->next;
                right=right->next;
            }
            
        }
        p->next=left==nullptr?right:left;
        return dummpyhead.next;
    }
};

/*
Link: :https://leetcode-cn.com/problems/sort-list/
date: 2020/10/28
Author: qingfu
*/