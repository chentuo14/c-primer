#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> m;
    auto it = m.begin();
    it->second = 1;

    return 0;
}
