#include <iostream>
#include <string>

using namespace std;

class X{
public:
    string s;
    X(std::istream &is = std::cin) {
        is>>s;
    }
    void print() {
        cout<<s<<endl;
    }
};

int main()
{
    X x(std::cin);
    x.print();
    return 0;
}

