#include <iostream>

using namespace std;

int main()
{
    const string s = "Keep out!";
    for(auto &c : s) { /*这里的c应该是const char &类型的*/ }
    return 0;
}
