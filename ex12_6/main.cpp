#include <iostream>
#include <vector>

using namespace std;

vector<int> *new_vector(void)
{
    return new (nothrow) vector<int>;
}

void read_ints(vector<int> *pv)
{
    int v;

    while(cin>>v)
        pv->push_back(v);
}

void print_ints(vector<int> *pv)
{
    for(const auto &v : *pv)
        cout<<v<<" ";
    cout<<endl;
}

int main()
{
    vector<int> *pv = new_vector();
//    vector<int> *pv = new vector<int>;
    if(!pv) {
        cout<<"momery ont enough."<<endl;
        return -1;
    }

    read_ints(pv);

    print_ints(pv);

    delete pv;
    pv = nullptr;
    return 0;
}
