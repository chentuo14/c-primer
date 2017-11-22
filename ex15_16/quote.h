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
    virtual void debug() {
        cout<<"bookNo="<<bookNo<<" price="<<price<<endl;
    }

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

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book,double price, std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) { }
    double net_price(std::size_t ) const = 0;

protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double sales_price, std::size_t qty, double ds) :
        Disc_quote(book, sales_price, qty, ds) { }
    double net_price(std::size_t cnt) const override;
    virtual void debug() {
        Quote::debug();
        cout<<"min_qty="<<quantity<<" discount="<<discount<<endl;
    }
};

double Bulk_quote::net_price(size_t cnt) const
{
    if (cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

#endif // QUOTE_H
