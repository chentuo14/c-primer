#include <iostream>
#include <fstream>
#include "ex8_6.h"

using namespace std;

int main(int argc, char **argv)
{
    std::ifstream input(argv[1]);
    Sales_data total;
    if(read(input, total)) {
        Sales_data trans;
        while(read(input, trans)) {
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(std::cout, total)<<std::endl;
                total = trans;
            }
        }
        print(std::cout, total) << std::endl;
    }
    else {
        std::cerr << "No data?!"<< std::endl;
    }
    return 0;
}
