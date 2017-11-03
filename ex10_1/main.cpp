#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec = {1,2,34,5,63,1,1,2,3,4,5};
    int ret;
    auto c = vec.begin();
    ret = count(vec.begin(), vec.end(), 1);
    cout<<ret;
    return 0;
}
