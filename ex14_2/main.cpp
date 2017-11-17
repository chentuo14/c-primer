#include <iostream>

using namespace std;

class Sales_data {
    friend std::istream& operator>>(std::istream &, Sales_data &);
    friend std::istream& operator<<(std::istream &,const Sales_data &);

public:
    Sales_data operator +=(const Sales_data &, const Sales_data &);
};

    Sales_data operator +(const Sales_data &, const Sales_data &);

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
