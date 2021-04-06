#pragma once
#include "Decorator.h"
#include <ctime>

class Timer : public Decorator
{
private:
	unsigned int _time;
public:
	Timer(Substring_Search_Algorithms* w) : Decorator(w), _time{0} {}
	int Search(const std::string& Line_1, const std::string& Line_2);
	unsigned int time();
};

