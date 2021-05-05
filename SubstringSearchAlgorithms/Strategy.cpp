#include "Strategy.h"
#include "Visitor.h"
#include "Timer.h"

  /*!Naive algorithm!*/

int Naive::Search(const std::string& Text, const std::string& Pattern) {
    break_.clear();
    if (Pattern.size() == 0) {
		return -1;
	}
    else if (Text.size() < Pattern.size()) {
		return -1;
	}
	 //Cycle for 1 character transition
    for (size_t i = 0; i <= Text.size() - Pattern.size(); i++) {
		size_t j;
		int pos = 0;
        bool isFound = true;
		// For each character with text check the pattern
        for (j = 0; j < Pattern.size(); j++) {
            if (Text[i + j] == Pattern[0] && isFound) {
                isFound = false;
				pos = i + j;
			}
			
            if (Text[i + j] != Pattern[j]) {
				SetBreak_(i + j, j, false);
                isFound = true;
				break;
			}
			else SetBreak_(i + j, j, true);
		
		}
		// Line_2 found
        if (j == Pattern.size()) {
			return pos;
		}
	}
	return -1;
}



/*!Implementation of the method accept!*/


std::string Naive::accept(Visitor& visitor, const std::string& Text, const std::string& Pattern) {
    return visitor.visit(this,Text,Pattern);
}


/*!Implementation of the method GetBreak_!*/






std::vector<point> Naive::GetBreak_() {
	return this->break_;
}


/*!Implementation of the method SetBreak_!*/


void Naive::SetBreak_(const int& i, const int& j, const bool& q) {
	break_.push_back(point(i, j, q));
}



/*!Implementation of the variable power!*/



long long Rabina_Karpa::power(long x, long y) { if (y == 0) return 1; else return (power(x, y - 1) * x) % q; }



/*!Implementation of the constructor Rabin Karp!*/
Rabina_Karpa::Rabina_Karpa() : d(26), q(101) {}


/*!Rabin Karp algorithm!*/



int Rabina_Karpa::Search(const std::string& Text, const std::string& Pattern) {
    break_.clear();
    if (Pattern.size() > Text.size()) return -1;
    if (Pattern.size() == 0) return -1;
    long long h = power(d, (Pattern.size() - 1)) % q, t = 0, t0 = 0;
    for (size_t i = 0; i < Pattern.size(); i++) {
        t = (d * t + Pattern[i]) % q;
        t0 = (d * t0 + Pattern[i]) % q;
	}
    for (size_t j = 0; j < Text.size() - Pattern.size() + 1; j++) {
		if (t == t0) {
			bool w = true;
            for (size_t k = 0; k < Pattern.size(); k++) {
                if (Pattern[k] != Text[j + k]) {
				w = false;
                SetBreak_(j + k, k, false);
                break;
                } else SetBreak_(j + k, k, true);
			}
			if (w) return j;
        } else { SetBreak_(j, 0, false); }
        t0 = (d * (t0 - Text[j] * h) + Text[j + Pattern.size()]) % q;
		if (t0 < 0) t0 += q;
	}
	return -1;
}




std::string Rabina_Karpa::accept(Visitor& visitor, const std::string& Text, const std::string& Pattern) {
    return visitor.visit(this,Text,Pattern);
}

std::vector<point> Rabina_Karpa::GetBreak_() {
	return this->break_;
}

void Rabina_Karpa::SetBreak_(const int& i, const int& j, const bool& q) {
	break_.push_back(point(i, j, q));
}


/*!Implementation of the method shift_table!*/





std::vector<int> Horspool::shift_table(const std::string& Pattern)
{
    std::vector<int> shift_table_;
    size_t i;
	for (i = 0; i < 256; i++) {
        shift_table_.push_back(Pattern.size());
	}
    for (i = 0; i < Pattern.size() - 1; i++) {
        shift_table_[Pattern[i]] = Pattern.size() - 1 - i;
	}
    return shift_table_;
}





int Horspool::Search(const std::string& Text, const std::string& Pattern) {
    break_.clear();
    if (Pattern.size() > Text.size()) return -1;
    if (Pattern.size() == 0) return -1;
    std::vector<int> t = shift_table(Pattern);
    size_t i = Pattern.size() - 1;
    while (i < Text.size()) {
		bool q = true;
        for (size_t k = 0; k < Pattern.size(); k++) {
            if (Pattern[Pattern.size() - 1 - k] != Text[i - k]) { q = false; SetBreak_(i - k, Pattern.size() - 1 - k, false); break; }
            else { SetBreak_(i - k, Pattern.size() - 1 - k, true); }
		}
        if (q) return i - Pattern.size() + 1;
        i = i + t[Text[i]];
	}
	return -1;
}



