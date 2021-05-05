#include "iterations.h"

//Iterations_::Iterations_(MainWindow *window1)

void Iterations_::print(Substring_Search_Algorithm * algorithm)
{
    preprint();
    std::string s;
    std::string pattern = window->GetPattern();
    for (const auto &index : algorithm->GetBreak_()) {
        if (!window->is_Iteration_works()) break;
        if (hash(index)) {
        s.clear();
        s = "<pre><font size=20>";
        for (size_t i = 0; i < index.i - index.j; i++) s+= " ";
        if(index.j > 0) s += pattern.substr(0, index.j);
        if (index.q) s += "<font color=green>"; else s += "<font color=red>";
        s += pattern[index.j];
        s += "</font>";
        if(index.j != pattern.size() - 1) s += pattern.substr(index.j + 1, pattern.size() - 1);
        s += "</font></pre>";
          window->SetText(s);
        }

        QEventLoop loop;
        QTimer::singleShot(window->GetTimeIteration(), &loop, SLOT(quit()));
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
    std::string pattern = window->GetPattern();
    pattern_hash = 0;
    Rabina_Karpa *algorithm = new Rabina_Karpa;
    for (size_t i = 0; i < pattern.size(); i++) {
        pattern_hash = (algorithm->d * pattern_hash + pattern[i]) % algorithm->q;
    }
    window->SetText("q=" + std::to_string(algorithm->q) + " d=" + std::to_string(algorithm->d));
    window->SetText("hash(" + pattern + ")=" + std::to_string(pattern_hash));
    delete algorithm;
}

bool Iterations_Rabina_Karpa::hash(const point &w)
{
    long long window1 = 0;
    Rabina_Karpa *algorithm = new Rabina_Karpa;
    std::string text = window->GetText();
    for (size_t i = w.i; i < w.i + window->GetPattern().size(); i++) {
        window1 = (algorithm->d * window1 +text[i]) % algorithm->q;
    }
    if (!w.q) {
        if (pattern_hash != window1) {window->SetText("hash(" + text + ")=" + std::to_string(window1)); return false; }
    }
    if (w.j == 0) window->SetText("<pre><font size=20>" + text + "</font></pre>");
    return true;
}

void Iterations_Horspool::preprint()
{
    Horspool* algorithm = new Horspool;
    std::vector<int> pre = algorithm->shift_table(window->GetPattern());
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

    window->SetText(s);
    std::string s1 = window->GetText(); s1 = "<font size=20>" + s1 + "</font>"; window->SetText(s1);
}

bool Iterations_Horspool::hash(const point &w)
{
    return true;
}

void Iterations_KMP::preprint()
{
    KMP* algorithm = new KMP;
    algorithm->Search(window->GetText(),window->GetPattern());
    std::string t;
    for(size_t i = 0; i < algorithm->container_table.size(); i++){
          for(size_t j = 0; j < algorithm->container_table[i].size(); j++){
             t += std::to_string(algorithm->container_table[i][j])+"   ";
        }
    }
    delete algorithm;
    window->SetText(t);

}



bool Iterations_KMP::hash(const point &w)
{
    return true;
}


void Iterations_Boyer_Moor::preprint()
{

    Boyer_Moor* algorithm = new Boyer_Moor;
    algorithm->Search(window->GetText(),window->GetPattern());
    std::string t;

    for(size_t i = 0; i < algorithm->prefix_func(window->GetPattern()).size(); i++){
              t += std::to_string(algorithm->prefix_func(window->GetPattern())[i])+"   ";
    }
    window->SetText(t);
    t.clear();
    for(size_t i = 0; i < algorithm->suffics_table_.size(); i++){
              t += std::to_string(algorithm->suffics_table_[i])+"   ";
    }
    window->SetText(t);
    t.clear();
    for(size_t i = 0; i < algorithm->stop_table_.size(); i++){
         t += std::to_string(algorithm->stop_table_[i])+"   ";
    }
    delete algorithm;
    window->SetText(t);
}

bool Iterations_Boyer_Moor::hash(const point &w)
{
    return true;
}
