#include <iostream>
#include "quote.h"

using namespace std;

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
//    Bulk_quote(const std::string &book, double sales_price, std::size_t qty, double ds) :
//        bookNo(book), price(sales_price), min_qty(qty), discount(ds) { }
    double net_price(std::size_t cnt) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) *price;
    else
        return cnt * price;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}


