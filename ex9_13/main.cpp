#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    list<int> list1={0,1,2,3,4,5,6,7,8};
    vector<double> vecDouble(list1.begin(), list1.end());           //元素类型相容
    vector<int> vecInt(list1.begin(), list1.end());

    return 0;
}
