#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

string &trans(string &s)
{
    for(int p =0;p<s.size();p++) {
        if(s[p] >='A' && s[p] <='Z')
            s[p]=s[p]-('A'-'a');
        else if(s[p] == ',' || s[p] == '.')
            s.erase(p,1);
    }
    return s;
}

int main(int argc, char *argv[])
{
    ifstream in(argv[1]);
    if(!in) {
        cout<<"open file failed."<<endl;
        exit(1);
    }

    map<string, list<int>> word_lineno;
    string line;
    string word;
    int lineno = 0;
    while(getline(in, line)) {
        lineno++;
        istringstream l_in(line);
        while(l_in>>word) {
            trans(word);
            word_lineno[word].push_back(lineno);
        }
    }

    for(const auto &w : word_lineno) {
        cout<<w.first<<"in line: ";
        for(const auto &i : w.second)
            cout<<i<<" ";
        cout<<endl;
    }

    return 0;
}
