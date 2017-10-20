#include <iostream>

using namespace std;

int main()
{
    const char ca[] = {'h','e','l','l','o'};
    const char *cp = ca;
    while(*cp) {                /*这里可能在'o'后面还会输出，直到遇到0为止*/
        cout<<*cp<<endl;
        ++cp;
    }
    return 0;
}
