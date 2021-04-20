#include "pch.h"
#include "Strategy.h"
#include "Visitor.h"
#include "Timer.h"
//Implement of algorithms
int Naive::Search(const std::string& Line_1, const std::string& Line_2) {
   if (Line_2.size() == 0) {
		return -1;
	}
	else if (Line_1.size() < Line_2.size()) {
		return -1;
	}
	 //Cycle for 1 character transition
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
				SetBreak_(i + j);
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

std::vector<int> Naive::GerBreak_() {
	return this->break_;
}

void Naive::SetBreak_(const int& index) {
	break_.push_back(index);
}

Rabina_Karpa::Rabina_Karpa() : d(26), q(101) {}

int Rabina_Karpa::Search(const std::string& Line_1, const std::string& Line_2) {
	if (Line_2.size() > Line_1.size()) return -1;
        if (Line_2.size() == 0) return -1;
        long long h = power(d, (Line_2.size() - 1)) % q, t = 0, t0 = 0;
	for (int i = 0; i < Line_2.size(); i++) {
		t = (d * t + Line_2[i]) % q;
		t0 = (d * t0 + Line_1[i]) % q;
	}
	for (int j = 0; j < Line_1.size() - Line_2.size() + 1; j++) {
		if (t == t0) {
			bool w = true;
			for (int k = 0; k < Line_2.size(); k++) {
				if (Line_2[k] != Line_1[j + k]) { w = false; SetBreak_(j + k); break; }
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

std::vector<int> Rabina_Karpa::GerBreak_() {
	return this->break_;
}

void Rabina_Karpa::SetBreak_(const int& index) {
	break_.push_back(index);
}

std::vector<int> Horspool::shift_table(const std::string& p)
{
    std::vector<int> a;
    int i;
    for (i = 0; i < 256; i++) {
        a.push_back(p.size());
    }
    for (i = 0; i < p.size() - 1; i++) {
        a[p[i]] = p.size() - 1 - i;
    }
    return a;
}
int Horspool::Search(const std::string& Line_1, const std::string& Line_2) {
    if (Line_2.size() > Line_1.size()) return -1;
    if (Line_2.size() == 0) return -1;
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

std::vector<int> Horspool::GerBreak_() {
	return this->break_;
}

void Horspool::SetBreak_(const int& index) {
	break_.push_back(index);
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
        if (Line_2.size() == 0) return -1;
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

std::vector<int> KMP::GerBreak_() {
	return this->break_;
}
void KMP::SetBreak_(const int& index) {
	break_.push_back(index);
}

std::vector<int> Boyer_Moor::prefix_func(const std::string& s) {
	std::vector<int> p(s.length());

	int k = 0;
	p[0] = 0;
	for (int i = 1; i < s.length(); ++i) {
		while (k > 0 && s[k] != s[i]) {
			k = p[k - 1];
		}
		if (s[k] == s[i]) {
			++k;
		}
		p[i] = k;
	}
	return p;
}


int Boyer_Moor::Search(const std::string& Line_1, const std::string& Line_2) {
	if (Line_1.length() < Line_2.length()) {
		return -1;
	}

	if (!Line_2.length()) {
		return -1;
	}

	typedef std:: map<char, int> TStopTable;
	typedef std:: map<int, int> TSufficsTable;
	TStopTable stop_table;
	TSufficsTable suffics_table;

	for (int i = 0; i < Line_2.length(); ++i) {
		stop_table[Line_2[i]] = i;
	}

	std::string rt(Line_2.rbegin(), Line_2.rend());
	std::vector<int> p = prefix_func(Line_2), pr = prefix_func(rt);
	for (int i = 0; i < Line_2.length() + 1; ++i) {
		suffics_table[i] = Line_2.length() - p.back();
	}

	for (int i = 1; i < Line_2.length(); ++i) {
		int j = pr[i];
		suffics_table[j] = std::min(suffics_table[j], i - pr[i] + 1);
	}

	for (int shift = 0; shift <= Line_1.length() - Line_2.length();) {
		int pos = Line_2.length() - 1;

		while (Line_2[pos] == Line_1[pos + shift]) {
			if (pos == 0) return shift;
			--pos;
		}

		if (pos == Line_2.length() - 1) {
			TStopTable::const_iterator stop_symbol = stop_table.find(Line_1[pos + shift]);
			int stop_symbol_additional = pos - (stop_symbol != stop_table.end() ? stop_symbol->second : -1);
			shift += stop_symbol_additional;
		}
		else {
			shift += suffics_table[Line_2.length() - pos - 1];
		}
	}

	return -1;
}

std::string Boyer_Moor::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return v.visit(this,Line_1,Line_2);
}

std::vector<int> Boyer_Moor::GerBreak_() {
	return this->break_;
}

void Boyer_Moor::SetBreak_(const int& index) {
	break_.push_back(index);
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

std::vector<int> Substring_Search_Algorithms_::GerBreak_() {
	return p->GerBreak_();
}

void Substring_Search_Algorithms_::SetBreak_(const int& index) {
	p->SetBreak_(index);
}
