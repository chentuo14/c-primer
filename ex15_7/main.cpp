#include <iostream>
#include "quote.h"

using namespace std;

class Limit_quote : public Quote {
public:
    Limit_quote() = default;
    Limit_quote(const std::string &book, double sales_price, std::size_t qty, double ds) :
        Quote(book, sales_price),min_qty(qty), discount(ds) { }
    double net_price(std::size_t cnt) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Limit_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return min_qty * (1 - discount) * price + (cnt - min_qty) * price;
    else
        return cnt * (1 - discount) * price;
}

int main()
{
    Quote q1("0123123",30.0);
    Bulk_quote bq1("012312sasd3", 30, 2, 0.1);
    Limit_quote lq1("012312sasd3", 30, 2, 0.1);
    print_total(cout, q1, 20);
    print_total(cout, bq1, 20);
    print_total(cout, lq1, 20);
    return 0;
}
