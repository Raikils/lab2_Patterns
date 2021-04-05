#include "Strategy.h"

//Implement of algorithms
int Naive::Search(const std::string& Line_1, const std::string& Line_2) {
   if (Line_2.size() == 0) {
		return -1;
	}
	else if (Line_1.size() < Line_2.size()) {
		return -1;
	}
	// Cycle for 1 character transition
	for (size_t i = 0; i <= Line_1.size() - Line_2.size(); i++) {
		size_t j;
		int pos = 0;
		// For each character with text check the pattern
		for (j = 0; j < Line_2.size(); j++) {
			if (Line_1[i + j] == Line_2[0]) {
				pos = i + j;
			}
			if (Line_1[i + j] != Line_2[j]) {
				break;
			}
		}
		// Line_2 found
		if (j == Line_2.size()) {
			return pos;
		}
	}
	return -1;
}

int Rabina_Karpa::Search(const std::string& Line_1, const std::string& Line_2) {
    if (Line_2.size() == 0) {
		return -1;
	}
	else if (Line_1.size() < Line_2.size()) {
		return -1;
	}
	size_t j = 0;
	int pos = 0;
	int pattern_hash = 0;
	int text_hash = 0;
	int h = 1;
	int d = 10;
	for (size_t i = 0; i < Line_2.size() - 1; i++) {
		h = (h * d) % (d + 3);
	}
	// Calculate the hash value for the pattern and text
	for (size_t i = 0; i < Line_2.size(); i++) {
		pattern_hash = (d * pattern_hash + Line_2[i]) % (d + 3);
		text_hash = (d * text_hash + Line_1[i]) % (d + 3);
	}
	// Find a match
	for (size_t i = 0; i <= Line_1.size() - Line_2.size(); i++) {
		if (pattern_hash == text_hash) {
			
			if (Line_1[i + j] == Line_2[0]) {
				pos = i + j;
			}
			for (j = 0; j < Line_2.size(); j++) {
				if (Line_1[i + j] != Line_2[j]) {
					break;
				}
			}
			if (j == Line_2.size()) {
				return pos;
			}
		}
		if (i < Line_1.size() - Line_2.size()) {
			text_hash = (d * (text_hash - Line_1[i] * h) + Line_1[i + Line_2.size()]) % (d + 3);
			if (text_hash < 0) {
				text_hash = (text_hash + (d + 3));
			}
		}
	}
	return -1;
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
int Horspool::Search(const std::string& Line_1, const std::string& Line_2) {
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
    return p->Search(Line_1, Line_2);
}