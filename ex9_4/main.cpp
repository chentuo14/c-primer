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

int main()
{
    vector<int> vec;
    for(int i=0;i<10;++i)
        vec.push_back(i);

    if(function(vec, 10))
        cout<<"the value is in vector.";
    else
        cout<<"the value is not in vector.";
    return 0;
}
