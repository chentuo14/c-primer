#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class StrVec {
public:
    StrVec():
        elements(nullptr), first_free(nullptr), cap(nullptr) { }
    StrVec(const StrVec &s);
    StrVec(initializer_list<string> s);
    StrVec &operator =(const StrVec &rhs);
    ~StrVec();
    void push_back(const std::string &s);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

private:
    std::allocator<std::string> alloc;
    void chk_n_alloc() { if(size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string *> alloc_n_copy (const std::string *b, const std::string *s);
    void free();
    void reallocate();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};

StrVec::StrVec(const StrVec &s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(initializer_list<string> s)
{
    auto newdata  = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = newdata.second;
}

StrVec &StrVec::operator =(const StrVec &rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const string &s)
{
    chk_n_alloc();

    alloc.construct(first_free++, s);   //把first_free指向s的副本，并加1
}

std::pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto data = alloc.allocate(e - b);

    return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free()
{
    if(elements) {
        for(auto p = first_free;p!=elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate()
{
    auto newcapacity = size()?2*size():1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto elem = elements;
    for(size_t i=0;i!=size();++i)
        alloc.construct(dest++, std::move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}


