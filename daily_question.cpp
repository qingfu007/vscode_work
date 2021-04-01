#include<bits/stdc++.h>
 
using namespace std;
/********************************************
title:  每日一题
author: qingfu2020

********************************************/
/*
link:   https://leetcode-cn.com/problems/word-pattern/
date:   2020/12/16
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        //哈希表。每个字母对应专属单词。
        unordered_map<char,string> mp;
        unordered_set<string> comp;
        istringstream buf(s);
        string temp;
        int idx=0;
        int len=pattern.size();
        while(buf>>temp){
            if(idx>=len) return false;
            char cur=pattern[idx];
            if(mp.find(cur)==mp.end()){
                mp[cur]=temp;
                if(comp.find(temp)!=comp.end()){ 
                    return false;
                }
                else{
                    comp.insert(temp);
                }
                
            }
            else{
                if(mp[cur]!=temp){
                    return false;
                }
            }
            idx++;
        }
        return idx==len;       
    }
};

/*
linK:https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
date:2020/12/17
*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
        //dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);

        //简化：dp0=max(dp0,dp1+prices[i]-fee);dp[1]=max(dp1,dp0_brfore-prices[i]); 
        int dp0=0;
        int dp1=-50000;
        for(const auto& price:prices){
            int dp0_before=dp0;
            dp0=max(dp0,dp1+price-fee);
            dp1=max(dp1,dp0_before-price);
        }
        return dp0;

    }
};
class Solution {
public:
    //贪心解法：仅供参考。收益为正时候卖出。
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int buy = prices[0] + fee;
        int profit = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] + fee < buy) {//股票下跌，不买。
                buy = prices[i] + fee;
            }
            else if (prices[i] > buy) { //卖出一支股票时，我们就立即获得了以相同价格并且免除手续费买入一支股票的权力。
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        return profit;
    }
};

/*
link:https://leetcode-cn.com/problems/find-the-difference/
date:2020/12/18
*/

//idiot用哈希表，可以计数。可以求和取差值。可以合并进行位运算!!!!!!
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        for(const auto& c:s){
            mp[c]++;
        }
        for(const auto& c:t){
            if(mp.find(c)==mp.end()||mp[c]==0){ 
                return c;
            }
            else{
                --mp[c];

            }
        }
        return '0';


    }
};


/*
link:https://leetcode-cn.com/problems/rotate-image/
date:2020/12/19
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return;
        int n=matrix.size();
        for(int i=0;i<n;++i){
            for(int j=0;i<i;++j){
                swap(matrix[i][j],matrix[j][i]);                
            }
        }
        for(int j=0;j<n/2;++j){
            for(int i=0;i<n;++i){
                swap(matrix[i][j],matrix[i][n-j]);                
            }
        }
        return;
        
    }
};

/*
link:https://leetcode-cn.com/problems/remove-duplicate-letters/
date:2020/12/20
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        //统计元素种类，计算可删除个数。
        //每次遇到新元素，比栈顶小的时候，后面还有栈顶就把栈顶排后面去（删了这个）
        string temp;
        vector<int> visit(26),nums(26);
        for(char ch:s){
            nums[ch-'a']++;
        }

        string str;
        for(const auto& c:s){
            if(!visit[c-'a']){
                while(!str.empty()&&str.back()>c){
                    if(nums[str.back()-'a']>0){
                        visit[str.back()-'a']=0;
                        str.pop_back();
                    }
                    else{
                        break;
                    }
                }
                visit[c-'a']=1;
                str.push_back(c);
            }
            nums[c-'a']-=1;
        }
        return str;
        

    }
};



/*
link:https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/solution/
date:2020/12/22
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> q;
        
        q.push(root);
        int flag=0;
        int n;
        while(!q.empty()){
            n=q.size();
            vector<int> cur;
            while(n--){
                TreeNode* temp=q.front();
                cur.push_back(temp->val);
                q.pop();
                if(temp->left){ 
                    q.push(temp->left);
                }
                if(temp->right){ 
                    q.push(temp->right);
                }
            }
            if(flag) reverse(cur.begin(),cur.end());
            res.push_back(cur);                       
        }
        return res;
        
    }
};

/*
link:https://leetcode-cn.com/problems/candy/
date:2020/12/24
*/

//核心在于问题的分解，将规则划分为左规则与右规则。
//左规则：当r[i-1]<r[i]，left[i]=left[i-1]+1;否则left[i]=1;
//右规则：当r[i]>r[i+1],right[i]=righe[i+1]+1;否则right[i]=1;

