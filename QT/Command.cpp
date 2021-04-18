#include "Command.h"
#include <iostream>

void Iteration::next(const int &index){

    std::string r = m->GetPattern();
     std::string t = m->GetText();
    std::string p;
    std::string p1;
    p1.insert(0,1.25*index,' ');
    p.insert(0,t.size(),' ');
    p.insert(index,p1+r);
    m->SetText(p);
}

void NextIterationCommand::execute(const int &index){

    piteration->next(index);

}
