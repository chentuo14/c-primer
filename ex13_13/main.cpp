#include <iostream>
#include <vector>

using namespace std;

struct X {
    X() {std::cout<<"X()"<<std::endl;}
    X(const X&) {std::cout<<"X(const X&)"<<std::endl;}
    X& operator =(const X&rhs) {
        std::cout<<"= (const X&)"<<std::endl;
        return *this;
    }
    ~X() { std::cout<<"~X()"<<std::endl; }
};

void f1(X x)
{

}

void f2(X &x)
{

}

int main(int argc, char *argv[])
{
    cout<<"X x:"<<endl;
    X x;
    cout<<endl;

    cout<<"f1(X x):"<<endl;
    f1(x);
    cout<<endl;

    cout<<"f2(X &x):"<<endl;
    f2(x);
    cout<<endl;

    cout<<"X *px = new X:"<<endl;
    X *px = new X;
    cout<<endl;

    cout<<"vector<X> vx:"<<endl;
    vector<X> vx;
    vx.push_back(x);
    cout<<endl;

    cout<<"delete px:"<<endl;
    delete px;
    cout<<endl;

    cout<<" X y = x"<<endl;
    X y = x;
    y = x;
    cout<<endl;

    cout<<"end:"<<endl;

    return 0;
}