class Solution {
public:
    int candy(vector<int>& ratings) {
        //贪心。
        int n=ratings.size();
        vector<int> left(n);
        for(int i=0;i<n;++i){
            if(i>0&&ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
            else{
                left[i]=1;
            }
        }
        int right=0,res=0;
        for(int i=n-1;i>=0;--i){
            if(i<n-1&&ratings[i]>ratings[i+1]){
                right++;
            }
            else{
                right=1;
            }
            res+=max(left[i],right);
        }
        return res;

    }
};

/*
link:https://leetcode-cn.com/problems/candy/
date:2020/12/25
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // unordered_map<int,int> m;
        // for(const auto c:s){
        //     m[c]++;
        // }
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        int l1=g.size(),l2=s.size();
        while(i<l1&&j<l2){
            if(g[i]<=s[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i;

    }
};

/* 
link:https://leetcode-cn.com/problems/largest-rectangle-in-histogram/solution/
date:?????
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int res=0;
        for(int mid=0;mid<n;++mid){
            int height=heights[mid];
            int left=mid,right=mid;
            while(left >0 && heights[left-1]>=height){
                --left;
            }
            while(right<n-1 && heights[right+1]>=height){
                ++right;
            }
            res=max(res,(right-left+1)*height);
        }
        return res;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int res=0;
        for(int left=0;left<n;++left){
            for(int right=left;right<n;++right){
                int minHeight=*min_element(heights.begin()+left,heights.begin()+right+1);
                res=max(res,(right-left+1)*minHeight);
            }
        }
        return res;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> left(n),right(n);

        stack<int> s;
        for(int i=0;i<n;++i){
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            left[i]=(s.empty()?-1:s.top());
            s.push(i);
        }
        
        s=stack<int>();
        for(int i=n-1;i>=0;--i){
            while(!s.empty()&&heights[s.top()]>=heights[i]){
                s.pop();
            }
            right[i]=(s.empty()?-1:s.top());
            s.push(i);
        }
        int res=0;
        for(int i=0;i<n;++i){
            res=max(res,(right[i]-left[i]-1)*heights[i]);
        }
        return res;
    }
};

/*
link: https://leetcode-cn.com/problems/maximal-rectangle/
date:2020/12/26
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return 0;
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> left(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    left[i][j]=matrix[i][j]-'0';
                }
                else{
                    left[i][j]=(matrix[i][j]=='1'?left[i][j-1]+1:0);
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0'){
                    continue;
                }
                int width=left[i][j];
                int area=width;
                for(int k=i-1;k>=0;k--){
                    width=min(width,left[k][j]);
                    area=max(area,(i-k+1)*width);
                }
                res=max(area,res);                
            }
        }
        return res;
    }
};

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(m==0){
            return 0;
        }
        int n=matrix[0].size();
        vector<vector<int>> height(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    height[i][j]=(i==0?0:height[i-1][j])+1;  //计算每一行的柱状图高度
                }
            }
        }

        int res=0;
        for(int i=0;i<m;++i){
            vector<int> left(n),right(n,n);
            stack<int> s;
            for(int j=0;j<n;++j){
                while(!s.empty()&&height[i][s.top()]>=height[i][j]){
                    right[s.top()]=j;
                    s.pop();
                }
                left[j]=(s.empty()?-1:s.top());
                s.push(j);
            }
            for(int j=0;j<n;++j){
                int w=right[j]-left[j]-1;
                int area=w*height[i][j];
                res=max(res,area);
            }

        }
        return res;
    }
};

/* 
link:https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/
date:2020/12/28
*/

// dp[k][0]=max(dp[k][0],dp[k][1]+prices[i]);
// dp[k][1]=max(dp[k][1],dp[k-1][0]-prices[i]);
// dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i]);
// dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]);

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(k>n/2+1) return maxProfit(n/2+1,prices);
        vector<vector<int>> dp(k,vector<int>(2,INT_MIN));
        for(int i=0;i<k;++i){
            dp[i][0]=0;
        }
        for(const int& price:prices){
            for(int j=k-1;j>=0;--j){
                dp[j][0]=max(dp[j][0],dp[j][1]+price);
                if(j>0){
                    dp[j][1]=max(dp[j][1],dp[j-1][0]-price);
                }
                else{
                    dp[j][1]=max(dp[j][1],-price);
                }
            }
        }
        return dp[k-1][0];
    }
};

