#include "Command.h"
#include <iostream>

void Iteration::next(const point &index){

    /*std::string r = m->GetPattern();
     std::string t = m->GetText();
    std::string p;
    std::string p1;
    p1.insert(0,1.25*index,' ');
    p.insert(0,t.size(),' ');
    p.insert(index,p1+r);
    m->SetText(p);*/
    std::string r = m->GetPattern();
    std::string t = m->GetText();
    std::string s;
    s = "<pre>";
    for (int i = 0; i < index.i - index.j; i++) s+= " ";
    if(index.j > 0) s += r.substr(0, index.j);
    if (index.q) s += "<font color=green>"; else s += "<font color=red>";
    s += r[index.j];
    s += "</font>";
    if(index.j != r.size() - 1) s += r.substr(index.j + 1, r.size() - 1);
    s += "</pre>";
    m->SetText(s);
}

void NextIterationCommand::execute(const point &index){

    piteration->next(index);

}
