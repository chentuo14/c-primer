#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi={1,2,3,4,5,6,7,8,9,0};

    for(auto riter = vi.rbegin();riter!=vi.rend();riter++)
        cout<<*riter<<" ";
    return 0;
}
