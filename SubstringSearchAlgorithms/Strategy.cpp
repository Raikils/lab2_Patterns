#include "Strategy.h"

//Implement of algorithms
int Naive::Search(const std::string& Line_1, const std::string& Line_2) {
    int pos = 0;
    return pos;
}

int Rabina_Karpa::Search(const std::string& Line_1, const std::string& Line_2) {
    int pos = 0;
    return pos;
}
int Horspool:: Search(const std::string& Line_1, const std::string& Line_2) {
    int pos = 0;
    return pos;
}

int KMP::Search(const std::string& Line_1, const std::string& Line_2) {
    int pos = 0;
    return pos;
}

int Boyer_Moor::Search(const std::string& Line_1, const std::string& Line_2) {
    int pos = 0;
    return pos;
}

//Implement a class for use
Substring_Search_Algorithms_::Substring_Search_Algorithms_(Substring_Search_Algorithms* comp) : p(comp) {}

Substring_Search_Algorithms_::~Substring_Search_Algorithms_() { delete p; }

int Substring_Search_Algorithms_::Search(const std::string& Line_1, const std::string& Line_2) {
    p->Search(Line_1, Line_2);
}