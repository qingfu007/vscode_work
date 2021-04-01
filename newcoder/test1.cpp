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
            temp[i-1]++;
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
    for(int i=0;i<res.size();++i){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    int k;
    cin>>k;
    return 0;
}