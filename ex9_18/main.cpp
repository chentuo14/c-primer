#include <iostream>
#include <deque>

using namespace std;

int main()
{
    std::string str;
    deque<string> deq;
    while(std::cin>>str)
        deq.push_back(str);


//    for(auto db = deq.begin();db!=deq.end();++db)
//        std::cout<<*db<<endl;
    for(auto db=deq.cbegin();db!=deq.cend();++db)
        std::cout<<*db<<endl;

    return 0;
}
