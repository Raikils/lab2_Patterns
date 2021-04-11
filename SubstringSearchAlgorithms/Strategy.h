#pragma once
#include <iostream>
#include <string>
#include <vector>


#ifdef SubstringSearchAlgorithms_lib
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif

//A class hierarchy that defines the algorithms for finding a contract
class DECLSPEC Substring_Search_Algorithms
{
public:
    virtual ~Substring_Search_Algorithms() {}
	virtual std::string accept(class Visitor& v, const std::string& Line_1, const std::string& Line_2) = 0;
    virtual int Search(const std::string& Line_1, const std::string& Line_2) = 0;
};

//Naive algorithm
class DECLSPEC Naive : public Substring_Search_Algorithms
{
public:
	std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//Rabina Karpa algorithm
class DECLSPEC Rabina_Karpa : public Substring_Search_Algorithms
{
public:
	long long d;
    long long q;
    long long power(int x, int y) { if (y == 0) return 1; else return power(x, y - 1) * x; }
    Rabina_Karpa();
	std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//Horspool algorithm
class DECLSPEC Horspool : public Substring_Search_Algorithms
{
public:
	std::vector<int> shift_table(const std::string& p);
    std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//KMP algorithm
class DECLSPEC KMP : public Substring_Search_Algorithms
{
public:
	std::vector<int> pref(const std::string& p);
    std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//Boyer Moor algorithm
class DECLSPEC Boyer_Moor : public Substring_Search_Algorithms
{
public:
	std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};


//Implement a class for use
class DECLSPEC Substring_Search_Algorithms_ : public Substring_Search_Algorithms
{
public:
    Substring_Search_Algorithms_(Substring_Search_Algorithms* comp);
    ~Substring_Search_Algorithms_();
	 std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
private:
    Substring_Search_Algorithms* p;
};
