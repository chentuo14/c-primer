#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &p) :
        ps(new string(*p.ps)), i(p.i) { }
    HasPtr& operator =(const HasPtr&);
    HasPtr& operator =(const string&);
    string& operator *();
    ~HasPtr();

private:
    string *ps;
    int i;
};

inline
HasPtr &HasPtr::operator =(const HasPtr &rhs)
{
    auto newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}

HasPtr& HasPtr::operator =(const string &rhs)
{
    *ps = rhs;
    return *this;
}

HasPtr::~HasPtr()
{
    delete ps;
}

string& HasPtr::operator *()
{
    return *ps;
}

int main(int argc, char *argv[])
{
    HasPtr h("hi mom!");
    HasPtr h2(h);
    HasPtr h3 = h;
    h2 = "hi dad!";
    h3 = "hi son!";
    cout<<"h: "<<*h<<endl;
    cout<<"h2: "<<*h2<<endl;
    cout<<"h3: "<<*h3<<endl;
    return 0;
}
