#pragma once
#include <vector>
#include <memory>


template <typename... Args>
void println(std::string format, const Args&... args);

class Figure {
    public:
    virtual void change() = 0;
};

class Square: public Figure {
    public:
    void change() ;
};

class Circle: public Figure {
    public:
    void change() ;
};

class Triangle: public Figure {
    public:
    void change() ;
};

class Rectangle: public Figure {
    public:
    void change() ;
};


class Tab {
    public:
    std::vector <std::shared_ptr<Figure>> content;
    Tab();
    Tab(std::string path);
    void save(std::string path);
    void add_figure(std::shared_ptr<Figure> figure);
    void remove_figure(std::shared_ptr<Figure> figure);
};


class Editor {
    public:
    std::vector <std::shared_ptr<Tab>> open_tabs = {};
    std::shared_ptr<Tab> current_tab = nullptr;
    Editor();
    void open_file(std::string path);
    void create_new_tab();
    void change_focus_to(std::shared_ptr<Tab> tab);
    void close_tab(std::shared_ptr<Tab> tab);
    void start();
    void stop();
};
