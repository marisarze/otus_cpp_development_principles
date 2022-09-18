#include <iostream>
#include <vector>
#include "editor.h"
#include <fmt/core.h>


class Figure {
    public:
    std::string name="AbStRaCt_FiGuRe";
}

class Square: public Figure {
    public:
    std::string name="SqUaRe_FiGuRe";
}

class Circle: public Figure {
    public:
    std::string name="CiRcLe_FiGuRe";
}

class Triangle: public Figure {
    public:
    std::string name="TrIaNgLe_FiGuRe";
}


class Tab {
    std::vector <Figure*> content;
    public:

    Tab(std::string path){
        fmt::print("Tab loaded from file {}", path);
    }

    Tab(){
        fmt::print("New empty tab created);
    }

    void save(std::string path){
        fmt::print("Tab {} was saved to file {}", this, path);
    }

    void add_figure(Figure* figure){
        content.emplace_back(figure);
        fmt::print("Figure {} was added to tab {}", figure->name, this);
    }

    void remove_figure(Figure* figure){
        auto it=std::find(content.begin(), content.end(), figure);
        content.erase(it);
        delete *it;
        fmt::print("Figure {} was removed from file {}", figure->name, this);
    }
}


class Editor {
    std::vector <File*> open_tabs = {};
    File* current_focus = nullptr;
    public:
    void open_file(std::string file_path){
        auto new_tab = File(file_path); 
        open_tabs.emplace_back(new_tab);
        change_focus_to(new_tab);
    }

    void change_focus_to(File* tab){
        current_focus = tab;
        fmt::print("Current focus changed to {}", tab);
    }

    void save_tab(File* tab, std::string path){
        tab->save(file_path);
    }

    void start(){
        fmt::print("Starting the engine.");
    }

    void close(){
        fmt::print("Preparing for closing the engine...Closed.");
    }












}