#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>

using namespace std;

class base {
public:
    base();
    base(string szNm): basename(szNm) { }
    string name() {return basename; }
    virtual void print(ostream &os) { os<<basename<<" "; }

private:
    string basename;
};

class derived : public base {
public:
    derived(string szName, int iVal):base(szName), i(iVal) { }
    void print(ostream &os) { base::print(os); os<<"--"<<i; }
private:
    int i;
};

#endif // PRINT_H
