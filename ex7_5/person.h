#ifndef PERSON_H
#define PERSON_H


class Person
{
public:
    Person();
    Person(std::string _name, std::string _address);
    void show_info() {
        cout<<name<<"'s"<<" address is "<<address<<endl;
    }

    std::string name;
    std::string address;
};

#endif // PERSON_H
