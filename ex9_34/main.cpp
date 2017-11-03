#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto iter = vi.begin();
    while(iter!=vi.end())
    {
        if(*iter %2)
            iter = vi.insert(iter, *iter);      //这里如果插入元素，需要加2
        iter+=2;
    }

    cout << "Hello World!" << endl;
    return 0;
}
