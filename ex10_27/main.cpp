#include <iostream>
#include <vector>
#include <functional>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vi = {1,2,3,4,5,6,7,8,9};
    list<int> li;

    unique_copy(vi.begin(), vi.end(), back_inserter(li));

    for(auto v: li)
        cout<<v<<" ";
    cout<<endl;

    return 0;
}
