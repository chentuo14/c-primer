#include <iostream>

using namespace std;

int main()
{
    int i =3;
    auto f = [&i]()->bool{if(i==0) return false; else {--i; return true;}};
    int j = f();
    j = f();
    j = f();
    cout<<j<<endl;
    return 0;
}
