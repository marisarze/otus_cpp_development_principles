#include <iostream>
#include <vector>
#include "editor.h"
#include <fmt/core.h>
#include <fmt/format.h>
#include <algorithm>
#include <memory>
#include <cstdio>


#define UNUSED(variable) (void)variable

template <typename... Args>
void println(std::string format, const Args&... args) {
  fmt::print(format, args...);
  std::putc('\n', stdout);
}

// void Figure::change() {};

void Square::change() {
    println("The SQUARE is changed", 0);
}

void Circle::change() {
    println("The CIRCLE is changed", 0);
}

void Triangle::change() {
    println("The TRIANGLE is changed", 0);
}

void Rectangle::change() {
    println("The RECTANGLE is changed", 0);
}

Tab::Tab(){}

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
    println("Figure erased from tab {}", fmt::ptr(this));
}

Editor::Editor(){
    println("Editor created");
}

void Editor::open_file(std::string path){
    auto new_tab = std::make_shared<Tab>(path); 
    open_tabs.emplace_back(new_tab);
    change_focus_to(new_tab);
    println("New empty tab created with loading from \'{}\'", path);
}

void Editor::create_new_tab(){
    auto new_tab = std::make_shared<Tab>(); 
    open_tabs.emplace_back(new_tab);
    change_focus_to(new_tab);
    println("New empty tab created");
}

void Editor::close_tab(std::shared_ptr<Tab> tab){
    auto it = std::find(open_tabs.begin(), open_tabs.end(), tab);
    open_tabs.erase(it);
    println("Tab erased from editor {}", fmt::ptr(this));
}

void Editor::change_focus_to(std::shared_ptr<Tab> tab){
    current_tab = tab;
    println("Current focus changed to {}", fmt::ptr(tab.get()));
}

std::vector <std::shared_ptr<Figure>> Editor::current_tab_content(){
    return current_tab->content;
}

void Editor::start(){
    println("Starting the engine");
}

void Editor::stop(){
    println("Preparing for stopping the engine...Stopped");
}
