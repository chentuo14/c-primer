#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int b[10] = {0,1,2,3,4,5,6,7,8,9};
    int flag = 0;

    for(int i=0;i<10;i++)
    {
        if(a[i]!=b[i])
        {
            flag = 1;
            break;
        }
    }
    if(!flag)
        cout<<"Equal"<<endl;
    else
        cout<<"not equal"<<endl;

    return 0;
}
