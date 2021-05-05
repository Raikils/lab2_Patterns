#include "Strategy.h"
#include "Visitor.h"
#include "Timer.h"

  /*!Naive algorithm!*/
/*!
\code
int Naive::Search(const std::string& Line_1, const std::string& Line_2) {
    break_.clear();
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
                SetBreak_(i + j, j, false);
                q = true;
                break;
            }
            else SetBreak_(i + j, j, true);

        }
        // Line_2 found
        if (j == Line_2.size()) {
            return pos;
        }
    }
    return -1;
}


\endcode
*/


int Naive::Search(const std::string& Line_1, const std::string& Line_2) {
    break_.clear();
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
				SetBreak_(i + j, j, false);
				q = true;
				break;
			}
			else SetBreak_(i + j, j, true);
		
		}
		// Line_2 found
		if (j == Line_2.size()) {
			return pos;
		}
	}
	return -1;
}

/*!
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/


/*!Implementation of the method accept!*/

/*!
\code

std::string Naive::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
    return v.visit(this,Line_1,Line_2);
}


\endcode
*/
std::string Naive::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return v.visit(this,Line_1,Line_2);
}

/*!
\param[in] v input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implementation of the method GetBreak_!*/

/*!
\code

std::vector<point> Naive::GetBreak_() {
    return this->break_;
}


\endcode
*/

std::vector<point> Naive::GetBreak_() {
	return this->break_;
}


/*!Implementation of the method SetBreak_!*/

/*!
\code

void Naive::SetBreak_(const int& i, const int& j, const bool& q) {
    break_.push_back(point(i, j, q));
}


\endcode
*/

void Naive::SetBreak_(const int& i, const int& j, const bool& q) {
	break_.push_back(point(i, j, q));
}

/*!
\param[in] i input parametr
\param[in] j input parametr
\param[in] q input parametr
*/


/*!Implementation of the variable power!*/

/*!
\code

long long Rabina_Karpa::power(long x, long y) { if (y == 0) return 1; else return (power(x, y - 1) * x) % q; }


\endcode
*/

long long Rabina_Karpa::power(long x, long y) { if (y == 0) return 1; else return (power(x, y - 1) * x) % q; }

/*!
\param[in] x input parametr
\param[in] y input parametr
*/

/*!Implementation of the constructor Rabin Karp!*/
Rabina_Karpa::Rabina_Karpa() : d(26), q(115249) {}


/*!Rabin Karp algorithm!*/

/*!
\code

int Rabina_Karpa::Search(const std::string& Line_1, const std::string& Line_2) {
    break_.clear();
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
                if (Line_2[k] != Line_1[j + k]) {
                w = false;
                SetBreak_(j + k, k, false);
                break;
                } else SetBreak_(j + k, k, true);
            }
            if (w) return j;
        } else { SetBreak_(j, 0, false); }
        t0 = (d * (t0 - Line_1[j] * h) + Line_1[j + Line_2.size()]) % q;
        if (t0 < 0) t0 += q;
    }
    return -1;
}
\endcode
*/


int Rabina_Karpa::Search(const std::string& Line_1, const std::string& Line_2) {
    break_.clear();
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
				if (Line_2[k] != Line_1[j + k]) { 
				w = false;
                SetBreak_(j + k, k, false);
                break;
                } else SetBreak_(j + k, k, true);
			}
			if (w) return j;
        } else { SetBreak_(j, 0, false); }
		t0 = (d * (t0 - Line_1[j] * h) + Line_1[j + Line_2.size()]) % q;
		if (t0 < 0) t0 += q;
	}
	return -1;
}

/*!
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/



std::string Rabina_Karpa::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return v.visit(this,Line_1,Line_2);
}

std::vector<point> Rabina_Karpa::GetBreak_() {
	return this->break_;
}

void Rabina_Karpa::SetBreak_(const int& i, const int& j, const bool& q) {
	break_.push_back(point(i, j, q));
}


/*!Implementation of the method shift_table!*/

/*!
\code

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


\endcode
*/

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

/*!
\param[in] p input parametr
*/

/*!Horspool algorithm!*/

