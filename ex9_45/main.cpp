#include <iostream>

using namespace std;

int main()
{
    string before1 = "Mr.",before2 = "Ms.";
    string after1 = "Jr.", after2 = "III";
    string name = "chentuo";

    auto iter = name.begin();
    name.insert(iter,before1.begin(), before1.end());
    name.append(after1);

    cout<<name<<endl;

    return 0;
}
