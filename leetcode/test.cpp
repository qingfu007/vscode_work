#include <string>
#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;
int main() {
    vector<int> a(3,1);
    a.reserve(4);
    int i=a.size()-1;
    auto j=a.size()-1;
    // cout<<i<<endl;
    // cout<<j<<endl;
    unordered_set<int> nums;
    cout<<"a:"<<a.capacity()<<endl;
    int n=5;
    while(n--)
    {
        a.push_back(20000);
    }
    

    cout<<"a:"<<a.capacity()<<endl;
    a.reserve(9);
    cout<<"a:"<<a.capacity()<<endl;
    a.push_back(20000);
    a.push_back(20000);
    cout<<"a:"<<a.capacity()<<endl;
    cout<<"a:"<<a.capacity()<<endl;
    cout<<"a:"<<a.capacity()<<endl;


    cout<<"nums:"<<nums.max_size()<<endl;



    int pause;
    cin >> pause;
    return 0;
    
}