/*!
\code

int Horspool::Search(const std::string& Line_1, const std::string& Line_2) {
    break_.clear();
    if (Line_2.size() > Line_1.size()) return -1;
    if (Line_2.size() == 0) return -1;
    std::vector<int> t = shift_table(Line_2);
    int i = Line_2.size() - 1;
    while (i < Line_1.size()) {
        bool q = true;
        for (int k = 0; k < Line_2.size(); k++) {
            if (Line_2[Line_2.size() - 1 - k] != Line_1[i - k]) { q = false; SetBreak_(i - k, Line_2.size() - 1 - k, false); break; }
            else { SetBreak_(i - k, Line_2.size() - 1 - k, true); }
        }
        if (q) return i - Line_2.size() + 1;
        i = i + t[Line_1[i]];
    }
    return -1;
}

\endcode
*/


int Horspool::Search(const std::string& Line_1, const std::string& Line_2) {
    break_.clear();
    if (Line_2.size() > Line_1.size()) return -1;
	if (Line_2.size() == 0) return -1;
	std::vector<int> t = shift_table(Line_2);
	int i = Line_2.size() - 1;
	while (i < Line_1.size()) {
		bool q = true;
		for (int k = 0; k < Line_2.size(); k++) {
            if (Line_2[Line_2.size() - 1 - k] != Line_1[i - k]) { q = false; SetBreak_(i - k, Line_2.size() - 1 - k, false); break; }
            else { SetBreak_(i - k, Line_2.size() - 1 - k, true); }
		}
		if (q) return i - Line_2.size() + 1;
		i = i + t[Line_1[i]];
	}
	return -1;
}

/*!
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/


std::string Horspool::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return v.visit(this,Line_1,Line_2);
}

std::vector<point> Horspool::GetBreak_() {
	return this->break_;
}

void Horspool::SetBreak_(const int& i, const int& j, const bool& q) {
	break_.push_back(point(i, j, q));
}

/*!KMP algorithm!*/

/*!
\code

int KMP::Search(const std::string& Line_1, const std::string& Line_2) {
    break_.clear();
    if (Line_2.size() == 0) {
            return -1;
        }
        else if (Line_1.size() < Line_2.size()) {
            return  -1;
        }
        size_t pos_in_first = 0;
        size_t pos_in_second = 0;
        std::deque<size_t> next_first_char;

        while (true) {
            if (Line_1[pos_in_second] == Line_2[pos_in_first] ) {
                if(pos_in_first!=0 && pos_in_first != Line_2.size() - 1){
                    SetBreak_(pos_in_second, pos_in_first, true);
                }
                if (pos_in_first == Line_2.size() - 1) {
                    SetBreak_(pos_in_second, pos_in_first, true);
                    return pos_in_second - pos_in_first;
                }
                else {
                    if (Line_1[pos_in_second] == Line_2[0]) {
                        SetBreak_(pos_in_second, 0, true);

                        next_first_char.push_back(pos_in_second);

                    }
                    pos_in_first++;
                    if (pos_in_second == Line_1.size() - 1) {
                        return  -1;
                    }
                    else {
                        pos_in_second++;
                    }
                }
            }
            else if (next_first_char.size() > 1) {
                SetBreak_(pos_in_second, pos_in_first, false);
                container_table.push_back(next_first_char);
                pos_in_first = pos_in_second - next_first_char[1];
                next_first_char.pop_front();

            }
            else {
                SetBreak_(pos_in_second, pos_in_first, false);
                pos_in_first = 0;
                if (Line_1[pos_in_second] != Line_2[0]) {

                    if (pos_in_second == Line_1.size() - 1) {
                        return  -1;
                    }
                    else {
                        pos_in_second++;

                    }
                }

                next_first_char.clear();
            }
        }
}


\endcode
*/

