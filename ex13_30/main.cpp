#include <iostream>
#include <string>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0), use(new std::size_t(1)) { }
    HasPtr(const HasPtr &p) :
        ps(p.ps), i(p.i), use(p.use) { ++*use; }
    HasPtr& operator =(const HasPtr&);
    HasPtr& operator =(const string&);
    string& operator *();
    ~HasPtr();
    void swap(HasPtr &lhs, HasPtr &rhs);

private:
    string *ps;
    int i;
    std::size_t *use;
};

inline
HasPtr &HasPtr::operator =(const HasPtr &rhs)
{
    ++*rhs.use;
    if(--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr& HasPtr::operator =(const string &rhs)
{
    *ps = rhs;
    return *this;
}

HasPtr::~HasPtr()
{
    if(--*use == 0) {
        delete ps;
        delete use;
    }
}

inline
void HasPtr::swap(HasPtr &lhs, HasPtr &rhs)
{
    cout<<"change"<<*lhs.ps<<" and "<<*rhs.ps<<endl;
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
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
    swap(h2, h3);
    cout<<"h: "<<*h<<endl;
    cout<<"h2: "<<*h2<<endl;
    cout<<"h3: "<<*h3<<endl;
    return 0;
}
