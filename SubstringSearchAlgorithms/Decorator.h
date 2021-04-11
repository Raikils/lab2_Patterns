#pragma once
#include "Strategy.h"

#ifdef SubstringSearchAlgorithms_lib
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif

class DECLSPEC Decorator: public Substring_Search_Algorithms
{
private:
	Substring_Search_Algorithms* w;
public:
	Decorator(Substring_Search_Algorithms* w): w(w) {}
	Decorator(): w(nullptr) {}
	int Search(const std::string& Line_1, const std::string& Line_2);
};

class DECLSPEC Improved_Rabina_Karpa : public Rabina_Karpa
{
private:
	Rabina_Karpa* r;
public:
	Improved_Rabina_Karpa(Rabina_Karpa* r) : r(r) {}
	Improved_Rabina_Karpa() : r(new Rabina_Karpa) {}
	int Search(const std::string& Line_1, const std::string& Line_2);
};