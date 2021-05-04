#include <cmath>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QDebug>
#include "iterations.h"
#include <thread>


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


int MainWindow::GetTimeIteration()
{
    return this->ui->horizontalSlider_spead_iterations->value();
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
        Substring_Search_Algorithms_* p1 = p;
        Timer *t = new Timer(p1);
        t->Search(text,pattern);
        ui->textBrowser_Time->setText(QString::number(t->time()));
        ui->checkBox_time->setChecked(false);
        delete t;
    }
    if (ui->checkBox_complexity->isChecked()) {

        ComplexityOfTheAlgorithm r;
        QString s = p->accept(r,text,pattern).c_str();
        ui->textBrowser_Complexity->setText(s);
        ui->checkBox_complexity->setChecked(false);
    }
   if (ui->checkBox_memory->isChecked()) {
        MemoryUsage mem;
        SetCurrentUsage();
        if(mem.CurrentUsage()>0){
            SetCurrentUsage();
        }
        AmountOfMemoryOfTheAlgorithm m;

        QString m1 = p->accept(m,text,pattern).c_str();
        ui->textBrowser_Memory->setText(m1);
        ui->checkBox_memory->setChecked(false);
    }
    if (position != -1) {
        ui->textBrowser_iterations->append(s.c_str());
    }
    if (ui->checkBox_iterations->isChecked() && ui->checkBox_time->isChecked()==false && ui->checkBox_complexity->isChecked()==false && ui->checkBox_memory->isChecked()==false) {
        if (position == -1) { s = text; s = "<font size=7>" + s + "</font>";
            ui->textBrowser_iterations->append(s.c_str()); }
        Iterations_ *it;
        if(ui->listWidget_algorithms->currentItem()->text()=="Naive") it = new Iterations_Naive(this);
        if(ui->listWidget_algorithms->currentItem()->text()=="Rabin Karp") it = new Iterations_Rabina_Karpa(this);
        if(ui->listWidget_algorithms->currentItem()->text()=="KMP") it = new Iterations_KMP(this);
        if(ui->listWidget_algorithms->currentItem()->text()=="Horspool") it = new Iterations_Horspool(this);
        if(ui->listWidget_algorithms->currentItem()->text()=="Boyer Moor") it = new Iterations_Boyer_Moor(this);
        it->print(p);
    }
    delete p;
}

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
