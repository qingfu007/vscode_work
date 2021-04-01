// #include <iostream>
// #include <vector>


// using namespace std;
// const int INF=2147483647;

// vector<vector<int>> edge;
// vector<vector<int>> dp;
// int n,m;
// void tsp(){
//     for(int i=0;i<n;++i){
//         dp[i][0]=edge[i][0];
//     }

//     for(int j=1;j<m;++j){
//         for(int i=0;i<n;++i){
//             // dp[i][j]=INF;

//             if(((j>>(i-1))&1)==1) continue; //集合中包含节点i。则跳过

//             for(int k=1;k<n;++k){
//                 if(((j>>(k-1))&1)==0) continue; //集合中不包含k点
//                 if( dp[i][j]> edge[i][k]+dp[k][j^(1<<(k-1))]){ //i经过j的集合回到0的最短路径>i经过k + k经过j集合（不包括k)回到0的最短路径
//                     dp[i][j]= edge[i][k]+dp[k][j^(1<<(k-1))];
//                 }
//             }
//         }
//     }
// }
// int main(){
//     cin>>n;
//     edge.resize(n,vector<int>(n,0));
//     for(int i=0;i<n;++i){
//         for(int j=0;j<n;++j){
//             cin>>edge[i][j];
//         }
//     } 
//     m=1<<(n-1);
//     dp.resize(n,vector<int>(m,INF));
//     tsp();
//     cout<<dp[0][m-1]<<endl;
//     system("pause");
    
//     return 0;
// }

//两个条件：总的能量不能小于0；半途中的能量不能小于0
//统计：所有路径的能量之和，--》每次跳跃之后所需能量
#include <iostream>
#include <vector>
// #define INT_MAX 2147483647
// #define INT_MIN -2147483648
using namespace std;

bool isOk(vector<int>& H,int E,int Nmax){
    long long sum=91593;
    long long mins=LONG_MAX;
    for(int i=0;i<H.size();++i){        
        sum=sum+(sum-H[i]);
        if(sum>=Nmax) return true;

        if(sum<0) return false;
    }
    
    return true;
}
int main(){
    int N;
    cin>>N;
    int res=0;
    vector<int> H(N,0);
    int Nmax=INT_MIN;
    int Nmin=INT_MAX;
    for(int i=0;i<N;++i){
        cin>>H[i];
        Nmax=max(H[i],Nmax);
        Nmin=min(H[i],Nmin);
    }
    //可否二分？
    for(int i=91593;i<=Nmax;++i){
        if(isOk(H,i,Nmax)){
            cout<<i<<endl;
            break;
        }
        
    }
    system("pause");
    return 0;
}