int KMP::Search(const std::string& Line_1, const std::string& Line_2) {
    break_.clear();
    if (Line_2.size() == 0) {
            return -1;
        }
        else if (Line_1.size() < Line_2.size()) {
            return  -1;
        }
        size_t pos_in_first = 0;
        size_t pos_in_second = 0;
        std::deque<size_t> next_first_char;

        while (true) {
            if (Line_1[pos_in_second] == Line_2[pos_in_first] ) {
                if(pos_in_first!=0 && pos_in_first != Line_2.size() - 1){
                    SetBreak_(pos_in_second, pos_in_first, true);
                }
                if (pos_in_first == Line_2.size() - 1) {
                    SetBreak_(pos_in_second, pos_in_first, true);
                    return pos_in_second - pos_in_first;
                }
                else {
                    if (Line_1[pos_in_second] == Line_2[0]) {
                        SetBreak_(pos_in_second, 0, true);

                        next_first_char.push_back(pos_in_second);

                    }
                    pos_in_first++;
                    if (pos_in_second == Line_1.size() - 1) {
                        return  -1;
                    }
                    else {
                        pos_in_second++;
                    }
                }
            }
            else if (next_first_char.size() > 1) {
                SetBreak_(pos_in_second, pos_in_first, false);
                container_table.push_back(next_first_char);
                pos_in_first = pos_in_second - next_first_char[1];
                next_first_char.pop_front();

            }
            else {
                SetBreak_(pos_in_second, pos_in_first, false);
                pos_in_first = 0;
                if (Line_1[pos_in_second] != Line_2[0]) {

                    if (pos_in_second == Line_1.size() - 1) {
                        return  -1;
                    }
                    else {
                        pos_in_second++;

                    }
                }

                next_first_char.clear();
            }
        }
}


/*!
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

std::string KMP::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return v.visit(this,Line_1,Line_2);
}



std::vector<point> KMP::GetBreak_() {
	return this->break_;
}
void KMP::SetBreak_(const int& i, const int& j, const bool& q) {
    break_.push_back(point(i, j, q));
}


/*!Prefix function!*/

/*!
\code

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


\endcode
*/


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

/*!
\param[in] s input parametr
*/


/*!Boyer Moor algorithm!*/

/*!
\code

int Boyer_Moor::Search(const std::string& Line_1, const std::string& Line_2) {
    break_.clear();
    if (Line_1.length() < Line_2.length()) {
        return -1;
    }

    if (!Line_2.length()) {
        return Line_1.length();
    }

    typedef std::map<char, int> TStopTable;
    typedef std::map<int, int> TSufficsTable;
    TStopTable stop_table;
    TSufficsTable suffics_table;

    for (int i = 0; i < Line_2.length(); ++i) {
        stop_table[Line_2[i]] = i;
        stop_table_[Line_2[i]] = i;
    }

    std::string rt(Line_2.rbegin(), Line_2.rend());
    std::vector<int> p = prefix_func(Line_2), pr = prefix_func(rt);
    for (int i = 0; i < Line_2.length() + 1; ++i) {
        suffics_table[i] = Line_2.length() - p.back();
        suffics_table_[i] = Line_2.length() - p.back();
    }

    for (int i = 1; i < Line_2.length(); ++i) {
        int j = pr[i];
                suffics_table[j] =std::min(suffics_table[j], i - pr[i] + 1);
                suffics_table_[j] =std::min(suffics_table[j], i - pr[i] + 1);
    }

    for (int shift = 0; shift <= Line_1.length() - Line_2.length();) {
        int pos = Line_2.length() - 1;

        while (Line_2[pos] == Line_1[pos + shift]) {
             SetBreak_(pos+shift,pos,true);
            if (pos == 0)
                return shift;
              --pos;

            }
        if (pos == Line_2.length() - 1) {
            TStopTable::const_iterator stop_symbol = stop_table.find(Line_1[pos + shift]);

            int stop_symbol_additional = pos - (stop_symbol != stop_table.end() ? stop_symbol->second : -1);

            shift += stop_symbol_additional;

            SetBreak_(shift,pos, false);
        }
        else {
            SetBreak_(pos+shift,pos, false);
            shift += suffics_table[Line_2.length() - pos - 1];

        }

    }

    return -1;
}



\endcode
*/


