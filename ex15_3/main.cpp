#include <iostream>
#include "quote.h"

using namespace std;

int main()
{
    Quote santi("123456", 23.0);
    santi.print_total(cout, santi, 2);
    return 0;
}
