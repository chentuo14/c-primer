#include <iostream>
#include <list>
#include <vector>

using namespace std;

bool l_v_equal(vector<int> &ivec, list<int> &ilist) {
    //比较list和vector的个数
    if(ivec.size() != ilist.size())
        return false;

    auto lb = ilist.begin();
    auto le = ilist.end();
    auto vb = ivec.begin();
    for(;lb!=le;++lb,++vb)
        if(*lb!=*vb) return false;

    return true;
}

int main()
{
    list<int> mylist = {1,2,3,4,5};
    vector<int> vec = {1,2,3,4,5};

    cout<<(l_v_equal(vec, mylist)?"yes":"no")<<endl;

    return 0;
}
