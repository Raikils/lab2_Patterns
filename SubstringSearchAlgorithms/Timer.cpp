
#include "pch.h"
#include "Timer.h"

Timer::Timer(Substring_Search_Algorithms* w) : Decorator(w), _time{ 0 } {}

int Timer::Search(const std::string& Line_1, const std::string& Line_2)
{
	unsigned int start = clock();
        const int n = 100;
        int r;
        for (int i = 0; i < n; i++) r = Decorator::Search(Line_1, Line_2);
        _time = 0.0 + (clock() - start + 0.0) / (n + 0.0);
	return r;
}


double Timer::time()
{
	return _time;
}
