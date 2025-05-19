#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "NelderMead.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonOptimize_clicked();

private:
    Ui::MainWindow *ui;

    // Парсинг ввода
    bool parseInput(QVector<double>& initialPoint, NelderMeadParams& params);
};
#endif // MAINWINDOW_H
