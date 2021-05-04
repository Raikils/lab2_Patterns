#pragma once
#include "Strategy.h"
#include <string>

/*!A class hierarchy that defines the visit for finding a contract*/
class  Visitor
{
public:
    /*!Virtual method for Naive*/
    virtual std::string visit(Naive *p, const std::string& Line_1, const std::string& Line_2) = 0;
    /*!Virtual method for Rabin Karp*/
    virtual std::string visit(Rabina_Karpa *p, const std::string& Line_1, const std::string& Line_2) = 0;
    /*!Virtual method for KMP*/
    virtual std::string visit(KMP *p, const std::string& Line_1, const std::string& Line_2) = 0;
     /*!Virtual method for Horspool*/
    virtual std::string visit(Horspool *p, const std::string& Line_1, const std::string& Line_2) = 0;
     /*!Virtual method for Boyer Moor*/
    virtual std::string visit(Boyer_Moor *p, const std::string& Line_1, const std::string& Line_2) = 0;
};

/*!A class for finding complexity of algorithm*/
class  ComplexityOfTheAlgorithm : public Visitor
{
    /*!A method for finding complexity of Naive algorithm*/
    std::string visit(Naive *p, const std::string& Line_1, const std::string& Line_2);
     /*!A method for finding complexity of Rabin Karp algorithm*/
    std::string visit(Rabina_Karpa *p, const std::string& Line_1, const std::string& Line_2);
     /*!A method for finding complexity of KMP algorithm*/
    std::string visit(KMP *p, const std::string& Line_1, const std::string& Line_2);
     /*!A method for finding complexity of Horspool algorithm*/
    std::string visit(Horspool *p, const std::string& Line_1, const std::string& Line_2);
     /*!A method for finding complexity of Boyer Moor algorithm*/
    std::string visit(Boyer_Moor *p, const std::string& Line_1, const std::string& Line_2);
};

/*!A class for finding used memory of algorithm*/
class  AmountOfMemoryOfTheAlgorithm : public Visitor
{
    /*!A class for finding used memory of Naive algorithm*/
    std::string visit(Naive* p, const std::string& Line_1, const std::string& Line_2);
    /*!A class for finding used memory of Rabin Karp algorithm*/
    std::string visit(Rabina_Karpa* p, const std::string& Line_1, const std::string& Line_2);
    /*!A class for finding used memory of KMP algorithm*/
    std::string visit(KMP* p, const std::string& Line_1, const std::string& Line_2);
    /*!A class for finding used memory of Horspool algorithm*/
    std::string visit(Horspool* p, const std::string& Line_1, const std::string& Line_2);
    /*!A class for finding used memory of Boyer Moor algorithm*/
    std::string visit(Boyer_Moor* p, const std::string& Line_1, const std::string& Line_2);
};
