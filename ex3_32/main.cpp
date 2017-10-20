#include <iostream>
#include <vector>

using namespace std;

int main()
{
//    int a[10];
//    int b[10];
//    for(int i=0;i<10;i++)
//    {
//        a[i] = i;
//        cout<<"a["<<i<<"] = "<<a[i]<<endl;
//    }

//    for(int i=0;i<10;i++)
//    {
//        b[i] = a[i];
//        cout<<"b["<<i<<"] = "<<a[i]<<endl;
//    }

    /*vector version*/
    vector<int> va;
    vector<int> vb;
    for(int i=0;i<10;i++)
        va.push_back(i);
    vb = va;

    for(int num : va)
        cout<<num<<" ";
    cout<<endl;
    for(int num : vb)
        cout<<num<<" ";

    return 0;
}
