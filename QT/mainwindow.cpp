#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include "MemoryUsage.h"
#include "MemoryUsage.cpp"
#include "Visitor.h"
#include "Visitor.cpp"
#include "Strategy.h"
#include "Strategy.cpp"
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





void MainWindow::on_listWidget_currentTextChanged(const QString &currentText)
{
    if(currentText == "Naive"){
        Substring_Search_Algorithms* list[]
        {
            new Naive()
        };
        ComplexityOfTheAlgorithm p;
        AmountOfMemoryOfTheAlgorithm m;
        std::string a = ui->lineEdit_1->text().toStdString();
        std::string b = ui->lineEdit_2->text().toStdString();
        QString c = QString::fromUtf8(list[0]->accept(m,a,b).c_str());
        QString d = QString::fromUtf8(list[0]->accept(p,a,b).c_str());
        ui->textBrowser_Memory->setText(c);
        ui->textBrowser_Complexity->setText(d);
    }
    if(currentText == "Rabin Karp"){
        Substring_Search_Algorithms* list[]
        {
            new Rabina_Karpa()
        };
        ComplexityOfTheAlgorithm p;
        AmountOfMemoryOfTheAlgorithm m;
        std::string a = ui->lineEdit_1->text().toStdString();
        std::string b = ui->lineEdit_2->text().toStdString();
        QString c = QString::fromUtf8(list[0]->accept(m,a,b).c_str());
        QString d = QString::fromUtf8(list[0]->accept(p,a,b).c_str());
        ui->textBrowser_Memory->setText(c);
        ui->textBrowser_Complexity->setText(d);
    }
    if(currentText == "KMP"){
        Substring_Search_Algorithms* list[]
        {
            new KMP()
        };
        ComplexityOfTheAlgorithm p;
        AmountOfMemoryOfTheAlgorithm m;
        std::string a = ui->lineEdit_1->text().toStdString();
        std::string b = ui->lineEdit_2->text().toStdString();
        QString c = QString::fromUtf8(list[0]->accept(m,a,b).c_str());
        QString d = QString::fromUtf8(list[0]->accept(p,a,b).c_str());
        ui->textBrowser_Memory->setText(c);
        ui->textBrowser_Complexity->setText(d);
    }
    if(currentText == "Horspool"){
        Substring_Search_Algorithms* list[]
        {
            new Horspool()
        };
        ComplexityOfTheAlgorithm p;
        AmountOfMemoryOfTheAlgorithm m;
        std::string a = ui->lineEdit_1->text().toStdString();
        std::string b = ui->lineEdit_2->text().toStdString();
        QString c = QString::fromUtf8(list[0]->accept(m,a,b).c_str());
        QString d = QString::fromUtf8(list[0]->accept(p,a,b).c_str());
        ui->textBrowser_Memory->setText(c);
        ui->textBrowser_Complexity->setText(d);
    }
}
