#include <iostream>
#include "quote.h"

using namespace std;

int main()
{
    Quote q1("0123123",30.0);
    Bulk_quote bq1("012312sasd3", 30, 2, 0.1);
    print_total(cout, q1, 20);
    print_total(cout, bq1, 20);
    return 0;
}
