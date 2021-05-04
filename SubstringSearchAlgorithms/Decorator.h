#pragma once
#include "Strategy.h"

class Decorator: public Substring_Search_Algorithms
{
private:
	Substring_Search_Algorithms* w;
public:
	Decorator(Substring_Search_Algorithms* w): w(w) {}
	Decorator(): w(nullptr) {}
	std::string accept(class Visitor& v, const std::string& Line_1, const std::string& Line_2);
        std::vector<point> GetBreak_();
	void SetBreak_(const int& i, const int& j, const bool& q);
	int Search(const std::string& Line_1, const std::string& Line_2);
};

class  Improved_Rabina_Karpa : public Rabina_Karpa
{
private:
	Rabina_Karpa* r;
public:
	Improved_Rabina_Karpa(Rabina_Karpa* r) : r(r) {}
	Improved_Rabina_Karpa() : r(new Rabina_Karpa) {}
	int Search(const std::string& Line_1, const std::string& Line_2);
};