std::string Horspool::accept(Visitor& visitor, const std::string& Text, const std::string& Pattern) {
    return visitor.visit(this,Text,Pattern);
}

std::vector<point> Horspool::GetBreak_() {
	return this->break_;
}

void Horspool::SetBreak_(const int& i, const int& j, const bool& q) {
	break_.push_back(point(i, j, q));
}

/*!KMP algorithm!*/


int KMP::Search(const std::string& Text, const std::string& Pattern) {
    break_.clear();
    if (Pattern.size() == 0) {
            return -1;
        }
        else if (Text.size() < Pattern.size()) {
            return  -1;
        }
        size_t pos_in_first = 0;
        size_t pos_in_second = 0;
        std::deque<size_t> next_first_char;

        while (true) {
            if (Text[pos_in_second] == Pattern[pos_in_first] ) {
                if(pos_in_first!=0 && pos_in_first != Pattern.size() - 1){
                    SetBreak_(pos_in_second, pos_in_first, true);
                }
                if (pos_in_first == Pattern.size() - 1) {
                    SetBreak_(pos_in_second, pos_in_first, true);
                    return pos_in_second - pos_in_first;
                }
                else {
                    if (Text[pos_in_second] == Pattern[0]) {
                        SetBreak_(pos_in_second, 0, true);

                        next_first_char.push_back(pos_in_second);

                    }
                    pos_in_first++;
                    if (pos_in_second == Text.size() - 1) {
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
                if (Text[pos_in_second] != Pattern[0]) {

                    if (pos_in_second == Text.size() - 1) {
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


std::string KMP::accept(Visitor& visitor, const std::string& Text, const std::string& Pattern) {
    return visitor.visit(this,Text,Pattern);
}



std::vector<point> KMP::GetBreak_() {
	return this->break_;
}
void KMP::SetBreak_(const int& i, const int& j, const bool& q) {
    break_.push_back(point(i, j, q));
}


/*!Prefix function!*/



std::vector<int> Boyer_Moor::prefix_func(const std::string& Pattern) {
    std::vector<int> pref(Pattern.length());

    size_t k = 0;
    pref[0] = 0;
    for (size_t i = 1; i < Pattern.length(); ++i) {
        while (k > 0 && Pattern[k] != Pattern[i]) {
            k = pref[k - 1];
		}
        if (Pattern[k] == Pattern[i]) {
			++k;
		}
        pref[i] = k;
	}
    return pref;
}

/*!Boyer Moor algorithm!*/


int Boyer_Moor::Search(const std::string& Text, const std::string& Pattern) {
    break_.clear();
    if (Text.length() < Pattern.length()) {
		return -1;
	}

    if (!Pattern.length()) {
        return Text.length();
	}

    typedef std::map<char, int> TStopTable;
    typedef std::map<int, int> TSufficsTable;
	TStopTable stop_table;
	TSufficsTable suffics_table;

    for (size_t i = 0; i < Pattern.length(); ++i) {
        stop_table[Pattern[i]] = i;
        stop_table_[Pattern[i]] = i;
	}

    std::string rt(Pattern.rbegin(), Pattern.rend());
    std::vector<int> p = prefix_func(Pattern), pr = prefix_func(rt);
    for (size_t i = 0; i < Pattern.length() + 1; ++i) {
        suffics_table[i] = Pattern.length() - p.back();
        suffics_table_[i] = Pattern.length() - p.back();
	}

    for (int i = 1; i < Pattern.length(); ++i) {
		int j = pr[i];
                suffics_table[j] =std::min(suffics_table[j], i - pr[i] + 1);
                suffics_table_[j] =std::min(suffics_table[j], i - pr[i] + 1);
	}

    for (size_t shift = 0; shift <= Text.length() - Pattern.length();) {
        size_t pos = Pattern.length() - 1;

        while (Pattern[pos] == Text[pos + shift]) {
             SetBreak_(pos+shift,pos,true);
            if (pos == 0)
                return shift;
              --pos;

            }
        if (pos == Pattern.length() - 1) {
            TStopTable::const_iterator stop_symbol = stop_table.find(Text[pos + shift]);

            int stop_symbol_additional = pos - (stop_symbol != stop_table.end() ? stop_symbol->second : -1);

            shift += stop_symbol_additional;

            SetBreak_(shift,pos, false);
		}
		else {
            SetBreak_(pos+shift,pos, false);
            shift += suffics_table[Pattern.length() - pos - 1];

		}

	}

	return -1;
}



std::string Boyer_Moor::accept(Visitor& visitor, const std::string& Text, const std::string& Pattern) {
    return visitor.visit(this,Text,Pattern);
}

std::vector<point> Boyer_Moor::GetBreak_() {
	return this->break_;
}

void Boyer_Moor::SetBreak_(const int& i, const int& j, const bool& q) {
	break_.push_back(point(i, j, q));
}

