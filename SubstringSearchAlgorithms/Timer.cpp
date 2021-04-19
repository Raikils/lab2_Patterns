
#include "pch.h"
#include "Timer.h"

int Timer::Search(const std::string& Line_1, const std::string& Line_2)
{
	unsigned int start = clock();
	int r = Decorator::Search(Line_1, Line_2);
	_time = clock() - start;
	return r;
}


unsigned int Timer::time()
{
	return _time;
}