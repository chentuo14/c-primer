#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void add_child(multimap<string, string> &families,
               const string &family, const string &child)
{
    families.insert({family, child});
}


int main()
{
    multimap<string, string> families;

    add_child(families, "zhang", "qiang");
    add_child(families, "zhang", "gang");
    add_child(families, "wang", "wu");

    for(auto f : families)
        cout<<f.first<<"'s child: "<<f.second<<endl;

    return 0;
}
