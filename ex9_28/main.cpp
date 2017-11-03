#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<string> flst={"abc", "bcd", "efg", "hij"};
    string s1 = "abdc";
    string s2 = "ksjdaljd";
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    bool flag = false;
    while(curr!=flst.end())
    {
        if(*curr==s1)
        {
            flst.insert_after(prev, s2);
            flag = true;
        }

        prev=curr;
        ++curr;
    }
    if(!flag)
        flst.insert_after(prev, s2);

    for(auto i=flst.begin();i!=flst.end();++i)
    {
        cout<<*i<<" ";
    }


    return 0;
}
