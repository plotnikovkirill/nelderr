#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QDoubleValidator>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Валидаторы для числового ввода
    QDoubleValidator* doubleValidator = new QDoubleValidator(this);
    QIntValidator* intValidator = new QIntValidator(1, 100000, this);

    ui->lineEditInitialPoint->setValidator(doubleValidator);
    ui->lineEditAlpha->setValidator(doubleValidator);
    ui->lineEditGamma->setValidator(doubleValidator);
    ui->lineEditBeta->setValidator(doubleValidator);
    ui->lineEditSigma->setValidator(doubleValidator);
    ui->lineEditStep->setValidator(doubleValidator);
    ui->lineEditTolerance->setValidator(new QDoubleValidator(1e-10, 1.0, 10, this));
    ui->lineEditMaxIter->setValidator(intValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::parseInput(QVector<double>& initialPoint, NelderMeadParams& params)
{
    // Парсинг начальной точки
    QStringList parts = ui->lineEditInitialPoint->text().split(",");
    initialPoint.clear();
    for (const QString& part : parts) {
        bool ok;
        double val = part.trimmed().toDouble(&ok);
        if (!ok) return false;
        initialPoint.append(val);
    }

    // Парсинг параметров алгоритма
    params.alpha = ui->lineEditAlpha->text().toDouble();
    params.gamma = ui->lineEditGamma->text().toDouble();
    params.beta = ui->lineEditBeta->text().toDouble();
    params.sigma = ui->lineEditSigma->text().toDouble();
    params.step = ui->lineEditStep->text().toDouble();
    params.tolerance = ui->lineEditTolerance->text().toDouble();
    params.max_iterations = ui->lineEditMaxIter->text().toInt();

    return true;
}

void MainWindow::on_pushButtonOptimize_clicked()
{
    QVector<double> initialPoint;
    NelderMeadParams params;

    if (!parseInput(initialPoint, params)) {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод");
        return;
    }

    // Целевая функция (пример)
    auto objectiveFunc = [](double* x) -> double {
        return 100*pow(x[1]-x[0]*x[0],2) + pow(1-x[0],2); // Можно сделать редактируемой
    };

    // Выделение памяти для результата
    double* result = new double[initialPoint.size()];

    // Вызов алгоритма
    nelder_mead_optimize(
        objectiveFunc,
        initialPoint.size(),
        initialPoint.data(),
        result,
        &params
        );

    // Форматирование результата
    QString resultText = "Оптимальная точка:\n";
    for (int i = 0; i < initialPoint.size(); ++i) {
        resultText += QString("x%1 = %2\n").arg(i).arg(result[i], 0, 'g', 6);
    }
    ui->textEditResults->setPlainText(resultText);

    delete[] result;
}
