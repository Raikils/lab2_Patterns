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
std::vector<int> Horspool::shift_table(const std::string& p)
{
    std::vector<int> a;
    int i;
    for (i = 0; i < 256; i++) {
        a.push_back(p.size());
    }
    for (i = 0; i < p.size(); i++) {
        a[p[i]] = p.size() - 1 - i;
    }
    return a;
}
int Horspool:: Search(const std::string& Line_1, const std::string& Line_2) {
    if (Line_2.size() > Line_1.size()) return -1;
    std::vector<int> t = shift_table(Line_2);
    int i = Line_2.size() - 1;
    while (i < Line_1.size()) {
        bool q = true;
        for (int k = 0; k < Line_2.size(); k++) {
            if (Line_2[Line_2.size() - 1 - k] != Line_1[i - k]) { q = false; break; }
        }
        if (q) return i - Line_2.size() + 1;
        i = i + t[Line_1[i]];
    }
    return -1;
}

std::vector<int> KMP::pref(const std::string& p)
{
    std::vector<int> pi(p.size(), 0);
    int i, j, k, l;
    for (i = 1; i < p.size(); i++) {
        for (j = 1; j <= i; j++) {
            bool q = true;
            for (k = 0, l = i - j + 1; k < j; k++, l++) {
                if (p[k] != p[l]) { q = false; break; }
            }
            if (q) pi[i] = j;
        }
    }
    return pi;
}

int KMP::Search(const std::string& Line_1, const std::string& Line_2) {
    if (Line_2.size() > Line_1.size()) return -1;
    std::vector<int> pi = pref(Line_2);
    int q = 0;
    for (int i = 0; i < Line_1.size(); i++) {
        while (q > 0 && Line_2[q] != Line_1[i]) q = pi[q];
        if (Line_2[q] == Line_1[i]) q++;
        if (q == Line_2.size()) return i - Line_2.size() + 1;
        //q = pi[q];
    }
    return -1;
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