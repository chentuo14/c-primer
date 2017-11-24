#include <iostream>
#include <string>
#include <ostream>
#include "quote.h"
#include <vector>
#include <memory>

using namespace std;

int main()
{
    vector<shared_ptr<Quote>> itemVec;
    for(size_t i = 0; i != 10; ++i)
    {
        itemVec.push_back(make_shared<Bulk_quote>("C++ Primer", 6, 5, 0.5));
    }

    double sum = 0;
    for(vector<shared_ptr<Quote>>::iterator iter = itemVec.begin(); iter != itemVec.end(); ++iter)
    {
        sum += (*iter)->net_price(10);
    }

    cout<<sum<<endl;
    return 0;
}
