#include "Decorator.h"

int Decorator::Search(const std::string& Text, const std::string& Pattern)
{
    return algorithm->Search(Text, Pattern);
}
std::string Decorator::accept(class Visitor& visitor, const std::string& Text, const std::string& Pattern)
{
	return "";
}

std::vector<point> Decorator::GetBreak_() {
        return {};
}

void Decorator::SetBreak_(const int& i, const int& j, const bool& q) {

}

int Improved_Rabina_Karpa::Search(const std::string& Text, const std::string& Pattern)
{
    RK_algorithm->q = 18014398241046527;
    RK_algorithm->d = std::rand() + 1;
    return RK_algorithm->Search(Text, Pattern);
}
