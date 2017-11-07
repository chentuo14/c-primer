#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<int> l1={0,1,2,3,4,5,0,6,7,8,9};

    auto last_z = find(l1.rbegin(),l1.rend(), 0);

    last_z++;
    int p = 1;
    for(auto iter= l1.begin();iter!=last_z.base();iter++,p++);

    if(p>=l1.size())
        cout<<"there is no zero."<<endl;
    else
        cout<<"the last zero in "<<p<<" size."<<endl;

    return 0;
}
