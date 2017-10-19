#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arry1(10, 42);              //第一种
    vector<int> arry2{42,42,42,42,42,42,42,42,42,42};   //第二种
    vector<int> arry3;          //第三种
    for(int i=0;i<10;i++)
        arry3.push_back(42);

    for(auto num : arry1)
        cout<<num<<" ";
    cout<<endl;

    for(auto num : arry2)
        cout<<num<<" ";
    cout<<endl;

    for(auto num : arry3)
        cout<<num<<" ";
    cout<<endl;

    return 0;
}
