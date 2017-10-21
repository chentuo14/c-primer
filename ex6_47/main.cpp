#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVec(vector<int> &vec)
{
#ifndef NDEBUG
    cout<<"vector size: "<<vec.size()<<endl;
#endif
    if(!vec.empty())
    {
        auto tmp = vec.back();
        vec.pop_back();
        printVec(vec);
        cout<<tmp<<" ";
    }
}

int main()
{
    vector<int> myvector{1,2,3,4,5,6,7,8,9,10};

    printVec(myvector);

    return 0;
}
