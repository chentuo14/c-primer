#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;

//    vec.at(0);        //这个会抛出out_of_range
    vec[0];
    vec.front();
    vec.begin();
    return 0;
}
