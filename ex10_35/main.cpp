#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi = {1,2,3,4,5,6,7,8,9,0};

    for(auto iter=vi.end();iter!=vi.begin();)
        cout<<*--iter<<" ";

    return 0;
}
