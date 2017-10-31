#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<char*> mlist = {"this is a char*"};
    vector<string> vec;

    vec.assign(mlist.begin(), mlist.end());
n
    return 0;
}
