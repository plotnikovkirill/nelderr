/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxInput;
    QGridLayout *gridLayout;
    QLabel *labelInitialPoint;
    QPlainTextEdit *functionEdit;
    QLineEdit *lineEditInitialPoint;
    QLabel *labelAlpha;
    QLineEdit *lineEditAlpha;
    QLabel *labelGamma;
    QLineEdit *lineEditGamma;
    QLabel *labelBeta;
    QLineEdit *lineEditBeta;
    QLabel *labelSigma;
    QLineEdit *lineEditSigma;
    QLabel *labelStep;
    QLineEdit *lineEditStep;
    QLabel *labelTolerance;
    QLineEdit *lineEditTolerance;
    QLabel *labelMaxIter;
    QLineEdit *lineEditMaxIter;
    QPushButton *pushButtonOptimize;
    QGroupBox *groupBoxResults;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEditResults;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName("verticalLayout");
        groupBoxInput = new QGroupBox(centralWidget);
        groupBoxInput->setObjectName("groupBoxInput");
        gridLayout = new QGridLayout(groupBoxInput);
        gridLayout->setObjectName("gridLayout");
        labelInitialPoint = new QLabel(groupBoxInput);
        labelInitialPoint->setObjectName("labelInitialPoint");

        gridLayout->addWidget(labelInitialPoint, 0, 0, 1, 1);

        functionEdit = new QPlainTextEdit(groupBoxInput);
        functionEdit->setObjectName("functionEdit");

        gridLayout->addWidget(functionEdit, 0, 0, 1, 1);

        lineEditInitialPoint = new QLineEdit(groupBoxInput);
        lineEditInitialPoint->setObjectName("lineEditInitialPoint");

        gridLayout->addWidget(lineEditInitialPoint, 0, 1, 1, 1);

        labelAlpha = new QLabel(groupBoxInput);
        labelAlpha->setObjectName("labelAlpha");

        gridLayout->addWidget(labelAlpha, 1, 0, 1, 1);

        lineEditAlpha = new QLineEdit(groupBoxInput);
        lineEditAlpha->setObjectName("lineEditAlpha");

        gridLayout->addWidget(lineEditAlpha, 1, 1, 1, 1);

        labelGamma = new QLabel(groupBoxInput);
        labelGamma->setObjectName("labelGamma");

        gridLayout->addWidget(labelGamma, 2, 0, 1, 1);

        lineEditGamma = new QLineEdit(groupBoxInput);
        lineEditGamma->setObjectName("lineEditGamma");

        gridLayout->addWidget(lineEditGamma, 2, 1, 1, 1);

        labelBeta = new QLabel(groupBoxInput);
        labelBeta->setObjectName("labelBeta");

        gridLayout->addWidget(labelBeta, 3, 0, 1, 1);

        lineEditBeta = new QLineEdit(groupBoxInput);
        lineEditBeta->setObjectName("lineEditBeta");

        gridLayout->addWidget(lineEditBeta, 3, 1, 1, 1);

        labelSigma = new QLabel(groupBoxInput);
        labelSigma->setObjectName("labelSigma");

        gridLayout->addWidget(labelSigma, 4, 0, 1, 1);

        lineEditSigma = new QLineEdit(groupBoxInput);
        lineEditSigma->setObjectName("lineEditSigma");

        gridLayout->addWidget(lineEditSigma, 4, 1, 1, 1);

        labelStep = new QLabel(groupBoxInput);
        labelStep->setObjectName("labelStep");

        gridLayout->addWidget(labelStep, 5, 0, 1, 1);

        lineEditStep = new QLineEdit(groupBoxInput);
        lineEditStep->setObjectName("lineEditStep");

        gridLayout->addWidget(lineEditStep, 5, 1, 1, 1);

        labelTolerance = new QLabel(groupBoxInput);
        labelTolerance->setObjectName("labelTolerance");

        gridLayout->addWidget(labelTolerance, 6, 0, 1, 1);

        lineEditTolerance = new QLineEdit(groupBoxInput);
        lineEditTolerance->setObjectName("lineEditTolerance");

        gridLayout->addWidget(lineEditTolerance, 6, 1, 1, 1);

        labelMaxIter = new QLabel(groupBoxInput);
        labelMaxIter->setObjectName("labelMaxIter");

        gridLayout->addWidget(labelMaxIter, 7, 0, 1, 1);

        lineEditMaxIter = new QLineEdit(groupBoxInput);
        lineEditMaxIter->setObjectName("lineEditMaxIter");

        gridLayout->addWidget(lineEditMaxIter, 7, 1, 1, 1);


        verticalLayout->addWidget(groupBoxInput);

        pushButtonOptimize = new QPushButton(centralWidget);
        pushButtonOptimize->setObjectName("pushButtonOptimize");

        verticalLayout->addWidget(pushButtonOptimize);

        groupBoxResults = new QGroupBox(centralWidget);
        groupBoxResults->setObjectName("groupBoxResults");
        verticalLayout_2 = new QVBoxLayout(groupBoxResults);
        verticalLayout_2->setObjectName("verticalLayout_2");
        textEditResults = new QTextEdit(groupBoxResults);
        textEditResults->setObjectName("textEditResults");
        textEditResults->setReadOnly(true);

        verticalLayout_2->addWidget(textEditResults);


        verticalLayout->addWidget(groupBoxResults);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        groupBoxInput->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        labelInitialPoint->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\320\260\321\217 \321\202\320\276\321\207\320\272\320\260:", nullptr));
        functionEdit->setPlainText(QCoreApplication::translate("MainWindow", "x[0]*x[0] + x[1]*x[1];", nullptr));
        lineEditInitialPoint->setText(QCoreApplication::translate("MainWindow", "5.0, 5.0", nullptr));
        labelAlpha->setText(QCoreApplication::translate("MainWindow", "Alpha (\320\276\321\202\321\200\320\260\320\266\320\265\320\275\320\270\320\265):", nullptr));
        lineEditAlpha->setText(QCoreApplication::translate("MainWindow", "1.0", nullptr));
        labelGamma->setText(QCoreApplication::translate("MainWindow", "Gamma (\321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\270\320\265):", nullptr));
        lineEditGamma->setText(QCoreApplication::translate("MainWindow", "2.0", nullptr));
        labelBeta->setText(QCoreApplication::translate("MainWindow", "Beta (\321\201\320\266\320\260\321\202\320\270\320\265):", nullptr));
        lineEditBeta->setText(QCoreApplication::translate("MainWindow", "0.5", nullptr));
        labelSigma->setText(QCoreApplication::translate("MainWindow", "Sigma (\321\201\320\276\320\272\321\200\320\260\321\211\320\265\320\275\320\270\320\265):", nullptr));
        lineEditSigma->setText(QCoreApplication::translate("MainWindow", "0.5", nullptr));
        labelStep->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\320\273\321\214\320\275\321\213\320\271 \321\210\320\260\320\263:", nullptr));
        lineEditStep->setText(QCoreApplication::translate("MainWindow", "1.0", nullptr));
        labelTolerance->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\270\321\202\320\265\321\200\320\270\320\271 \320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\270:", nullptr));
        lineEditTolerance->setText(QCoreApplication::translate("MainWindow", "1e-6", nullptr));
        labelMaxIter->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201. \320\270\321\202\320\265\321\200\320\260\321\206\320\270\320\271:", nullptr));
        lineEditMaxIter->setText(QCoreApplication::translate("MainWindow", "1000", nullptr));
        pushButtonOptimize->setText(QCoreApplication::translate("MainWindow", "\320\236\320\277\321\202\320\270\320\274\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        groupBoxResults->setTitle(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202\321\213", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
