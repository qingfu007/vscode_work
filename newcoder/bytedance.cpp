
namespace demo1{
#include<iostream>
#include<string>
#include<vector>
using namespace std;
 
int main()
{
    int n=0;
    cin>>n;
    vector<string> s;
    for(int i=0;i<n;++i){
        string input;
        cin>>input;
        s.push_back(input);      
    }
    vector<string> res;
    for(int i=0;i<n;++i){
        string temp;
        int j=0;
        while(j<s[i].size()){
            if(temp.size()<2){
                temp+=s[i][j];
            }
            else{
                int m=temp.size();
                if(s[i][j]==temp[m-1])
                {
                    if(temp[m-1]==temp[m-2]){
                        ++j;
                        continue;
                    }
                    if(m>=3&&temp[m-2]==temp[m-3]){
                        ++j;
                        continue;
                    }
                    temp+=s[i][j];
                }
                else{
                    temp+=s[i][j];
                }
                 
            }
            ++j;
        }
        res.push_back(temp);
         
    }
    for(int i=0;i<res.size();++i){
        cout<<res[i]<<endl;
    }
     
    return 0;
}

}
namespace demo2{
//总共3名特工，故确定右侧节点的情况下，寻找最左侧的情况。然后从j-i个数据中选择2个（组合数）
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,D;
    cin>>N;
    cin>>D;
    vector<int> vec(N);
    for(int i=0;i<N;++i){
        cin>>vec[i];
    }
    long res=0;
    int i=0;
    for(int j=0;j<N;++j){
        if(j<2){
            continue;
        }
        while(j-i>2&&vec[j]-vec[i]>D){//i到j的距离大于3且两数之差大于D，则循环
            ++i;
        }
        if(j-i>=2&&vec[j]-vec[i]<=D){ //i到j之间至少有3个元素，且，距离之差小于等于D.从j-i个元素中选2个。
            res=res+((long)(j-i)*(long)(j-i-1)/2);   
            res=res%99997867;
        }
    }
    cout<<res<<endl;
    return 0;
}
}

namespace demo3{
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> count(9,0);
    for(int i=0;i<13;++i){
        int tmp;
        cin>>tmp;
        ++count[tmp-1];
    }
    vector<int> res;
    for(int i=1;i<=9;++i){
        if(count[i-1]>=4) continue;
        for(int j=0;j<9;++j){
            vector<int> temp(count);
            ++temp[i-1];
            int sum=0;
            int k=0;
            if(temp[j]<2){
                continue;
            }
            temp[j]-=2;
            while(k<9){
                if(temp[k]>=3){
                    temp[k]-=3;
                    ++sum;
                }
                while(k<7&&temp[k]>0&&temp[k+1]>0&&temp[k+2]>0){
                    ++sum;
                    --temp[k];
                    --temp[k+1];
                    --temp[k+2];
                }
                ++k;
            }
            if(sum==4){
                res.push_back(i);
            }
        }
    }
    if(res.empty()){
        cout<<0<<endl;
        return 0;
    }
    for(const auto c:res){
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;
}    
}

namespace demo4{

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include<utility>

using namespace std;

int main(){
    int N;
    int res=0;
    cin>>N;
    while(N--){
        int M;
        cin>>M;
        map<pair<int,int>,int>count;
//        unordered_set<pair<int,int> pre;
        for(int i=0;i<M;++i){
            int len;
            cin>>len;
            set<pair<int,int>> s;
            for(int i=0;i<2*len;i+=2){
                int a,b;
                cin>>a>>b;
                auto k=make_pair(a,b);
                s.insert(k);
                if(count.find(k)==count.end()){
                    count[k]=0;
                }
            }
            for(auto &u:count){
                if(s.find(u.first)==s.end()){
                    res=max(res,u.second);
                    u.second=0;
                    
                }
                else{
                    u.second++;
                }
            }
        }
        
        for(auto &u:count){
            res=max(res,u.second);
        }
        cout<<res<<endl;
    }
    
    return 0;
}
}

namespace demo5{

#include <iostream>
#include <vector>

using namespace std;

int minPath=INT_MAX;
int visited=0;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> edge(n,vector<int>(n,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>edge[i][j];
        }
    }
    vector<int> mark(n,0);
    dfs(0,0);
    return minPath;

}

void dfs(int cur,int dst){
    if(dst>minPath) return;
    if(visited==n){
        if(dst<minPath) minPath=dst;
        return;
    }
    else{
        for(int i=0;i<n;++i){
            if(mark[i]==0&&edge[cur][i]!=0){
                mark[i]=1;
                visited++;
                dfs(i,dst+edge[cur][i]);
                visited--;
                mark[i]=0;
            }
        }
    }

}

}