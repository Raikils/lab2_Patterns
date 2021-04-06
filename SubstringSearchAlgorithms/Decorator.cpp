#include "Decorator.h"

int Decorator::Search(const std::string& Line_1, const std::string& Line_2)
{
	return w->Search(Line_1, Line_2);
}
