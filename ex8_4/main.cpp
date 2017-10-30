#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void ReadFileToVector(const std::string &fileName, vector<string> &vec)
{
    ifstream in(fileName);
    if(in) {
        string buf;
        while(std::getline(in, buf)) vec.push_back(buf);
    }
    else {
        cout<<fileName<<" error."<<endl;
    }
}

int main()
{
    vector<string> vec;
    ReadFileToVector("book.txt", vec);
    for(const auto &str : vec) std::cout<<str<<endl;
    return 0;
}
