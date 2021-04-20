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

#include "QDateTime"

#include <string>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   }
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::SetText(const std::string& pattern){
    QString r = pattern.c_str();
    ui->textBrowser->append(r);

}



std::string MainWindow::GetPattern(){
   std::string r = ui->lineEdit_2->text().toStdString();
   return r;
}

std::string MainWindow::GetText()
{
    std::string r = ui->lineEdit_1->text().toStdString();
    return r;
}

std::string MainWindow::GetPatIt(){
   std::string r = ui->textBrowser->toPlainText().toStdString();
   return r;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->listWidget->currentItem()->text()=="Naive"){
        MemoryUsage mem;
        SetCurrentUsage();
        Substring_Search_Algorithms_* p = new Substring_Search_Algorithms_(new Naive);
        std::string a = ui->lineEdit_1->text().toStdString();
        std::string b = ui->lineEdit_2->text().toStdString();
        ComplexityOfTheAlgorithm r;
        QString s = p->accept(r,a,b).c_str();

        int n = p->Search(a,b);
        QString w = QString::number(n);
        Timer *t = new Timer(p);
        t->Search(a,b);
        QString t1 = QString::number(t->time());
        if(mem.CurrentUsage()>0){
            SetCurrentUsage();
        }
        AmountOfMemoryOfTheAlgorithm m;
        QString m1 = p->accept(m,a,b).c_str();
        ui->textBrowser_Memory->setText(m1);
        ui->textBrowser_Time->setText(t1);
        ui->textBrowser_Start->setText(w);
        ui->textBrowser_Complexity->setText(s);


    }
    if(ui->listWidget->currentItem()->text()=="Rabin Karp"){
        MemoryUsage mem;
        SetCurrentUsage();
        Substring_Search_Algorithms_* p = new Substring_Search_Algorithms_(new Rabina_Karpa);
        std::string a = ui->lineEdit_1->text().toStdString();
        std::string b = ui->lineEdit_2->text().toStdString();
        ComplexityOfTheAlgorithm r;
        QString s = p->accept(r,a,b).c_str();
        int n = p->Search(a,b);
        QString w = QString::number(n);
        Timer *t = new Timer(p);
        t->Search(a,b);
        QString t1 = QString::number(t->time());
        if(mem.CurrentUsage()>0){
            SetCurrentUsage();
        }
        AmountOfMemoryOfTheAlgorithm m;
        QString m1 = p->accept(m,a,b).c_str();
          ui->textBrowser_Memory->setText(m1);
        //ui->textBrowser_Time->setText(t1);
        ui->textBrowser_Start->setText(w);
        ui->textBrowser_Complexity->setText(s);
    }
    if(ui->listWidget->currentItem()->text()=="KMP"){
        MemoryUsage mem;
        SetCurrentUsage();
        Substring_Search_Algorithms_* p = new Substring_Search_Algorithms_(new KMP);
        std::string a = ui->lineEdit_1->text().toStdString();
        std::string b = ui->lineEdit_2->text().toStdString();
        ComplexityOfTheAlgorithm r;
        QString s = p->accept(r,a,b).c_str();
        int n = p->Search(a,b);
        QString w = QString::number(n);
        Timer *t = new Timer(p);
        t->Search(a,b);
        QString t1 = QString::number(t->time());
        if(mem.CurrentUsage()>0){
            SetCurrentUsage();
        }
        AmountOfMemoryOfTheAlgorithm m;
        QString m1 = p->accept(m,a,b).c_str();
        ui->textBrowser_Memory->setText(m1);
        //ui->textBrowser_Time->setText(t1);
        ui->textBrowser_Start->setText(w);
        ui->textBrowser_Complexity->setText(s);
    }
    if(ui->listWidget->currentItem()->text()=="Horspool"){
        MemoryUsage mem;
        SetCurrentUsage();
        Substring_Search_Algorithms_* p = new Substring_Search_Algorithms_(new Horspool);
        std::string a = ui->lineEdit_1->text().toStdString();
        std::string b = ui->lineEdit_2->text().toStdString();
        ComplexityOfTheAlgorithm r;
        QString s = p->accept(r,a,b).c_str();
        int n = p->Search(a,b);
        QString w = QString::number(n);
        Timer *t = new Timer(p);
        t->Search(a,b);
        QString t1 = QString::number(t->time());
        if(mem.CurrentUsage() > 0){
            SetCurrentUsage();
        }
        AmountOfMemoryOfTheAlgorithm m;
        QString m1 = p->accept(m,a,b).c_str();
        ui->textBrowser_Memory->setText(m1);
        ui->textBrowser_Time->setText(t1);
        ui->textBrowser_Start->setText(w);
        ui->textBrowser_Complexity->setText(s);
    }
    if(ui->listWidget->currentItem()->text()=="Boyer Moor"){
        MemoryUsage mem;
        SetCurrentUsage();
        Substring_Search_Algorithms_* p = new Substring_Search_Algorithms_(new Boyer_Moor);
        std::string a = ui->lineEdit_1->text().toStdString();
        std::string b = ui->lineEdit_2->text().toStdString();
        ComplexityOfTheAlgorithm r;
        QString s = p->accept(r,a,b).c_str();
        int n = p->Search(a,b);
        QString w = QString::number(n);
        Timer *t = new Timer(p);
        t->Search(a,b);
        QString t1 = QString::number(t->time());
        if(mem.CurrentUsage() > 0){
            SetCurrentUsage();
        }
        AmountOfMemoryOfTheAlgorithm m;
        QString m1 = p->accept(m,a,b).c_str();
        ui->textBrowser_Memory->setText(m1);
        ui->textBrowser_Time->setText(t1);
        ui->textBrowser_Start->setText(w);
        ui->textBrowser_Complexity->setText(s);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
   if(ui->listWidget->currentItem()->text()=="Naive"){

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
}

