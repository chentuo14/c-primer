#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

void add_family(map<string, vector<pair<string, string>>> &families, const string &family)
{
    if(families.find(family) == families.end())
        families[family];
}

void add_child(map<string, vector<pair<string, string>>> &families,
               const string &family, const string &child, const string &birthday)
{
    families[family].push_back({child, birthday});
}

int main()
{
    map<string, vector<pair<string, string>>> families;
    add_family(families, "zhang");
    add_child(families, "zhang","qiang","1991-11-14");
    add_child(families, "zhang", "gang","1970-1-1");
    add_child(families, "wang", "wu", "1980-1-1");
    add_family(families, "wang");

    for(auto f : families) {
        cout<<f.first<<"'s child:";
        for(auto c: f.second)
            cout<<c.first<<" (born:"<<c.second<<")"<<endl;
        cout<<endl;
    }

    return 0;
}
