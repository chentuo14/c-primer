#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> vi = {0,1,2,3,4,5,6,7,8,9};
    list<int> ls;
    int p = 10;
    for(auto riter = vi.rbegin();riter!=vi.rend();riter++,p--)
    {
        if(p<8&&p>2)
            ls.push_back(*riter.base());
    }

    for(auto iter=ls.begin();iter!=ls.end();iter++)
        cout<<*iter<<" ";

    return 0;
}
