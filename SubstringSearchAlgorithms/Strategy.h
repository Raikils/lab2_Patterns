#pragma once
#include <iostream>
#include <string>
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <map>
#include <vector>
#include "point.h"
#include <utility>
#include <deque>


/*!A class hierarchy that defines the algorithms for finding a contract*/
class  Substring_Search_Algorithms
{
public:
    /*!Virtual destructor*/
   virtual ~Substring_Search_Algorithms() {}
     /*!Virtual method accept for pattern visitor*/
   virtual std::string accept(class Visitor& v, const std::string& Line_1, const std::string& Line_2) = 0;
     /*!Virtual method for finding a substring*/
   virtual int Search(const std::string& Line_1, const std::string& Line_2) = 0;
     /*!Virtual method for finding comparative characters*/
   virtual std::vector<point> GetBreak_() = 0;
     /*!Virtual method for inserting comparative characters*/
   virtual void SetBreak_(const int& i, const int& j, const bool& q) = 0;
};




/*!Naive algorithm!*/
class  Naive : public Substring_Search_Algorithms
{
private:
    /*!Vector for saving comparative symbols!*/
    std::vector<point> break_;
public:

    std::vector<point> GetBreak_();
    void SetBreak_(const int& i, const int& j, const bool& q);
	std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//Rabina Karpa algorithm
class  Rabina_Karpa : public Substring_Search_Algorithms
{
private:
    std::vector<point> break_;
public:
    std::vector<point> GetBreak_();
    void SetBreak_(const int& i, const int& j, const bool& q);
    /*!Variables for hashing!*/
	long long d;
    long long q;
    long long power(long x, long y);
    /*!Constructor for Rabin Karp!*/
    Rabina_Karpa();
    std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//Horspool algorithm
class  Horspool : public Substring_Search_Algorithms
{
private:
    std::vector<point> break_;
public:
    std::vector<point> GetBreak_();
    void SetBreak_(const int& i, const int& j, const bool& q);
     /*!Method for creating shift table!*/
	std::vector<int> shift_table(const std::string& p);
    std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//KMP algorithm
class  KMP : public Substring_Search_Algorithms
{
private:
    std::vector<point> break_;
public:
    /*!Variable to store a table of possible matches!*/
    std::vector<std::deque<size_t> > container_table;
    std::vector<point> GetBreak_();
    void SetBreak_(const int& i, const int& j, const bool& q);
    std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};

//Boyer Moor algorithm
class  Boyer_Moor : public Substring_Search_Algorithms
{
private:
    std::vector<point> break_;
public:
    /*!Variable to store a table of stop symbols!*/
    typedef std::map<char, int> TStopTable_;
     /*!Variable to store a table of suffics!*/
    typedef std::map<int, int> TSufficsTable_;
    TStopTable_ stop_table_;
    TSufficsTable_ suffics_table_;
    std::vector<point> GetBreak_();
    void SetBreak_(const int& i, const int& j, const bool& q);
      /*!Prefix function!*/
    std::vector<int> prefix_func(const std::string& s);
    std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
    int Search(const std::string& Line_1, const std::string& Line_2);
};


  /*!Implement a class for use!*/
class  Substring_Search_Algorithms_ : public Substring_Search_Algorithms
{
private:
    std::vector<point> break_;

public:
    std::vector<point> GetBreak_();
    void SetBreak_(const int& i, const int& j, const bool& q);
    Substring_Search_Algorithms_(Substring_Search_Algorithms* comp);
    ~Substring_Search_Algorithms_();
	 std::string accept(Visitor& v, const std::string& Line_1, const std::string& Line_2);
     int Search(const std::string& Line_1, const std::string& Line_2);
private:
    Substring_Search_Algorithms* p;
};
