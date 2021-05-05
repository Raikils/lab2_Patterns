#pragma once
#include "Decorator.h"
#include <ctime>


class  Timer : public Decorator
{
private:
        double _time;
public:
        Timer(Substring_Search_Algorithm* w);
	int Search(const std::string& Line_1, const std::string& Line_2);
        double time();
};
