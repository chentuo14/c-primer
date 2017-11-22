#ifndef QUOTE_H
#define QUOTE_H

#include <iostream>

using namespace std;

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const
        { return n * price; }
    virtual ~Quote() = default;
    friend double print_total(ostream &os, const Quote &item, size_t n);


private:
    std::string bookNo;
protected:
    double price = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os<<"ISBN:"<<item.isbn()<<" # sold: "<<n<<" total due: "<<ret<<endl;
    return ret;
}

class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double sales_price, std::size_t qty, double ds) :
        Quote(book, sales_price),min_qty(qty), discount(ds) { }
    double net_price(std::size_t cnt) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

#endif // QUOTE_H
