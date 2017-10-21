#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    int length;
    vector<int> arry;
    while(cin>>num)
    {
        arry.push_back(num);
    }

    auto iter = arry.cbegin();
    auto iter2 = arry.cend();
    for(int i=0;i<arry.size() - 1;i++)
    {
        iter++;
        iter2--;
        cout<<*iter+*iter2<<" ";
    }
    return 0;
}
