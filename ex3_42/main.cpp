#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1(10,10);
    int a[10];
    for(int i=0;i<10;i++)
    {
        a[i] = v1[i];
        cout<<a[i]<<" ";
    }
    return 0;
}
