#include "Timer.h"

Timer::Timer(Substring_Search_Algorithm* algorithm) : Decorator(algorithm), _time{ 0 } {}

int Timer::Search(const std::string& Text, const std::string& Pattern)
{
	unsigned int start = clock();
        const int n = 1000;
        int r;
        for (int i = 0; i < n; i++) r = Decorator::Search(Text, Pattern);
        _time = 0.0 + (clock() - start + 0.0) / (n + 0.0);
	return r;
}


double Timer::time()
{
	return _time;
}
