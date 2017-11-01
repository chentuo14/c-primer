#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
public:
    Person();
    Person(std::string _name, std::string _address);
    std::string name;
    std::string address;
};

#endif // PERSON_H
