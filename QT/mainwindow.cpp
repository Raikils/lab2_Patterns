#include <cmath>
#include "MemoryUsage.h"
#include "MemoryUsage.cpp"
#include "Visitor.h"
#include "Visitor.cpp"
#include "Strategy.h"
#include "Strategy.cpp"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Decorator.h"
#include "Decorator.cpp"
#include "Timer.h"
#include "Timer.cpp"
#include "Command.h"
#include "point.h"

#include "QDateTime"

#include <string>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    enabled = true;
   }
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SetText(const std::string& pattern){
    QString r = pattern.c_str();
    ui->textBrowser_iterations->append(r);
    //qDebug() << pattern.c_str();
}



std::string MainWindow::GetPattern(){
   std::string r = ui->lineEdit_pattern->text().toStdString();
   return r;
}

std::string MainWindow::GetText()
{
    std::string r = ui->lineEdit_text->text().toStdString();
    return r;
}

std::string MainWindow::GetPatIt(){
   std::string r = ui->textBrowser_iterations->toPlainText().toStdString();
   return r;
}

void MainWindow::on_pushButton_start_clicked()
{
    if (!ui->listWidget_algorithms->currentItem()) return;
    ui->lineEdit_text->setReadOnly(true);
    ui->lineEdit_pattern->setReadOnly(true);
    Substring_Search_Algorithms_* p;
    if(ui->listWidget_algorithms->currentItem()->text()=="Naive")  p = new Substring_Search_Algorithms_(new Naive);
    if(ui->listWidget_algorithms->currentItem()->text()=="Rabin Karp") p = new Substring_Search_Algorithms_(new Rabina_Karpa);
    if(ui->listWidget_algorithms->currentItem()->text()=="KMP") p = new Substring_Search_Algorithms_(new KMP);
    if(ui->listWidget_algorithms->currentItem()->text()=="Horspool") p = new Substring_Search_Algorithms_(new Horspool);
    if(ui->listWidget_algorithms->currentItem()->text()=="Boyer Moor") p = new Substring_Search_Algorithms_(new Boyer_Moor);
    std::string text = ui->lineEdit_text->text().toStdString();
    std::string pattern = ui->lineEdit_pattern->text().toStdString();
    int position = p->Search(text,pattern);
    ui->textBrowser_Start->setText(QString::number(position));
    std::string s;
    if (position != -1) {
        if (position > 0) s+= text.substr(0, position);
        s += "<font color=green>";
        s += pattern;
        s += "</font>";
        if (position + pattern.size() - 1 < text.size() - 1) s += text.substr(position + pattern.size(), text.size() - 1);
        s = "<font size=20>" + s + "</font>";
    }
    if (ui->checkBox_time->isChecked()) {
        Timer *t = new Timer(p);
        t->Search(text,pattern);
        ui->textBrowser_Time->setText(QString::number(t->time()));
    }
    if (ui->checkBox_complexity->isChecked()) {
        ComplexityOfTheAlgorithm r;
        QString s = p->accept(r,text,pattern).c_str();
        ui->textBrowser_Complexity->setText(s);
    }
    if (ui->checkBox_memory->isChecked()) {
        /*  MemoryUsage mem;
    SetCurrentUsage();
        QString w = QString::number(n);
        if(mem.CurrentUsage()>0){
            SetCurrentUsage();
        }
        AmountOfMemoryOfTheAlgorithm m;
        QString m1 = p->accept(m,a,b).c_str();
        ui->textBrowser_Memory->setText(m1);*/
    }
    if (position != -1) {
        ui->textBrowser_iterations->append(s.c_str());
    }
    if (ui->checkBox_iterations->isChecked()) {
        if (position == -1) { s =text; s = "<font size=20>" + s + "</font>"; ui->textBrowser_iterations->append(s.c_str()); }
        for (const auto &index : p->GetBreak_()) {
            s.clear();
            s = "<pre><b><font size=20>";
            for (int i = 0; i < index.i - index.j; i++) s+= " ";
            if(index.j > 0) s += pattern.substr(0, index.j);
            if (index.q) s += "<font color=green>"; else s += "<font color=red>";
            s += pattern[index.j];
            s += "</font>";
            if(index.j != pattern.size() - 1) s += pattern.substr(index.j + 1, pattern.size() - 1);
            s += "</font></b></pre>";
            SetText(s);
            QEventLoop loop;
            QTimer::singleShot(1000, &loop, SLOT(quit()));
            loop.exec();
        }
    }
}




/*void MainWindow::on_pushButton_2_clicked()
{
   if(ui->listWidget_algorithms->currentItem()->text()=="Naive"){

       Substring_Search_Algorithms_* p = new Substring_Search_Algorithms_(new Naive);
       std::string a = ui->lineEdit_1->text().toStdString();
          ui->textBrowser_iterations->setText(a.c_str());
       std::string b = ui->lineEdit_2->text().toStdString();
       QString s1 = b.c_str();
        p->Search(a,b);
        Iteration it(this);
        std::vector<Command*> v;
        std::string s = ui->textBrowser_iterations->toPlainText().toStdString();
        std::vector<int> count;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < p->GetBreak_().size(); j++){
                 v.push_back(new NextIterationCommand(&it));
                 count.push_back(i);
            }
        }
          for(int j = 0; j <  p->GetBreak_().size(); j++){
             v[j]->execute(p->GetBreak_()[j]);
             QEventLoop loop;
             QTimer::singleShot(1000, &loop, SLOT(quit()));
             loop.exec();
         }
 }
   if(ui->listWidget->currentItem()->text()=="Rabin Karp"){

       Substring_Search_Algorithms_* p = new Substring_Search_Algorithms_(new Naive);
       std::string a = ui->lineEdit_1->text().toStdString();
       ui->textBrowser->setText(a.c_str());
       std::string b = ui->lineEdit_2->text().toStdString();
       QString s1 = b.c_str();
       p->Search(a,b);
       Iteration it(this);
       std::vector<Command*> v;
       std::string s = ui->textBrowser->toPlainText().toStdString();
       std::vector<int> count;
       for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < p->GerBreak_().size(); j++){
             if(p->GerBreak_()[j] == i){
                 v.push_back(new NextIterationCommand(&it));
                 count.push_back(i);
               }
            }
        }
        for(int j = 0; j <  v.size(); j++){
            v[j]->execute(count[j]);
            QEventLoop loop;
            QTimer::singleShot(1000, &loop, SLOT(quit()));
            loop.exec();
        }
 }
}*/


void MainWindow::on_checkBox_iterations_stateChanged(int arg1)
{
    ui->checkBox_more->setEnabled(arg1);
    ui->horizontalSlider_spead_iterations->setEnabled(arg1);
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit_pattern->clear();
    ui->lineEdit_text->clear();
    ui->lineEdit_text->setReadOnly(false);
    ui->lineEdit_pattern->setReadOnly(false);
    ui->textBrowser_Start->clear();
    ui->textBrowser_Complexity->clear();
    ui->textBrowser_Memory->clear();
    ui->textBrowser_Time->clear();
    ui->textBrowser_iterations->clear();
}
