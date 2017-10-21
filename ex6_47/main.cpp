#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &vec)
{
    if(!vec.empty())
    {
        cout<<vec.back()<<" ";
        vec.pop_back();
        printVec(vec);
    }
}

int main()
{
    vector<int> myvector;
    myvector.push_back(10);

    while (myvector.back() != 0)
    {
        myvector.push_back ( myvector.back() -1 );
    }
    printVec(myvector);

    return 0;
}
