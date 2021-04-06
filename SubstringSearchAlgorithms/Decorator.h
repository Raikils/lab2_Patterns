#pragma once
#include "Strategy.h"
//#include "Strategy.cpp"

class Decorator: public Substring_Search_Algorithms
{
private:
	Substring_Search_Algorithms* w;
public:
	Decorator(Substring_Search_Algorithms* w): w{w} {}
	Decorator(): w{nullptr} {}
	int Search(const std::string& Line_1, const std::string& Line_2);
};

