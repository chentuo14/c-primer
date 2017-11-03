#include <iostream>

using namespace std;

int main()
{
    string s={"12345678907565423414563413123877"};
    string oldVal,newVal;
    oldVal = "12";
    newVal = "aaa";

    for(auto curr=s.begin();curr!=s.end();++curr)
    {
        if(s.substr(curr-s.begin(),oldVal.size())==oldVal)    //找到对应的oldVal
        {   //查出并插入
            curr = s.erase(curr, curr+oldVal.size());
            curr = s.insert(curr, newVal.begin(), newVal.end());
        }
    }

    cout<<s<<endl;

    return 0;
}
