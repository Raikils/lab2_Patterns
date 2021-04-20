#pragma once
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>


#ifdef SubstringSearchAlgorithms_lib
#define DECLSPEC __declspec(dllexport)
#else
#define DECLSPEC __declspec(dllimport)
#endif

//A class hierarchy that defines the algorithms for finding a contract
class  Substring_Search_Algorithms
{
public:
    virtual ~Substring_Search_Algorithms() {}
   virtual std::string accept(class Visitor& v, const std::string& Line_1, const std::string& Line_2) = 0;
   virtual int Search(const std::string& Line_1, const std::string& Line_2) = 0;
   virtual std::vector<int> GerBreak_() = 0;
   virtual void SetBreak_(const int& index) = 0;
};

//Naive algorithm
class  Naive : public Substring_Search_Algorithms
{
private:
    std::vector<int> break_;
public:
    std::vector<int> GerBreak_();
    void SetBreak_(const int& index);
	std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//Rabina Karpa algorithm
class  Rabina_Karpa : public Substring_Search_Algorithms
{
private:
    std::vector<int> break_;
public:
    std::vector<int> GerBreak_();
    void SetBreak_(const int& index);
	long long d;
    long long q;
    long long power(int x, int y) { if (y == 0) return 1; else return power(x, y - 1) * x; }
    Rabina_Karpa();
    std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//Horspool algorithm
class  Horspool : public Substring_Search_Algorithms
{
private:
    std::vector<int> break_;
public:
    std::vector<int> GerBreak_();
    void SetBreak_(const int& index);
	std::vector<int> shift_table(const std::string& p);
    std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//KMP algorithm
class  KMP : public Substring_Search_Algorithms
{
private:
    std::vector<int> break_;
public:
    std::vector<int> GerBreak_();
    void SetBreak_(const int& index);
	std::vector<int> pref(const std::string& p);
    std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//Boyer Moor algorithm
class  Boyer_Moor : public Substring_Search_Algorithms
{
private:
    std::vector<int> break_;
public:
    std::vector<int> GerBreak_();
    void SetBreak_(const int& index);
    std::vector<int> prefix_func(const std::string& s);
	std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};


//Implement a class for use
class  Substring_Search_Algorithms_ : public Substring_Search_Algorithms
{
private:
    std::vector<int> break_;
public:
    std::vector<int> GerBreak_();
    void SetBreak_(const int& index);
    Substring_Search_Algorithms_(Substring_Search_Algorithms* comp);
    ~Substring_Search_Algorithms_();
	 std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
     int Search(const std::string& Line_1, const std::string& Line_2);
private:
    Substring_Search_Algorithms* p;
};
