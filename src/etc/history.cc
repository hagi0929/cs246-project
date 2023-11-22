#include "History.h"

History::History() {
    dout << "History ctor is called" << endl;
}
History::~History() {
    dout << "History dtor is called" << endl;
}
void History::add(const std::string& cmd) {
    dout << "history add is called" << endl;
}
void History::clear() {
    dout << "history clear is called" << endl;
}
void History::print() {
    dout << "history print is called" << endl;
}
string History::get(int n) {
    dout << "history get is called" << endl;
    return "";
}
int History::size() {
    dout << "history size is called" << endl;
    return 0;
}
