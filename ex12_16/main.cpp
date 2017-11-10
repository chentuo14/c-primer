#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<double> p1;
    unique_ptr<int> p2(new int(42));

//    unique_ptr<string> p1(new string("Stegosaurus"));
//    unique_ptr<string> p2(p1);
//    unique_ptr<string> p3;
//    p3 = p2;g
    return 0;
}
