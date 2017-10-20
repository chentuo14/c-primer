#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a[10];
    int *p = a;
    for(int i=0;i<10;i++)
    {
        a[i] = i;
        cout<<" "<<i;
    }
    cout<<endl;
    for(int i=0;i<10;i++)
    {
        *(p+i) = 0;
    }
    for(int i=0;i<10;i++)
    {
        cout<<" "<<*(p+i);
    }

    return 0;
}
