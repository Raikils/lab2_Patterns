#pragma once
#include "Strategy.h"
#include <string>

/*!A class hierarchy that defines the visit for finding a contract*/
class  Visitor
{
public:
    /*!Virtual method for Naive*/
    virtual std::string visit(Naive *p, const std::string& Text, const std::string& Pattern) = 0;
    /*!Virtual method for Rabin Karp*/
    virtual std::string visit(Rabina_Karpa *p, const std::string& Text, const std::string& Pattern) = 0;
    /*!Virtual method for KMP*/
    virtual std::string visit(KMP *p, const std::string& Text, const std::string& Pattern) = 0;
     /*!Virtual method for Horspool*/
    virtual std::string visit(Horspool *p, const std::string& Text, const std::string& Pattern) = 0;
     /*!Virtual method for Boyer Moor*/
    virtual std::string visit(Boyer_Moor *p, const std::string& Text, const std::string& Pattern) = 0;
};

/*!A class for finding complexity of algorithm*/
class  ComplexityOfTheAlgorithm : public Visitor
{
    /*!A method for finding complexity of Naive algorithm*/
    std::string visit(Naive *algorithm, const std::string& Text, const std::string& Pattern);
     /*!A method for finding complexity of Rabin Karp algorithm*/
    std::string visit(Rabina_Karpa *algorithm, const std::string& Text, const std::string& Pattern);
     /*!A method for finding complexity of KMP algorithm*/
    std::string visit(KMP *algorithm, const std::string& Text, const std::string& Pattern);
     /*!A method for finding complexity of Horspool algorithm*/
    std::string visit(Horspool *algorithm, const std::string& Text, const std::string& Pattern);
     /*!A method for finding complexity of Boyer Moor algorithm*/
    std::string visit(Boyer_Moor *algorithm, const std::string& Text, const std::string& Pattern);
};

/*!A class for finding used memory of algorithm*/
class  AmountOfMemoryOfTheAlgorithm : public Visitor
{
    /*!A class for finding used memory of Naive algorithm*/
    std::string visit(Naive* algorithm, const std::string& Text, const std::string& Pattern);
    /*!A class for finding used memory of Rabin Karp algorithm*/
    std::string visit(Rabina_Karpa* algorithm, const std::string& Text, const std::string& Pattern);
    /*!A class for finding used memory of KMP algorithm*/
    std::string visit(KMP* algorithmp, const std::string& Text, const std::string& Pattern);
    /*!A class for finding used memory of Horspool algorithm*/
    std::string visit(Horspool* algorithmp, const std::string& Text, const std::string& Pattern);
    /*!A class for finding used memory of Boyer Moor algorithm*/
    std::string visit(Boyer_Moor* algorithm, const std::string& Text, const std::string& Pattern);
};
