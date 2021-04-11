#include "Decorator.h"

int Decorator::Search(const std::string& Line_1, const std::string& Line_2)
{
	return w->Search(Line_1, Line_2);
}

int Improved_Rabina_Karpa::Search(const std::string& Line_1, const std::string& Line_2)
{
	r->q = 18014398241046527;
	r->d = std::rand() + 1;
	return r->Search(Line_1, Line_2);
}