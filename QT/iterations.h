#ifndef ITERATIONS_H
#define ITERATIONS_H
#include "mainwindow.h"
#include "QTimer"
#include "QDateTime"
#include <string>
#include <QEventLoop>
#include <vector>
#include <QDebug>

class Iterations_
{
public:
    MainWindow* m;
    Iterations_(MainWindow* m1): m(m1) {}
    void print(Substring_Search_Algorithms_* p);
    virtual void preprint() = 0;
    virtual bool hash(const point &w) = 0;
};

class Iterations_Naive : public Iterations_
{
public:
    Iterations_Naive(MainWindow* m1): Iterations_(m1) {}
    void preprint();
    bool hash(const point &w);
    ~Iterations_Naive();
};

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

class Iterations_Horspool : public Iterations_
{
public:
    Iterations_Horspool(MainWindow* m1): Iterations_(m1) {}
    void preprint();
    bool hash(const point &w);
    ~Iterations_Horspool();
};

class Iterations_KMP : public Iterations_
{
public:

    Iterations_KMP(MainWindow* m1): Iterations_(m1) {}
    void preprint();
    bool hash(const point &w);
    ~Iterations_KMP();
};

class Iterations_Boyer_Moor : public Iterations_
{
public:
    Iterations_Boyer_Moor(MainWindow* m1): Iterations_(m1) {}
    void preprint();
    bool hash(const point &w);
    ~Iterations_Boyer_Moor();
};

#endif // ITERATIONS_H
