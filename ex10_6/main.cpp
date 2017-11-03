#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec(10, 1);
    for(auto iter = vec.begin();iter!=vec.end();++iter)
        cout<<*iter<<" ";
    cout<<endl;
    fill_n(vec.begin(), vec.size(), 2);
    for(auto iter = vec.begin();iter!=vec.end();++iter)
        cout<<*iter<<" ";
    return 0;
}
