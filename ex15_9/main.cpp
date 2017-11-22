#include <iostream>
#include "quote.h"

using namespace std;

int main()
{
    Bulk_quote bulk;
    Quote *pQuote = &bulk;
    Quote &rQuote = bulk;
    return 0;
}
