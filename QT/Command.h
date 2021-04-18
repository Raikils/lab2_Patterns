#include <string>
#include "mainwindow.h"

class Iteration
{
private:
   MainWindow *m;

public:

   Iteration(): m(0){}

   Iteration(MainWindow *m): m(m) {}
   void next(const int& index);

};

class Command
{
public:
    virtual ~Command() {}
    virtual void execute(const int &index) = 0;
protected:
    Command( Iteration* p ): piteration( p) {}
    Iteration * piteration;
};

class NextIterationCommand: public Command {
public:
    NextIterationCommand(Iteration* p) : Command(p){}
    void execute(const int &index);
};
