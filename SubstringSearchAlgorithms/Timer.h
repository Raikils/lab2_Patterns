#pragma once
#include "Decorator.h"
#include <ctime>

/*!
 * \brief The Timer class
 * This class measures time
 */

class  Timer : public Decorator
{
private:
        double _time;
public:
        /*!
         * \brief Timer
         * Сonstructor with one parameter w
         */
        Timer(Substring_Search_Algorithms* w);
        /*!Method for finding a substring*/
	int Search(const std::string& Line_1, const std::string& Line_2);
    /*!
         * \brief time
         * This method returns running time of the last algorithm
         */
        double time();
};
