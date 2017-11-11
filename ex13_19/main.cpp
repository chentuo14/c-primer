#include <iostream>

using namespace std;

class Employee {
private:
    static int sn;
public:
    Employee() { mysn = sn++; }
    Employee(const string &s) { name = s; mysn = sn++; }
    Employee(Employee &e) { name = e.name; mysn = sn++; }
    Employee& operator =(Employee &rhs) { name = rhs.name; return *this; }

    const string &get_name() { return name; }
    int get_mysn() { return mysn; }
    string name;
    int mysn;
};

int Employee::sn = 0;

void f(Employee &s)
{
    cout<<s.get_name()<<":"<<s.get_mysn()<<endl;
}

int main(int argc, char *argv[])
{
    Employee a("zhao"), b = a, c;
    c = b;
    f(a); f(b); f(c);

    return 0;
}
