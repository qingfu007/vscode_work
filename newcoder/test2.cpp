#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include<utility>

using namespace std;

int main(){
    int N;
    cin>>N;
    while(N--){
        int M;
        cin>>M;
        unordered_map<pair<int,int>,int>count;
//        unordered_set<pair<int,int> pre;
        for(int i=0;i<M;++i){
            int len;
            cin>>len;
            unordered_set<pair<int,int>> s;
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
                if(s.find(u.first)==s.end()) u.second=0;
                else{
                    u.second++;
                }
            }
        }
        int res=0;
        for(auto &u:count){
            res=max(res,u.second);
        }
        cout<<res<<endl;
    }
    
    return 0;
}

