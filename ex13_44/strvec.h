#ifndef STRVEC_H
#define STRVEC_H

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
    ~String() { free(); }
    void free();

private:
    allocator<char> alloc;
    char *elements;
    char *end;
    pair<char*, char*> alloc_n_copy(const char *b, const *e);

    void range_initializer(const char *c, const char *d);
};

String::String(const char *s) {
    auto s1 = const_cast<char *>(s);
    while(*s1) {
        ++s1;
    }
    alloc_n_copy(s, s1);
}

void String::free() {
    if(elements) {
        for_each(elements, end, [this](const &rhs) { alloc.destroy(&rhs);});
        alloc.deallocate(elements, end - elements);
    }
}

pair<char *, char *> String::alloc_n_copy(const char *b, const*e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void String::range_initializer(const char *c, const char *d)
{
    auto p = alloc_n_copy(d, c);
    elements = p.first;
    end = p.second;
}

#endif // STRVEC_H


