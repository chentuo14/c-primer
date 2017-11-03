#include <iostream>

using namespace std;

int main()
{
    string before1 = "Mr.",before2 = "Ms.";
    string after1 = "Jr.", after2 = "III";
    string name = "chentuo";

    name.insert(name.begin(),before1.begin(), before1.end());
    name.insert(name.size(), after1);

    cout<<name<<endl;

    return 0;
}
