#ifndef STRING_H
#define STRING_H

#include <string>
#include <algorithm>
#include <memory>

using namespace std;

class String {
public:
    String();
    String(const char* s);
    String(const String &);
    String &operator =(const String &);
    friend ostream &operator <<(ostream &os, const String &s);
    ~String() { free(); }
    void free();

private:
    allocator<char> alloc;
    char *elements;
    char *end;
    std::pair<char*, char*> alloc_n_copy(const char *b, const char *e);

    void range_initializer(const char *c, const char *d);
};

String::String(const char *s) {
    auto s1 = const_cast<char *>(s);
    while(*s1) {
        ++s1;
    }
    alloc_n_copy(s, s1);
}

ostream &operator <<(ostream &os, const String &s)
{
   cout<<*s.elements;
   return os;
}

void String::free() {
    if(elements) {
        for_each(elements, end, [this](const &rhs) { alloc.destroy(&rhs);});
        alloc.deallocate(elements, end - elements);
    }
}

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void String::range_initializer(const char *c, const char *d)
{
    auto p = alloc_n_copy(d, c);
    elements = p.first;
    end = p.second;
}

#endif // STRING_H




