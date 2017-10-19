#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    vector<int> arry;
    for(int i=0;i<10;i++)
    {
        cin>>num;
        arry.push_back(num);
    }
    auto item = arry.begin();
    for(int i=0;i<10;i++,item++)
    {
        *item = *item*2;
    }

    for(num : arry)
    {
        cout<<num<<" ";
    }

    return 0;
}
