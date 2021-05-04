#include "iterations.h"

//Iterations_::Iterations_(MainWindow *m1)

/*!Print the iterations of algorythms function*/
void Iterations_::print(Substring_Search_Algorithms_ *p)
{
    preprint();
    std::string s;
    std::string pattern = m->GetPattern();
    for (const auto &index : p->GetBreak_()) {
        if (!m->is_Iteration_works()) break;
        if (hash(index)) {
        s.clear();
        s = "<pre><font size=20>";
        for (int i = 0; i < index.i - index.j; i++) s+= " ";
        if(index.j > 0) s += pattern.substr(0, index.j);
        if (index.q) s += "<font color=green>"; else s += "<font color=red>";
        s += pattern[index.j];
        s += "</font>";
        if(index.j != pattern.size() - 1) s += pattern.substr(index.j + 1, pattern.size() - 1);
        s += "</font></pre>";
          m->SetText(s);
        }

        QEventLoop loop;
        QTimer::singleShot(m->GetTimeIteration(), &loop, SLOT(quit()));
        loop.exec();
    }
}


/*!No extra structures for Naive algorythm*/
void Iterations_Naive::preprint()
{
    return;
}
/*!No hash-function for Naive algorythm*/
bool Iterations_Naive::hash(const point &w)
{
    return true;
}
/*!Destructor of Iterations_Naive*/
Iterations_Naive::~Iterations_Naive()
{

}
/*!Print data which is used for hashing*/
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
/*!Print hash-values of substrings*/
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
    }
    if (w.j == 0) m->SetText("<pre><font size=20>" + text + "</font></pre>");
    return true;
}
/*!Offset-table for Horspool algorythm*/
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

    m->SetText(s);
    std::string s1 = m->GetText(); s1 = "<font size=20>" + s1 + "</font>"; m->SetText(s1);
}
/*!No hash-function for Horspool algorythm*/
bool Iterations_Horspool::hash(const point &w)
{
    return true;
}
/*!Preprint for KMP algorythm*/
void Iterations_KMP::preprint()
{
    KMP* k = new KMP;
    k->Search(m->GetText(),m->GetPattern());
    std::string t;
    for(int i = 0; i < k->container_table.size(); i++){
          for(int j = 0; j < k->container_table[i].size(); j++){
             t += std::to_string(k->container_table[i][j])+"   ";
        }
    }
    delete k;
    m->SetText(t);

}


/*!No hash-function for KMP algorythm*/
bool Iterations_KMP::hash(const point &w)
{
    return true;
}

/*!Prefix and suffics functions for Boyer-Moor algorythm*/
void Iterations_Boyer_Moor::preprint()
{

    Boyer_Moor* b = new Boyer_Moor;
    b->Search(m->GetText(),m->GetPattern());
    std::string t;

    for(int i = 0; i < b->prefix_func(m->GetPattern()).size(); i++){
              t += std::to_string(b->prefix_func(m->GetPattern())[i])+"   ";
    }
    m->SetText(t);
    t.clear();
    for(int i = 0; i < b->suffics_table_.size(); i++){
              t += std::to_string(b->suffics_table_[i])+"   ";
    }
    m->SetText(t);
    t.clear();
    for(int i = 0; i < b->stop_table_.size(); i++){
         t += std::to_string(b->stop_table_[i])+"   ";
    }
    delete b;
    m->SetText(t);
}
/*!No hash-function for Boyer-Moor algorythm*/
bool Iterations_Boyer_Moor::hash(const point &w)
{
    return true;
}
