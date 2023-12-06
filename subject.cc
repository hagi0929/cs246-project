#include "subject.h"
using namespace std;

Subject::Subject() {};
Subject::~Subject() {};

void Subject::subscribe(shared_ptr<Observer> o) {
    observers.emplace_back(o);
}

