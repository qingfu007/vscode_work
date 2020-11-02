#include<vector>
#include<stack>
#include<iostream>
#include<algorithm>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)   return res;
        stack<TreeNode*> temp;
        temp.push(root);
        while(!temp.empty())
        {
            TreeNode* cur=temp.top();
            temp.pop();
            res.push_back(cur->val);
            if(cur->right) temp.push(cur->right);
            if(cur->left)  temp.push(cur->left);
        }
        return res;

        
    }
};

class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)   return res;
        stack<TreeNode*> temp;
        TreeNode* cur;
        temp.push(root);
        while(!temp.empty())
        {
            cur=temp.top();
            if(cur!=nullptr)
            {
                temp.pop();
                if(cur->right)   temp.push(cur->right);
                if(cur->left)    temp.push(cur->left);
                temp.push(cur);
                temp.push(nullptr);
            }
            else
            {
                temp.pop();
                cur=temp.top();
                temp.pop();
                res.push_back(cur->val);
                
            }
            

        }
        return res;

        
    }
};



/*
Link: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
date: 2020/10/27
Author: qingfu
*/