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
    void SetText(const std::string& pattern);
    std::string GetPattern();
    std::string GetText();
    std::string GetPatIt();
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_pushButton_start_clicked();
    //void on_pushButton_2_clicked();

    void on_checkBox_iterations_stateChanged(int arg1);

    void on_pushButton_clear_clicked();

private:
    Ui::MainWindow *ui;
    bool enabled;
};
#endif // MAINWINDOW_H
