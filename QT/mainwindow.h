#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QTimer"
#include "QDateTime"
#include "MemoryUsage.h"
#include "Visitor.h"
#include "Strategy.h"
#include "Decorator.h"
#include "Timer.h"
#include "point.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!Speed of showing Iterations*/
    int GetTimeIteration();
    /*!If all fields are full*/
    bool is_Iteration_works();
    /*!Show the iterations*/
    void SetText(const std::string& pattern);
    /*!Read the pattern text*/
    std::string GetPattern();
    /*!Read the text of substring*/
    std::string GetText();
    /*!Make iterations correct form(String)*/
    std::string GetPatIt();
    MainWindow(QWidget *parent = nullptr);
    /*!Destructor*/
    ~MainWindow();
private slots:
    /*!Start program work*/
    void on_pushButton_start_clicked();
    //void on_pushButton_2_clicked();
    /*!Change the state of Checkbox*/
    void on_checkBox_iterations_stateChanged(int arg1);
    /*!Clear the window text fields*/
    void on_pushButton_clear_clicked();

private:
    Ui::MainWindow *ui;
    bool _stop;
};
#endif // MAINWINDOW_H
