#pragma once
#include "Decorator.h"
#include <ctime>

#ifdef SubstringSearchAlgorithms_lib
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif

class DECLSPEC Timer : public Decorator
{
private:
	unsigned int _time;
public:
	Timer(Substring_Search_Algorithms* w) : Decorator(w), _time{0} {}
	int Search(const std::string& Line_1, const std::string& Line_2);
	unsigned int time();
};

