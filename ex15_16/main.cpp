#include <iostream>
#include "quote.h"

using namespace std;

class Limited_quote : public Disc_quote {
public:
    Limited_quote(const string &book="",double sales_price=0.0,size_t qty=0, double disc_rate=0.0):
        Disc_quote(book, sales_price, qty, disc_rate) { }
    double net_price(size_t cnt) const override
    {
        if(cnt <= quantity)
            return cnt * (1 - discount) * price;
        else
            return quantity * (1 - discount) * price + (cnt - quantity) * price;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