int Boyer_Moor::Search(const std::string& Line_1, const std::string& Line_2) {
    break_.clear();
    if (Line_1.length() < Line_2.length()) {
		return -1;
	}

	if (!Line_2.length()) {
        return -1;
	}

    typedef std::map<char, int> TStopTable;
    typedef std::map<int, int> TSufficsTable;
	TStopTable stop_table;
	TSufficsTable suffics_table;

	for (int i = 0; i < Line_2.length(); ++i) {
		stop_table[Line_2[i]] = i;
        stop_table_[Line_2[i]] = i;
	}

	std::string rt(Line_2.rbegin(), Line_2.rend());
	std::vector<int> p = prefix_func(Line_2), pr = prefix_func(rt);
	for (int i = 0; i < Line_2.length() + 1; ++i) {
		suffics_table[i] = Line_2.length() - p.back();
        suffics_table_[i] = Line_2.length() - p.back();
	}

	for (int i = 1; i < Line_2.length(); ++i) {
		int j = pr[i];
                suffics_table[j] =std::min(suffics_table[j], i - pr[i] + 1);
                suffics_table_[j] =std::min(suffics_table[j], i - pr[i] + 1);
	}

	for (int shift = 0; shift <= Line_1.length() - Line_2.length();) {
		int pos = Line_2.length() - 1;

		while (Line_2[pos] == Line_1[pos + shift]) {
             SetBreak_(pos+shift,pos,true);
            if (pos == 0)
                return shift;
              --pos;

            }
		if (pos == Line_2.length() - 1) {
			TStopTable::const_iterator stop_symbol = stop_table.find(Line_1[pos + shift]);

            int stop_symbol_additional = pos - (stop_symbol != stop_table.end() ? stop_symbol->second : -1);

            shift += stop_symbol_additional;

            SetBreak_(shift,pos, false);
		}
		else {
            SetBreak_(pos+shift,pos, false);
			shift += suffics_table[Line_2.length() - pos - 1];

		}

	}

	return -1;
}

/*!
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

std::string Boyer_Moor::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return v.visit(this,Line_1,Line_2);
}

std::vector<point> Boyer_Moor::GetBreak_() {
	return this->break_;
}

void Boyer_Moor::SetBreak_(const int& i, const int& j, const bool& q) {
	break_.push_back(point(i, j, q));
}

/*!Implement a class for use!*/
Substring_Search_Algorithms_::Substring_Search_Algorithms_(Substring_Search_Algorithms* comp) : p(comp) {}

Substring_Search_Algorithms_::~Substring_Search_Algorithms_() { delete p; }

/*!Implement method of accept!*/

/*!
\code

std::string Substring_Search_Algorithms_::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
    return p->accept(v,Line_1,Line_2);
}

\endcode
*/

std::string Substring_Search_Algorithms_::accept(Visitor& v, const std::string& Line_1, const std::string& Line_2) {
	return p->accept(v,Line_1,Line_2);
}

/*!
\param[in] v input parametr
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implement method of Search!*/

/*!
\code

int Substring_Search_Algorithms_::Search(const std::string& Line_1, const std::string& Line_2) {
    return p->Search(Line_1, Line_2);
}
\endcode
*/

int Substring_Search_Algorithms_::Search(const std::string& Line_1, const std::string& Line_2) {
    return p->Search(Line_1, Line_2);
}

/*!
\param[in] Line_1 input parametr
\param[in] Line_2 input parametr
*/

/*!Implement method of GetBreak_!*/

/*!
\code

std::vector<point> Substring_Search_Algorithms_::GetBreak_() {
    return p->GetBreak_();
}

\endcode
*/


std::vector<point> Substring_Search_Algorithms_::GetBreak_() {
	return p->GetBreak_();
}

/*!Implement method of SetBreak_!*/

/*!
\code

void Substring_Search_Algorithms_::SetBreak_(const int& i, const int& j, const bool& q) {
    p->SetBreak_(i, j, q);
}

\endcode
*/


void Substring_Search_Algorithms_::SetBreak_(const int& i, const int& j, const bool& q) {
	p->SetBreak_(i, j, q);
}

/*!
\param[in] i input parametr
\param[in] j input parametr
\param[in] q input parametr
*/
