#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
    list<string> mlist = {"1","2","3","4","5","6","3","1","1","2","3","4","5"};
    int ret;
    ret = count(mlist.begin(), mlist.end(), "1");
    cout<<ret;
    return 0;
}
