#include <iostream>

using namespace std;

class Foo {
public:
    Foo();
    Foo(const Foo&);
};

class Sales_data {
public:
    Sales_data(const Sales_data &);
private:
    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

Sales_data::Sales_data(const Sales_data &orig):
    bookNo(orig.bookNo),
    units_sold(orig.units_sold),
    revenue(orig.revenue) { }

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
