#ifndef ITERATIONS_H
#define ITERATIONS_H
#include "mainwindow.h"
#include "QTimer"
#include "QDateTime"
#include <string>
#include <QEventLoop>
#include <vector>
#include <QDebug>
/*!Basic Class for the visualization of iterations*/
class Iterations_
{
public:
    MainWindow* m;
    /*!Iterations of algorythm*/
    Iterations_(MainWindow* m1): m(m1) {}
    /*!Print iterations*/
    void print(Substring_Search_Algorithms_* p);
    /*!Extra data print*/
    virtual void preprint() = 0;
    /*!Hash-function print*/
    virtual bool hash(const point &w) = 0;
};
/*!Iterations of the Naive algorythm*/
class Iterations_Naive : public Iterations_
{
public:
    Iterations_Naive(MainWindow* m1): Iterations_(m1) {}
    void preprint();
    bool hash(const point &w);
    ~Iterations_Naive();
};
/*!Iterations of the Rabin-Karp algorythm*/
class Iterations_Rabina_Karpa : public Iterations_
{
private:
    long long pattern_hash;
public:
    Iterations_Rabina_Karpa(MainWindow* m1): Iterations_(m1) {}
    void preprint();
    bool hash(const point &w);
    ~Iterations_Rabina_Karpa();
};
/*!Iterations of the Horspool algorythm*/
class Iterations_Horspool : public Iterations_
{
public:
    Iterations_Horspool(MainWindow* m1): Iterations_(m1) {}
    void preprint();
    bool hash(const point &w);
    ~Iterations_Horspool();
};
/*!Iterations of the KMP algorythm*/
class Iterations_KMP : public Iterations_
{
public:

    Iterations_KMP(MainWindow* m1): Iterations_(m1) {}
    void preprint();
    bool hash(const point &w);
    ~Iterations_KMP();
};
/*!Iterations of the Boyer-Moor algorythm*/
class Iterations_Boyer_Moor : public Iterations_
{
public:
    Iterations_Boyer_Moor(MainWindow* m1): Iterations_(m1) {}
    void preprint();
    bool hash(const point &w);
    ~Iterations_Boyer_Moor();
};

#endif // ITERATIONS_H
