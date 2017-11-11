#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(const HasPtr &hp) {
        ps = new string(*hp.ps);
        i = hp.i;
    }

    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
private:
    std::string *ps;
    int i;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
