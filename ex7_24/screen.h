#ifndef SCREEN_H
#define SCREEN_H

class Screen {

public:
    using pos = std::string::size_type;
    Screen() = default;     //另有一个构造函数，所以此函数是必须的
    Screen(pos ht, pos wd) : height(ht), width(wd),
        contents(ht*wd, ' ') { }
    Screen(pos ht, pos wd, char c) : height(ht),width(wd),
        contents(ht*wd, c) { }
    char get() const                        //读取光标处的字符
        { return contents[cursor]; }        //隐式内联,在类内定义的默认是内联函数
    inline char get(pos ht, pos wd) const;  //显示内联
    Screen &move(pos r, pos c);             //能在之后被设为内联

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

char Screen::get(Screen::pos ht, Screen::pos wd) const
{
    pos row = ht * width;
    return contents[row + wd];
}

inline
Screen &Screen::move(Screen::pos r, Screen::pos c)
{
    pos row = r*width;
    cursor = row+c;
    return *this;
}

#endif // SCREEN_H
