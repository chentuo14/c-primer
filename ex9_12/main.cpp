#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> list = {1, 2, 3.0 , 4, 5, 6, 7};
    vector<int> list2 = list;                               //是全部拷贝
    vector<int> list3(list.begin() +2, list.end()-1);       //可以控制起始位置和结束位置

    return 0;
}
