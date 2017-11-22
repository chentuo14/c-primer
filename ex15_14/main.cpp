#include <iostream>
#include "print.h"

using namespace std;

int main()
{
    base bobj("bobj");
    base *bp1 = &bobj;
    base &br1 = bobj;

    derived dobj("dobj", 2);
    base *dp2 = &dobj;
    base &br2 = dobj;

    bobj.print(cout);
    dobj.print(cout);
    bp1->name();
    dp2->name();
    br1.print(cout);
    br2.print(cout);

    return 0;
}
