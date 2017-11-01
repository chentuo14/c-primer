#ifndef PERSON_H
#define PERSON_H

#include <iostream>

class Person
{
public:
    Person(std::string _name, std::string _address);
    Person();

    void show_info() {
        std::cout<<name<<"'s"<<" address is "<<address<<std::endl;
    }

    std::istream &read(std::istream &is, Person &_person)
    {
        is>>_person.name>>_person.address;
        return is;
    }

    std::ostream &print(std::ostream &os, const Person &_person)
    {
        os<<_person.name<<" "<<_person.address;
        return os;
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
