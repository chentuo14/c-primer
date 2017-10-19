#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    ivec.push_back(42);         //ivec[0] = 42;会报错
    return 0;
}
