#include <iostream>

using namespace std;

class Sales_data {
    friend ostream & operator <<(ostream &os, Sales_data &item);
};

ostream & operator <<(ostream &os, Sales_data &item)
{
    const char *sep = '\t';
    std::cout<<item.isbn()<<sep<<item.units_sold<<sep<<
               item.revenue<<sep<<item.avg_price();
    return os;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
