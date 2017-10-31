#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

struct PersonInfo {
    string name;
    vector<string> phones;
};

bool valid(const string &str)
{
    return isdigit(str[0]);
}

string format(const string &str)
{
    return str.substr(0, 3)+"-"+str.substr(3,3)+"-"+str.substr(6);
}

int main()
{
    ifstream ifs("phoneNumbers.txt");
    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    while(getline(ifs, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        record>>info.name;
        while(record>>word)
            info.phones.push_back(word);
        people.push_back(info);
    }

    for(auto &entry : people) {
        ostringstream formatted, badNums;
        for(const auto &nums : entry.phones) {
            if(!valid(nums)) {
                badNums << " " << nums;
            } else {
                formatted << " " << format(nums);
            }
        }
        if(badNums.str().empty())
            cout<<entry.name<<" "<<formatted.str()<<endl;
        else
            cerr<<"input error: "<<entry.name<<" invalid number(s) "<<badNums.str()<<endl;
    }

    return 0;
}