#pragma once
#include "Strategy.h"
/*!
 * \brief The Decorator pattern
 * This class implements Decorator pattern
 */
class Decorator: public Substring_Search_Algorithms
{
private:
	Substring_Search_Algorithms* w;
public:
    /*!
     * \brief Decorator
     * Сonstructor with one parameter w
     */
	Decorator(Substring_Search_Algorithms* w): w(w) {}
    /*!
     * \brief Decorator
     * Standart constructor
     */
	Decorator(): w(nullptr) {}
    /*!Method accept for pattern visitor*/
	std::string accept(class Visitor& v, const std::string& Line_1, const std::string& Line_2);
    /*!
     * \brief GetBreak_
     * This method returns array of break points
     */
    std::vector<point> GetBreak_();
    /*!
     * \brief SetBreak_
     * This method adds break point
     */
	void SetBreak_(const int& i, const int& j, const bool& q);
    /*!Method for finding a substring*/
	int Search(const std::string& Line_1, const std::string& Line_2);
};

class  Improved_Rabina_Karpa : public Rabina_Karpa
{
private:
	Rabina_Karpa* r;
public:
	Improved_Rabina_Karpa(Rabina_Karpa* r) : r(r) {}
	Improved_Rabina_Karpa() : r(new Rabina_Karpa) {}
	int Search(const std::string& Line_1, const std::string& Line_2);
};
