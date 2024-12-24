#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QAction>
#include <algorithm> // Для std::reverse

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Создаем виджеты
    lineEditLeft = new QLineEdit(this);
    lineEditRight = new QLineEdit(this);

    // Настраиваем компоновку
    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(lineEditLeft);
    layout->addWidget(lineEditRight);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Создаем действия, меню и панель инструментов
    createActions();
    createMenus();
    createToolBar();
}

MainWindow::~MainWindow()
{
    // Очистка памяти (Qt сам управляет памятью дочерних виджетов)
}

// Создание действий
void MainWindow::createActions()
{
    actionClearLeft = new QAction("Очистить левый", this);
    connect(actionClearLeft, &QAction::triggered, this, &MainWindow::on_actionClearLeft_triggered);

    actionClearRight = new QAction("Очистить правый", this);
    connect(actionClearRight, &QAction::triggered, this, &MainWindow::on_actionClearRight_triggered);

    actionClearAll = new QAction("Очистить все", this);
    connect(actionClearAll, &QAction::triggered, this, &MainWindow::on_actionClearAll_triggered);

    actionReverseLeft = new QAction("Обратить левый", this);
    connect(actionReverseLeft, &QAction::triggered, this, &MainWindow::on_actionReverseLeft_triggered);

    actionReverseRight = new QAction("Обратить правый", this);
    connect(actionReverseRight, &QAction::triggered, this, &MainWindow::on_actionReverseRight_triggered);

    actionReverseAll = new QAction("Обратить все", this);
    connect(actionReverseAll, &QAction::triggered, this, &MainWindow::on_actionReverseAll_triggered);

    actionCopyLeftToRight = new QAction("Копировать из левого в правый", this);
    connect(actionCopyLeftToRight, &QAction::triggered, this, &MainWindow::on_actionCopyLeftToRight_triggered);

    actionCopyRightToLeft = new QAction("Копировать из правого в левый", this);
    connect(actionCopyRightToLeft, &QAction::triggered, this, &MainWindow::on_actionCopyRightToLeft_triggered);

    actionMoveLeftToRight = new QAction("Перенести из левого в правый", this);
    connect(actionMoveLeftToRight, &QAction::triggered, this, &MainWindow::on_actionMoveLeftToRight_triggered);

    actionMoveRightToLeft = new QAction("Перенести из правого в левый", this);
    connect(actionMoveRightToLeft, &QAction::triggered, this, &MainWindow::on_actionMoveRightToLeft_triggered);

    actionSwap = new QAction("Обменять", this);
    connect(actionSwap, &QAction::triggered, this, &MainWindow::on_actionSwap_triggered);

    actionConcatLeftRight = new QAction("Конкатенация левый += правый", this);
    connect(actionConcatLeftRight, &QAction::triggered, this, &MainWindow::on_actionConcatLeftRight_triggered);

    actionConcatRightLeft = new QAction("Конкатенация правый += левый", this);
    connect(actionConcatRightLeft, &QAction::triggered, this, &MainWindow::on_actionConcatRightLeft_triggered);
}

// Создание меню
void MainWindow::createMenus()
{
    QMenu *menuOperations = menuBar()->addMenu("Операции");

    menuOperations->addAction(actionClearLeft);
    menuOperations->addAction(actionClearRight);
    menuOperations->addAction(actionClearAll);
    menuOperations->addSeparator();
    menuOperations->addAction(actionReverseLeft);
    menuOperations->addAction(actionReverseRight);
    menuOperations->addAction(actionReverseAll);
    menuOperations->addSeparator();
    menuOperations->addAction(actionCopyLeftToRight);
    menuOperations->addAction(actionCopyRightToLeft);
    menuOperations->addAction(actionMoveLeftToRight);
    menuOperations->addAction(actionMoveRightToLeft);
    menuOperations->addSeparator();
    menuOperations->addAction(actionSwap);
    menuOperations->addAction(actionConcatLeftRight);
    menuOperations->addAction(actionConcatRightLeft);
}

// Создание панели инструментов
void MainWindow::createToolBar()
{
    QToolBar *toolBar = addToolBar("MainToolBar");
    toolBar->addAction(actionClearLeft);
    toolBar->addAction(actionClearRight);
    toolBar->addAction(actionClearAll);
    toolBar->addSeparator();
    toolBar->addAction(actionReverseLeft);
    toolBar->addAction(actionReverseRight);
    toolBar->addAction(actionReverseAll);
    toolBar->addSeparator();
    toolBar->addAction(actionCopyLeftToRight);
    toolBar->addAction(actionCopyRightToLeft);
    toolBar->addAction(actionMoveLeftToRight);
    toolBar->addAction(actionMoveRightToLeft);
    toolBar->addSeparator();
    toolBar->addAction(actionSwap);
    toolBar->addAction(actionConcatLeftRight);
    toolBar->addAction(actionConcatRightLeft);
}

// Реализация слотов

void MainWindow::on_actionClearLeft_triggered()
{
    lineEditLeft->clear();
}

void MainWindow::on_actionClearRight_triggered()
{
    lineEditRight->clear();
}

void MainWindow::on_actionClearAll_triggered()
{
    lineEditLeft->clear();
    lineEditRight->clear();
}

void MainWindow::on_actionReverseLeft_triggered()
{
    QString text = lineEditLeft->text();
    std::reverse(text.begin(), text.end());
    lineEditLeft->setText(text);
}

void MainWindow::on_actionReverseRight_triggered()
{
    QString text = lineEditRight->text();
    std::reverse(text.begin(), text.end());
    lineEditRight->setText(text);
}

void MainWindow::on_actionReverseAll_triggered()
{
    on_actionReverseLeft_triggered();
    on_actionReverseRight_triggered();
}

void MainWindow::on_actionCopyLeftToRight_triggered()
{
    QString text = lineEditLeft->text();
    lineEditRight->setText(text);
}

void MainWindow::on_actionCopyRightToLeft_triggered()
{
    QString text = lineEditRight->text();
    lineEditLeft->setText(text);
}

void MainWindow::on_actionMoveLeftToRight_triggered()
{
    QString text = lineEditLeft->text();
    lineEditRight->setText(text);
    lineEditLeft->clear();
}

void MainWindow::on_actionMoveRightToLeft_triggered()
{
    QString text = lineEditRight->text();
    lineEditLeft->setText(text);
    lineEditRight->clear();
}

void MainWindow::on_actionSwap_triggered()
{
    QString leftText = lineEditLeft->text();
    QString rightText = lineEditRight->text();
    lineEditLeft->setText(rightText);
    lineEditRight->setText(leftText);
}

void MainWindow::on_actionConcatLeftRight_triggered()
{
    QString leftText = lineEditLeft->text();
    QString rightText = lineEditRight->text();
    lineEditLeft->setText(leftText + rightText);
}

void MainWindow::on_actionConcatRightLeft_triggered()
{
    QString leftText = lineEditLeft->text();
    QString rightText = lineEditRight->text();
    lineEditRight->setText(rightText + leftText);
}
