#include <iostream>

using namespace std;

int main()
{
    constexpr size_t array_size = 10;
    int ia[array_size];
    for (size_t ix = 1; ix <= array_size; ++ix)     //这里的ia[0]没有赋值
        ia[ix] = ix;
    return 0;
}