/*
link:https://leetcode-cn.com/problems/evaluate-division/
date:2021/01/06
*/
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars=0;
        unordered_map<string,int> variables;
        for(const auto&equation:equations){
            if(variables.find(equation[0])==variables.end()){
                variables[equation[0]]=nvars++;
            }
            if(variables.find(equation[1])==variables.end()){
                variables[equation[1]]=nvars++;
            }            
        }
        int n=equations.size();
        vector<vector<pair<int,double>>> edges(nvars);
        for(int i=0;i<n;++i){
            int var1=variables[equations[i][0]];
            int var2=variables[equations[i][1]];
            edges[var1].push_back(make_pair(var2,values[i]));
            edges[var2].push_back(make_pair(var1,1.0/values[i]));
        }

        vector<double> res;

        for(const auto&query:queries){
            if(variables.find(query[0])==variables.end()||variables.find(query[1])==variables.end()){
                res.push_back(-1.0);
            }
            else{
                double result=-1.0;
                int var1=variables[query[0]];
                int var2=variables[query[1]];
                if(var1==var2){
                    res.push_back(1.0);
                    continue;
                }
                queue<int> q;
                q.push(var1);
                vector<double> rations(nvars,-1.0);
                rations[var1]=1.0;
                while(!q.empty()&&rations[var2]<0){
                    int x=q.front();
                    q.pop();
                    for(const auto & edge:edges[x]){
                        int y=edge.first;
                        double val=edge.second;
                        if(rations[y]<0){
                            rations[y]=rations[x]*val;
                            q.push(y);
                        }


                    }
                }
                result=rations[var2];
                res.push_back(result);
            }
        }
        return res;
    }
};

/*
link:https://leetcode-cn.com/problems/number-of-provinces/
date:2020/01/07
*/
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_set<int> visited;
        int res=0;
        int n=isConnected.size();
        for(int i=0;i<n;++i){
            if(visited.find(i)==visited.end()){
                visited.insert(i);
                res++;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int k=q.front();
                    q.pop();
                    for(int j=0;j<n;++j){
                        if(isConnected[k][j]==1&&visited.find(j)==visited.end()){
                            visited.insert(j);
                            q.push(j);
                        }                       
                    }
                }
            }
        }
        return res;
    }
};

/*
link:https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/
date:2020/01/09
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]+prices[i]);
        //dp[i][k][1]=max(dp[i-1][k][1],dp[i-1][k-1][0]-prices[i]);
        //dp[0][2][0]=0;
        //dp[0][2][1]=max(0,-prices[0]);
        //dp[0][1][0]=0;
        //dp[0][1][1]=max(0,-prices[0]);

        //dp20=max(dp20,dp21+price)
        //dp21=max(dp21,dp10-price)
        //dp10=max(dp10,dp11+price)
        //dp11=max(dp11,-price);

        int dp10=0,dp20=0;
        int dp11=INT_MIN,dp21=INT_MIN;
        for(const int& price:prices){
            dp20=max(dp20,dp21+price);
            dp21=max(dp21,dp10-price);
            dp10=max(dp10,dp11+price);
            dp11=max(dp11,-price);
        }
        return dp20;

    }
};


/*
link:https://leetcode-cn.com/problems/summary-ranges/
date:2020/01/10
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        vector<int> temp;
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(temp.empty()||nums[i]==nums[i-1]+1){
                temp.emplace_back(nums[i]);
            }
            else if((i>0&&nums[i]>1+nums[i-1])){
                if(temp.size()==1){
                    res.emplace_back(to_string(temp[0]));
                    temp.clear();
                    
                }
                else{
                    string s=to_string(temp.front())+"->"+to_string(temp.back());
                    res.emplace_back(s);
                    temp.clear();
                }
                temp.push_back(nums[i]);
            }
  
        }
        if(!temp.empty()){
            if(temp.size()==1){
                    res.emplace_back(to_string(temp[0]));
                    temp.clear();
                    
                }
                else{
                    string s=to_string(temp.front())+"->"+to_string(temp.back());
                    res.emplace_back(s);
                    temp.clear();
                }

        }
        return res;

    }
};

/*
link: https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column
date: 2021/01/29
*/
class Djset {
public:
    Djset():count(0){}
    int find(int x){
        if(parent.find(x)==parent.end()){
            parent[x]=x;
            rank[x]=1;
            count++;
        }
        return parent[x]==x?x:parent[x]=find(parent[x]);
    }
    int getCount(){
        return count;
    }
    void unionSet(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx==fy){
            return;
        }
        if(rank[fx]<rank[fy]){
            swap(fx,fy);
        }
        rank[fx]+=rank[fy];
        parent[fy]=fx;
        count--;
    }

private:
    unordered_map<int,int> parent,rank;
    int count;
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        Djset ds;
        for(const auto& stone:stones){
            ds.unionSet(stone[0]+10001,stone[1]);
        }
        return stones.size()-ds.getCount();

    }
};

