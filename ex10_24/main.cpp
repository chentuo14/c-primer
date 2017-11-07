#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::placeholders;

string make_plural(size_t ctr,const string &word, const string &ending)
{
    return (ctr==1) ? word : word+ending;
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size()<=sz;
}

void biggies(vector<int> &vc, const string &s)
{
    auto p = find_if(vc.begin(), vc.end(),
                     bind(check_size, s, _1));
    cout<<p - vc.begin()+1<<" "<<*p<<" >= "<<s<<"的长度"<<endl;
}

int main()
{
    vector<int> vc = {1,2,3,4,5,6,7,8,9};

    biggies(vc, "Hello");
    biggies(vc, "everyone");
    biggies(vc, "!");

    return 0;
}
