#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

void biggies(vector<int> &vc, const string &s)
{
    auto p = find_if(vc.begin(), vc.end(),
                     bind(check_size, s, _1));
    cout<<p-vc.begin()+1<<" :"<<*p<<">= "<<s<<".length"<<endl;
}

int main()
{
    vector<int> vc = {1,2,3,4,5,6,7,8,9,0};

    biggies(vc, "hello");
    biggies(vc, "everyone");
    biggies(vc, "!");

    return 0;
}
