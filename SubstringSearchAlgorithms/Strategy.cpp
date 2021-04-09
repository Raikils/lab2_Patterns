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
		bool q = true;
		// For each character with text check the pattern
		for (j = 0; j < Line_2.size(); j++) {
			if (Line_1[i + j] == Line_2[0] && q == true) {
				q = false;
				pos = i + j;
			}
			
			if (Line_1[i + j] != Line_2[j]) {
				q = true;
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

std::string Naive::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return v.visit(this,Line_1,Line_2);
}
Rabina_Karpa::Rabina_Karpa() : d(26), q(101) {}

int Rabina_Karpa::Search(const std::string& Line_1, const std::string& Line_2) {
	if (Line_2.size() > Line_1.size()) return -1;
	int h = power(d, (Line_2.size() - 1)) % q, t = 0, t0 = 0;
	for (int i = 0; i < Line_2.size(); i++) {
		t = (d * t + Line_2[i]) % q;
		t0 = (d * t0 + Line_1[i]) % q;
	}
	for (int j = 0; j < Line_1.size() - Line_2.size() + 1; j++) {
		if (t == t0) {
			bool w = true;
			for (int k = 0; k < Line_2.size(); k++) {
				if (Line_2[k] != Line_1[j + k]) { w = false; break; }
			}
			if (w) return j;
		}
		t0 = (d * (t0 - Line_1[j] * h) + Line_1[j + Line_2.size()]) % q;
		if (t0 < 0) t0 += q;
	}
	return -1;
}

std::string Rabina_Karpa::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return v.visit(this,Line_1,Line_2);
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

std::string Horspool::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return v.visit(this,Line_1,Line_2);
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
std::string KMP::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return v.visit(this,Line_1,Line_2);
}


int Boyer_Moor::Search(const std::string& Line_1, const std::string& Line_2) {
    int pos = 0;
    return pos;
}

std::string Boyer_Moor::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return v.visit(this,Line_1,Line_2);
}

//Implement a class for use
Substring_Search_Algorithms_::Substring_Search_Algorithms_(Substring_Search_Algorithms* comp) : p(comp) {}

Substring_Search_Algorithms_::~Substring_Search_Algorithms_() { delete p; }

std::string Substring_Search_Algorithms_::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return p->accept(v,Line_1,Line_2);
}

int Substring_Search_Algorithms_::Search(const std::string& Line_1, const std::string& Line_2) {
    return p->Search(Line_1, Line_2);
}