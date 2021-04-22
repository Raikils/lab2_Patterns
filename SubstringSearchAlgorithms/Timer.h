#pragma once
#include "Decorator.h"
#include <ctime>

#ifdef SubstringSearchAlgorithms_lib
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif

class  Timer : public Decorator
{
private:
        double _time;
public:
        Timer(Substring_Search_Algorithms* w);
	int Search(const std::string& Line_1, const std::string& Line_2);
        double time();
};
