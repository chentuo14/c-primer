#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int b[10] = {0,1,2,3,4,5,6,7,8,9};
    vector<int> v1(a, a+10);
    vector<int> v2(b, b+10);
    int flag = 0;

//    for(int i=0;i<10;i++)
//    {
//        if(a[i]!=b[i])
//        {
//            flag = 1;
//            break;
//        }
//    }
//    if(!flag)
//        cout<<"Equal"<<endl;
//    else
//        cout<<"not equal"<<endl;

    if(v1 == v2)
        cout<<"Equal"<<endl;
    else
        cout<<"not equal"<<endl;

    return 0;
}
