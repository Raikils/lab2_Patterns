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
    return -1 * this->ui->horizontalSlider_spead_iterations->value();
}

bool MainWindow::is_Iteration_works()
{
    return _stop;
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
     SetCurrentUsage();
    if (!ui->listWidget_algorithms->currentItem()) return;
    ui->lineEdit_text->setReadOnly(true);
    ui->lineEdit_pattern->setReadOnly(true);
    ui->textBrowser_Start->clear();
    ui->textBrowser_Complexity->clear();
    ui->textBrowser_Memory->clear();
    ui->textBrowser_Time->clear();
    ui->textBrowser_iterations->clear();
    _stop = true;
      SetCurrentUsage();
    Substring_Search_Algorithm* algorithm;
    if(ui->listWidget_algorithms->currentItem()->text()=="Naive")  algorithm = new Naive;
    if(ui->listWidget_algorithms->currentItem()->text()=="Rabin Karp") algorithm = new Rabina_Karpa;
    if(ui->listWidget_algorithms->currentItem()->text()=="KMP") algorithm = new KMP;
    if(ui->listWidget_algorithms->currentItem()->text()=="Horspool") algorithm = new Horspool;
    if(ui->listWidget_algorithms->currentItem()->text()=="Boyer Moor") algorithm = new Boyer_Moor;
    std::string text = ui->lineEdit_text->text().toStdString();
    std::string pattern = ui->lineEdit_pattern->text().toStdString();
    int position = algorithm->Search(text,pattern);
    ui->textBrowser_Start->setText(QString::number(position));
    std::string s;

    if (position != -1) {
        if (position > 0) s+= text.substr(0, position);
        s += "<font color=green>";
        s += pattern;
        s += "</font>";
        if (position + pattern.size() - 1 < text.size() - 1) s += text.substr(position + pattern.size(), text.size() - 1);
        s = "<pre><b><font size=20>" + s + "</font></b></pre>";
    }
    if (ui->checkBox_time->isChecked()) {

        Timer *t = new Timer(algorithm);
        t->Search(text,pattern);
        ui->textBrowser_Time->setText(QString::number(t->time()));
        delete t;
    }
    if (ui->checkBox_complexity->isChecked()) {

        ComplexityOfTheAlgorithm complexy;
        QString s = algorithm->accept(complexy,text,pattern).c_str();
        ui->textBrowser_Complexity->setText(s);
    }
   if (ui->checkBox_memory->isChecked()) {

        MemoryUsage memory;
        if(memory.CurrentUsage()>0){
            SetCurrentUsage();
        }
        AmountOfMemoryOfTheAlgorithm amount;
        QString amount_string = algorithm->accept(amount,text,pattern).c_str();
        ui->textBrowser_Memory->setText(amount_string);
    }
    if (position != -1) {
        ui->textBrowser_iterations->append(s.c_str());
    }
    if (ui->checkBox_iterations->isChecked()) {

        ui->horizontalSlider_spead_iterations->setEnabled(false);
        if (position == -1) { s = text; s = "<pre><b><font size=20>" + s + "</font></b></pre>";
            ui->textBrowser_iterations->append(s.c_str()); }
        Iterations_ *it;
        if(ui->listWidget_algorithms->currentItem()->text()=="Naive") it = new Iterations_Naive(this);
        if(ui->listWidget_algorithms->currentItem()->text()=="Rabin Karp") it = new Iterations_Rabina_Karpa(this);
        if(ui->listWidget_algorithms->currentItem()->text()=="KMP") it = new Iterations_KMP(this);
        if(ui->listWidget_algorithms->currentItem()->text()=="Horspool") it = new Iterations_Horspool(this);
        if(ui->listWidget_algorithms->currentItem()->text()=="Boyer Moor") it = new Iterations_Boyer_Moor(this);
        it->print(algorithm);
        ui->horizontalSlider_spead_iterations->setEnabled(true);

    }
    delete algorithm;
    ui->lineEdit_text->setReadOnly(false);
    ui->lineEdit_pattern->setReadOnly(false);
}

void MainWindow::on_checkBox_iterations_stateChanged(int arg1)
{
    ui->horizontalSlider_spead_iterations->setEnabled(arg1);
}

void MainWindow::on_pushButton_clear_clicked()
{
    _stop = false;
}
