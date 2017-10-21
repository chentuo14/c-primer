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
    length = arry.size();
    for(int i=0;i<arry.size()-1;i++)
    {
        cout<<arry[i]+arry[length-i-1]<<" ";
    }

    return 0;
}
