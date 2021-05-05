#pragma once
#include "Strategy.h"

class Decorator: public Substring_Search_Algorithm
{
private:
    Substring_Search_Algorithm* algorithm;
public:
    Decorator(Substring_Search_Algorithm* algorithm): algorithm(algorithm) {}
    Decorator(): algorithm(nullptr) {}
    std::string accept(class Visitor& v, const std::string& Text, const std::string& Pattern);
        std::vector<point> GetBreak_();
	void SetBreak_(const int& i, const int& j, const bool& q);
    int Search(const std::string& Text, const std::string& Pattern);
};

class  Improved_Rabina_Karpa : public Rabina_Karpa
{
private:
    Rabina_Karpa* RK_algorithm;
public:
    Improved_Rabina_Karpa(Rabina_Karpa* RK_algorithm) :RK_algorithm(RK_algorithm) {}
    Improved_Rabina_Karpa() : RK_algorithm(new Rabina_Karpa) {}
    int Search(const std::string& Text, const std::string& Pattern);
};
