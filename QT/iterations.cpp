#include "iterations.h"

//Iterations_::Iterations_(MainWindow *m1)

void Iterations_::print(Substring_Search_Algorithms_ *p)
{
    preprint();
    std::string s;
    std::string pattern = m->GetPattern();
    for (const auto &index : p->GetBreak_()) {
        if (hash(index)) {
        s.clear();
        s = "<pre><b><font size=20>";
        for (int i = 0; i < index.i - index.j; i++) s+= " ";
        if(index.j > 0) s += pattern.substr(0, index.j);
        if (index.q) s += "<font color=green>"; else s += "<font color=red>";
        s += pattern[index.j];
        s += "</font>";
        if(index.j != pattern.size() - 1) s += pattern.substr(index.j + 1, pattern.size() - 1);
        s += "</font></b></pre>";
        m->SetText(s);
        }
        QEventLoop loop;
        QTimer::singleShot(1000, &loop, SLOT(quit()));
        loop.exec();
    }
}

void Iterations_Naive::preprint()
{
    return;
}

bool Iterations_Naive::hash(const point &w)
{
    return true;
}

Iterations_Naive::~Iterations_Naive()
{

}

void Iterations_Rabina_Karpa::preprint()
{
    std::string pattern = m->GetPattern();
    pattern_hash = 0;
    Rabina_Karpa *r = new Rabina_Karpa;
    for (int i = 0; i < pattern.size(); i++) {
        pattern_hash = (r->d * pattern_hash + pattern[i]) % r->q;
    }
    m->SetText("q=" + std::to_string(r->q) + " d=" + std::to_string(r->d));
    m->SetText("hash(" + pattern + ")=" + std::to_string(pattern_hash));
    delete r;
}

bool Iterations_Rabina_Karpa::hash(const point &w)
{
    long long window = 0;
    Rabina_Karpa *r = new Rabina_Karpa;
    std::string text = m->GetText();
    for (int i = w.i; i < w.i + m->GetPattern().size(); i++) {
        window = (r->d * window +text[i]) % r->q;
    }
    if (!w.q) {
        if (pattern_hash != window) {m->SetText("hash(" + text + ")=" + std::to_string(window)); return false; }
        else return true;
    } else return true;
}

void Iterations_Horspool::preprint()
{
    Horspool* h = new Horspool;
    std::vector<int> pre = h->shift_table(m->GetPattern());
    std::string s = "";
    char a;
    for (int i = 0; i < 256; i++) {
        a = i;
        if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122)) {
        s += "(";
        s += std::string(1, a);
        s += "|";
        s += std::to_string(pre[i]);
        s += ")";
        }
    }
    delete h;
    m->SetText(s);
    std::string s1 = m->GetText(); s1 = "<font size=20>" + s1 + "</font>"; m->SetText(s1);
}

bool Iterations_Horspool::hash(const point &w)
{
    return true;
}
