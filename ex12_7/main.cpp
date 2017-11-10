#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> new_vector(void)
{
    return make_shared<vector<int>>();
}

void read_ints(shared_ptr<vector<int>> pv)
{
    int v;

    while(cin>>v)
        pv->push_back(v);
}

void print_ints(shared_ptr<vector<int>> pv)
{
    for(const auto &v : *pv)
        cout<<v<<" ";
    cout<<endl;
}

int main()
{
    auto pv=new_vector();

    read_ints(pv);
    print_ints(pv);
    return 0;
}
