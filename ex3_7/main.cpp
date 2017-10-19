#include <iostream>

using namespace std;

int main()
{
    string s1 = "sjdsljdlasjda";
    for(char &c :s1)
        c = 'X';
    cout << s1 << endl;
    return 0;
}
