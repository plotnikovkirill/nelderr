#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QDoubleValidator>
#include <QIntValidator>
// В mainwindow.cpp перед #include "exprtk.hpp"
#define exprtk_disable_exceptions
#define exprtk_disable_rtti
#define exprtk_disable_caseinsensitivity
#include "../exprtk-master/exprtk.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Валидаторы для числового ввода
    QDoubleValidator* doubleValidator = new QDoubleValidator(this);
    QIntValidator* intValidator = new QIntValidator(1, 100000, this);

    ui->lineEditInitialPoint->setInputMask("9.9, 9.9");
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
static QString currentExpression;
double evaluateExpression(double* x, const QString& expr){
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double> expression_t;
    typedef exprtk::parser<double> parser_t;

    symbol_table_t symbol_table;
    symbol_table.add_variable("x", x[0]);
    symbol_table.add_variable("y", x[1]);

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    bool compilation_success = parser.compile(expr.toStdString(), expression);
    if(compilation_success) {
        return expression.value();
    } else {
        // Обработка ошибки
        qDebug() << "Expression error:" << parser.error().c_str();
        return std::numeric_limits<double>::quiet_NaN();
    }
}
void MainWindow::on_pushButtonOptimize_clicked()
{
    currentExpression = ui->functionEdit->toPlainText();

    auto objectiveFunc = [](double* x) -> double {
        return evaluateExpression(x, currentExpression);
    };

    QVector<double> initialPoint;
    NelderMeadParams params;

    if (!parseInput(initialPoint, params)) {
        QMessageBox::critical(this, "Ошибка", "Некорректный ввод");
        return;
    }

    // Целевая функция (пример)
    // auto objectiveFunc = [](double* x) -> double {
    //     return x[0]*x[0] + x[1]*x[1]; // Можно сделать редактируемой
    // };

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

