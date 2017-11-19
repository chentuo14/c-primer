#include <iostream>

using namespace std;

class Sales_data
{
    friend istream & operator >>(istream &is, Sales_data item);

};

istream &operator >>(istream &is, Sales_data item)
{
    double price;
    is>>item.bookNo>>item.units_sold>>price;
    if(is)
        item.revenue = item.units_sold * price;
    else
        item = Sales_data();
    return is;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
