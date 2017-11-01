#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;                         //int的vector类型，可以对v1增删改
    const vector<int> v2;                   //v2是int的vector,常量类型不能增删改
    auto it1 = v1.begin(), it2 = v2.begin();        //it1是int的vector可以增删改，it2因为v2是const的，所以it2不可增删改
    auto it3 = v1.cbegin(), it4 = v2.cbegin();      //it3和it4都是const的
    return 0;
}
