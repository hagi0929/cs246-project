#ifndef HISTORY_H
#define HISTORY_H

#include <string>

using namespace std;

class History {
 public:
  History();
  ~History();
  void add(const std::string& cmd);
  void clear();
  void print();
  string get(int n);
  int size();
};

#endif