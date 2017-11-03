#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main()
{
    list<int> mlist;
    deque<int> odd,even;
    for(int i=0;i<10;++i)
        mlist.push_back(i);

    for(auto s=mlist.begin();s!=mlist.end();++s)
    {
        if(*s%2==0)
            even.push_back(*s);
        else
            odd.push_back(*s);
    }



    return 0;
}
