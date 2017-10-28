#include <iostream>

using namespace std;

class Y;

class X {
    Y *ptoY = nullptr;
};

class Y {
    X x;
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
