#include <iostream>
#include <vector>
#include "editor.h"
#include <fmt/core.h>
#include <fmt/format.h>
#include <algorithm>
#include <memory>

#define UNUSED(variable) (void)variable

void Square::change() {
    fmt::print("The SQUARE is changed");
}

void Circle::change() {
    fmt::print("The CIRCLE is changed");
}

void Triangle::change() {
    fmt::print("The TRIANGLE is changed");
}

void Rectangle::change() {
    fmt::print("The RECTANGLE is changed");
}

Tab::Tab(){};

Tab::Tab(std::string path){
    UNUSED(path);
}

void Tab::save(std::string path){
    UNUSED(path);
}

void Tab::add_figure(std::shared_ptr<Figure> figure){
        content.emplace_back(figure);
}

void Tab::remove_figure(std::shared_ptr<Figure> figure){
    auto it = std::find(content.begin(), content.end(), figure);
    content.erase(it);
    fmt::print("Figure erased from tab {}", fmt::ptr(this));
}

void Editor::open_file(std::string path){
    auto new_tab = std::make_shared<Tab>(path); 
    open_tabs.emplace_back(new_tab);
    change_focus_to(new_tab);
    fmt::print("New empty tab created with loading from {}", path);
}

void Editor::create_new_tab(){
    open_tabs.emplace_back(std::make_shared<Tab>());
    fmt::print("New empty tab created");
}

void Editor::close_tab(std::shared_ptr<Tab> tab){
    auto it = std::find(open_tabs.begin(), open_tabs.end(), tab);
    open_tabs.erase(it);
    fmt::print("Tab erased from editor {}", fmt::ptr(this));
}

void Editor::change_focus_to(std::shared_ptr<Tab> tab){
    current_tab = tab;
    fmt::print("Current focus changed to {}", fmt::ptr(tab.get()));
}

void Editor::start(){
    fmt::print("Starting the engine");
}

void Editor::stop(){
    fmt::print("Preparing for stopping the engine...Stopped");
}
