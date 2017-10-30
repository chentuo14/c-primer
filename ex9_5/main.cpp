#include <iostream>
#include <vector>

using namespace std;

bool function(vector<int> &vec, int value)
{
    for(auto start = vec.begin(); start!=vec.end(); ++start)
    {
        if(*start == value)
            return true;
    }
    return false;
}

int function1(vector<int> &vec, int value)
{
    for(auto bgn = vec.begin(); bgn!=vec.end(); ++bgn)
    {
        if(*bgn == value)
            return bgn - vec.begin();
    }
    return -1;
}

int main()
{
    vector<int> vec;
    int ret;
    for(int i=0;i<10;++i)
        vec.push_back(i);

    ret = function1(vec, 10);
    if(ret!=-1)
        cout<<"the value in vec["<<ret<<"].";
    else
        cout<<"the value is not in vec.";

    return 0;
}
