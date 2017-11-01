#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
public:
    Person();
    Person(std::string _name, std::string _address);
    void show_info() {
        std::cout<<name<<"'s"<<" address is "<<address<<std::endl;
    }

    const std::string& getName()
    {
        return name;
    }

    const std::string& getAddress()
    {
        return address;
    }

    std::string name;
    std::string address;
};

#endif // PERSON_H
