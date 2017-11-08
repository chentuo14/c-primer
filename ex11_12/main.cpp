#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if(!in) {
        cout<<"open file failed."<<endl;
        exit(1);
    }

    vector<pair<string, int>> data;
    string s;
    int v;
    while(in>>s && in>>v)
        data.push_back(pair<string, int>(s, v));

    for(const auto &d : data)
        cout<<d.first<<" "<<d.second<<endl;

    return 0;
}
