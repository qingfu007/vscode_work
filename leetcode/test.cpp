#include <string>
#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

class HashPtr {
public:
    //  构造函数
    HashPtr(const string &s=string()):
        ps(new string(s)),i(0) { }
    //拷贝构造函数
    HashPtr(const HashPtr & p):
        ps(new string(*p.ps)), i(p.i) { }
    //拷贝赋值运算符的声明
    HashPtr& operator=(const HashPtr &);
    //析构函数
    ~HashPtr() {delete ps; }

private:
    string *ps;
    int i;
    
};

HashPtr& HashPtr::operator=(const HashPtr &rhs)
{
    auto newp =new string(*rhs.ps);
    delete ps;
    ps=newp;
    i=rhs.i;
    return *this;
}


int main() {

    string s=string();
    




    int pause;
    cin >> pause;
    return 0;
    
}