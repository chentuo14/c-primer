#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    vector<string> buf;
    ifstream in("book.txt");

    if(in) {
        string line;
        while(getline(in, line)) {
            buf.push_back(line);
        }
    } else {
        cout<<"file open failed.";
    }

    for(auto &s : buf) {
        istringstream iss(s);
        string word;
        while(iss>>word) cout<<word<<endl;
    }

    return 0;
}
