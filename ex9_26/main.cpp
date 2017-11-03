#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> vec;
    list<int> mlist;
    for(int i=0;i<11;++i)
    {
        vec.push_back(ia[i]);
        mlist.push_back(ia[i]);
    }
    auto vb = vec.begin();
    auto lb = mlist.begin();
    while(vb !=vec.end())
    {
        if(*vb%2==0)
            vb = vec.erase(vb);
        else
            ++vb;
    }
    while(lb !=mlist.end())
    {
        if(*lb%2==0)
            ++lb;
        else
            lb = mlist.erase(lb);
    }
    for(auto i=vec.begin();i!=vec.end();++i)
        cout<<*i<<" ";
    cout<<endl;
    for(auto i=mlist.begin();i!=mlist.end();++i)
        cout<<*i<<" ";

    return 0;
}