/*
link:https://leetcode-cn.com/problems/swim-in-rising-water
date:2021/01/30
*/
class Unionfind {
public:
    int find(int x){
        if(parent.find(x)==parent.end()){
            parent[x]=x;
            rank[x]=1;
        }
        return parent[x]==x?x:parent[x]=find(parent[x]);
    }
    bool isConnected(int x,int y){
        return find(x)==find(y);
    }
    void unionSet(int x,int y){
        // int fx=find(x),fy=find(y);
        // if(fx==fy){
        //     return;
        // }
        if(isConnected(x,y)){
            return;
        }
        int fx=parent[x],fy=parent[y];
        if(rank[fx]<rank[fy]){
            swap(fx,fy);
        }
        rank[fx]+=rank[fy];
        parent[fy]=fx;
    }

private:
    unordered_map<int,int> parent,rank;
};
class Solution {

    constexpr static int DIRECTIONS[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
public:   
    int swimInWater(vector<vector<int>>& grid) {
        int N=grid.size();
        int len=N*N;
        vector<int> index(len);
        auto getIndex=[&](int i,int j){
            return i*N+j;
        };
        auto inArea=[&](int x,int y){
            return x>0&&x<N&&y>0&&y<N;
        };
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                index[grid[i][j]]=getIndex(i,j);               
            }
        }
        Unionfind unionfind;
        for(int i=0;i<len;i++){
            int x=index[i]/N;
            int y=index[i]%N;
            for(int k=0;k<4;k++){
                int newX=x+DIRECTIONS[i][0];
                int newY=y+DIRECTIONS[i][1];
                if(inArea(x,y)&&grid[newX][newY]<=i){
                    unionfind.unionSet(index[i],getIndex(newX,newY));
                }
                if(unionfind.isConnected(0,len-1)){
                    return i;
                }
            }
        }
        return -1;
    }
};

/*
link:https://leetcode-cn.com/problems/path-with-minimum-effort
date:2021/01/30
*/
/*union find*/
class UnionFind{
private:
    vector<int> parent;
    vector<int> rank;
    int n;
    int setCount;
public:
    UnionFind(int _n):n(_n),setCount(_n),parent(vector<int>(_n)),rank(_n,1){
         iota(parent.begin(), parent.end(), 0);
        
    }
    int find(int x){
        return parent[x]==x?x:parent[x]=find(parent[x]);
    }
    bool unionfind(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y){
            return false;
        }
        if(rank[x]<rank[y]){
            swap(x,y);
        }
        rank[x]+=rank[y];
        --setCount;
        return true;
    }
    bool isConnected(int x,int y){
        x=find(x);
        y=find(y);
        return x==y;
    }
};

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<tuple<int,int,int>> edges;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int id=i*n+j;
                if(i>0){
                    edges.emplace_back(id-n,id,abs(heights[i][j]-heights[i-1][j]));
                }
                if(j>0){
                    edges.emplace_back(id-1,id,abs(heights[i][j]-heights[i][j-1]));
                }
            }
        }

        sort(edges.begin(),edges.end(),[](const tuple<int,int,int>& e1,const tuple<int,int,int>& e2){
            // int x1,y1,v1,x2,y2,v2;
            // tie(x1,y1,v1)=e1;
            // tie(x2,y2,v2)=e2;
            int v1=get<2>(e1);
            int v2=get<2>(e2);
            return v1<v2;
        });
        UnionFind unionfind(m*n);
        int ans=0;
        for(const auto edge:edges){
            int x,y,z;
            tie(x,y,z)=edge;
            unionfind.unionfind(x,y);
            if(unionfind.isConnected(0,m*n-1)){
                ans=z;
                break;
            }
        }
        return ans;
    }
};

/*二分查找*/
class Solution {
        
    static constexpr int DIRECTIONS[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        int left=0,right=999999,ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            queue<pair<int,int>> q;
            q.emplace(0,0);
            vector<int> seen(m*n);
            seen[0]=1;
            while(!q.empty()){
                auto x=q.front().first;
                auto y=q.front().second;
                q.pop();
                for(int i=0;i<4;++i){
                    int nx=x+DIRECTIONS[i][0];
                    int ny=y+DIRECTIONS[i][1];
                    if(nx>=0&&nx<m&&ny>=0&&ny<n&&!seen[nx*n+ny]&&abs(heights[x][y] - heights[nx][ny]) <= mid){
                        q.emplace(nx,ny);
                        seen[nx*n+ny]=1;
                    }
                }
            }
            if(seen[m*n-1]){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans; 

    }
};

/*
link:https://leetcode-cn.com/problems/similar-string-groups
date:2021/01/31
*/

class Solution {
public:
    vector<int> parent;

