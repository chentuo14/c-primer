#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void remove_author(multimap<string, string> &books,
                   const string &author)
{
    auto pos = books.equal_range(author);
    if(pos.first == pos.second)
        cout<<"None "<<author<<" this author"<<endl<<endl;
    else
        books.erase(pos.first, pos.second);
}

void print_books(multimap<string, string> &books)
{
    cout<<"current book list include:"<<endl;
    for(auto &book : books)
        cout<<book.first<<", 《"<<book.second<<"》"<<endl;
    cout<<endl;
}

int main(int argc, char *argv[])
{
    multimap<string, string> books;
    books.insert({"Barth, John", "Sot-Weed Factor"});
    books.insert({"Barth, John","Lost in the Funhous"});
    books.insert({"JinYong", "SheDiaoYingXiongZhuan"});
    books.insert({"JinYong", "TianLongBaBu"});

    print_books(books);

    remove_author(books, "ZhangSan");
    remove_author(books, "Barth, John");
    print_books(books);

    return 0;
}
