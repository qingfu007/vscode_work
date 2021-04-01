#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

string make_plural(size_t ctr,const string &word, const string &ending);
void elimDups(vector<string> &words);
void biggies(vector<string> &words,vector<string>::size_type sz);


string make_plural(size_t ctr,const string &word, const string &ending)
{
    return (ctr==1)?word:word+ending;
}


void elimDups(vector<string> &words)
{
    sort(words.begin(),words.end());
    auto end_unique = unique(words.begin(),words.end());
    words.erase(end_unique,words.end());

}
void biggies(vector<string> &words,vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(),words.end(),[](const string& a, const string &b){return a.size()<b.size();});
    auto wc=find_if(words.begin(),words.end(),[sz](const string&a){return a.size()>=sz;});
    auto count=words.end()-wc;
    cout<<count<<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer "<<endl;

    for_each(wc,words.end(),
            [](const string &s){cout<<s<<" ";});
    cout<<endl;


}

int main() {
    vector<string> words={"a","aa","bb","cc","dd","aaa","bbb","ccc","ddd","aa","aab","ddd","aasdf"};
    size_t t=2;
    biggies(words,t);
    ostream_iterator<string> out_iter(cout,"\n"); 
    copy(words.begin(),words.end(),out_iter);
    cout<<endl;



    system("pause");
    return 0;
    
}