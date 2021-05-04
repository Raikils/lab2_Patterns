#pragma once
#include "Strategy.h"
#include <string>

class  Visitor
{
public:
    virtual std::string visit(Naive *p, const std::string& Line_1, const std::string& Line_2) = 0;
    virtual std::string visit(Rabina_Karpa *p, const std::string& Line_1, const std::string& Line_2) = 0;
    virtual std::string visit(KMP *p, const std::string& Line_1, const std::string& Line_2) = 0;
    virtual std::string visit(Horspool *p, const std::string& Line_1, const std::string& Line_2) = 0;
    virtual std::string visit(Boyer_Moor *p, const std::string& Line_1, const std::string& Line_2) = 0;
};

class  ComplexityOfTheAlgorithm : public Visitor
{
    std::string visit(Naive *p, const std::string& Line_1, const std::string& Line_2);
    std::string visit(Rabina_Karpa *p, const std::string& Line_1, const std::string& Line_2);
    std::string visit(KMP *p, const std::string& Line_1, const std::string& Line_2);
    std::string visit(Horspool *p, const std::string& Line_1, const std::string& Line_2);
    std::string visit(Boyer_Moor *p, const std::string& Line_1, const std::string& Line_2);
};

class  AmountOfMemoryOfTheAlgorithm : public Visitor
{
    std::string visit(Naive* p, const std::string& Line_1, const std::string& Line_2);
    std::string visit(Rabina_Karpa* p, const std::string& Line_1, const std::string& Line_2);
    std::string visit(KMP* p, const std::string& Line_1, const std::string& Line_2);
    std::string visit(Horspool* p, const std::string& Line_1, const std::string& Line_2);
    std::string visit(Boyer_Moor* p, const std::string& Line_1, const std::string& Line_2);
};