    int find(int x){
        return parent[x]==x?x:parent[x]=find(parent[x]);
    }

    bool check(const string& a,const string &b,int len){
        int num=0;
        for(int i=0;i<len;i++){
            if(a[i]!=b[i]){
                ++num;
            }
            if(num>2) return false;
        }
        return true;
    }
    int numSimilarGroups(vector<string>& strs) {
        int m=strs.size();
        int n=strs[0].size();
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        for(int i=0;i<m;++i){
            for(int j=i+1;i<m;++j){
                int fi=find(i),fj=find(j);
                if(fi==fj){
                    continue;
                }
                if(check(strs[i],strs[j],n)){
                    parent[fi]=fj;
                }
            }
        }
        int res=0;
        for(int i=0;i<m;++i){
            if(parent[i]==i){
                ++res;
            }
        }
        return res;
    }
};

/*
link: https://leetcode-cn.com/problems/kth-largest-element-in-an-array
date: 2021/01/31
*/
class Solution {
public:

    void maxHeapify(vector<int>& a,int i,int heapSize){
        int l=i*2+1,r=i*2+2,largest=i;
        if(l<heapSize && a[l]>a[largest]){
            largest=l;
        }
        if(r<heapSize && a[r]>a[largest]){
            largest=r;
        }
        if(largest!=i){
            swap(a[i],a[largest]);
            maxHeapify(a,largest,heapSize);
        }
    }

    void buildMaxHeap(vector<int>& a,int heapSize){
        for(int i=heapSize/2;i>=0;--i){
            maxHeapify(a,i,heapSize);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize= nums.size();
        buildMaxHeap(nums,heapSize);
        for(int i=nums.size()-1;i>=nums.size()-k+1;--i){
            swap(nums[0],nums[i]);
            --heapSize;
            maxHeapify(nums,0,heapSize);
        }
        return nums[0];

    }
};


class Solution {
public:
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

class DualHeap{
private:
    //大根堆，维护较小一半元素
    priority_queue<int> small;
    //小根堆，维护较大一半元素
    priority_queue<int,vector<int>,greater<int>> large;
    //哈希表，记录延迟删除的元素：延迟删除，即记录该元素该删除次数，为堆顶的时候才删除
    unordered_map<int,int> delayed;

    int k;
    //small和large当前包含的元素个数，已经除去延迟删除的元素。
    //两个个数之和即为窗口大小，个数对应上时，如果堆顶元素不需要删除，那么可以延迟删除
    int smallSize,largeSize;

public:
    DualHeap(int _k): k(_k),smallSize(0),largeSize(0) {}

private:
    template<typename T>
    void prune(T& heap){
        while(!heap.empty()){
            int num=heap.top();
            if(delayed.count(num)){
                --delayed[num];
                if(!delayed[num]){
                    delayed.erase(num);
                }
                heap.pop();
            }
            else{
                break;
            }
        }
    }
    void makeBalance(){
        if(smallSize>largeSize+1){
            large.push(small.top());
            small.pop();
            --smallSize;
            ++largeSize;
            prune(small);
        }
        else if (smallSize < largeSize) {
            // large 比 small 元素多 1 个
            small.push(large.top());
            large.pop();
            ++smallSize;
            --largeSize;
            // large 堆顶元素被移除，需要进行 prune
            prune(large);
        }
    }

public:
    void insert(int num){
        if(!small.empty()||num<=small.top()){
            small.push(num);
            ++smallSize;
        }
        else{
            large.push(num);
            ++largeSize;
        }
        makeBalance();
    }

    void erase(int num){
        ++delayed[num];
        if(num<=small.top()){
            --smallSize;
            if(num==small.top()){
                prune(small);
            }
        }
        else{
            --largeSize;
            if(num==large.top()){
                prune(large);
            }
        }
        makeBalance();
    }

    double getMedian(){
        return k&1?small.top():((double)small.top()+large.top())/2;
    }
};

class Solution{
public:
    vector<double> medianSlidingWindow(vector<int>& nums,int k){
        DualHeap dh(k);
        for(int i=0;i<k;++i){
            dh.insert(nums[i]);
        }
        vector<double> res={dh.getMedian()};
        int n=nums.size();
        for(int i=k;i<n;++i){
            dh.insert(nums[i]);
            dh.erase(nums[i-k]);
            res.push_back(dh.getMedian());
        }
        return res;
    }

}; 