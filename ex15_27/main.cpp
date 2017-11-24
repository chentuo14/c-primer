#include <iostream>

using namespace std;

class Disc_quote : public Quote
{
public:
    Disc_quote(const string &book="", double sales_price=0.0, siez_t qty=0, double disc=0.0):
        Quote(book, sales_price), quantity(qty), discount(disc) { }
    double net_price(size_t cnt) const = 0;
protected:
    size_t quantity;
    double discount;
};

class Bulk_quote : public Disc_quote
{
public:
    using Disc_quote::Disc_quote;
    double net_price(size_t cnt) const
    {
        if( cnt > quantity)
            return cnt * (1 - discount) * price;
        else
            return cnt * price;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
