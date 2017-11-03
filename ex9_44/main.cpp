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
        {
            int temp = curr-s.begin()-oldVal.size()+newVal.size();
            s.replace(curr-s.begin(), oldVal.size(), newVal);
            curr = s.begin()+temp;
        }
    }

    cout<<s<<endl;
    return 0;
}
