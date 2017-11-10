#include <iostream>
#include <memory>

using namespace std;

struct destination {};
struct connection {};

connection connect(destination *pd)
{
    cout<<"open connect"<<endl;
    return connection();
}

void disconnect(connection c)
{
    cout<<"close connect"<<endl;
}

void f(destination &d)
{
    cout<<"direct handle connect"<<endl;
    connection c = connect(&d);

    cout<<endl;
}

void end_connection(connection *p) { disconnect(*p); }

void f1(destination &d)
{
    cout<<"use chared_ptr handle connect"<<endl;
    connection c = connect(&d);
    shared_ptr<connection> p (&c, [](connection *p) {disconnect(*p);});

    cout<<endl;
}


int main()
{
    destination d;
    f(d);
    f1(d);
    return 0;
}
