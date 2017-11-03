#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<char> vi = {'a','b','c','d'};
    string s1(vi.begin(),vi.end());

    cout<<s1<<endl;
    return 0;
}
