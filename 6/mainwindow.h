#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionClearLeft_triggered();
    void on_actionClearRight_triggered();
    void on_actionClearAll_triggered();
    void on_actionReverseLeft_triggered();
    void on_actionReverseRight_triggered();
    void on_actionReverseAll_triggered();
    void on_actionCopyLeftToRight_triggered();
    void on_actionCopyRightToLeft_triggered();
    void on_actionMoveLeftToRight_triggered();
    void on_actionMoveRightToLeft_triggered();
    void on_actionSwap_triggered();
    void on_actionConcatLeftRight_triggered();
    void on_actionConcatRightLeft_triggered();

private:
    void createActions();
    void createMenus();
    void createToolBar();

    QLineEdit *lineEditLeft;
    QLineEdit *lineEditRight;

    // Действия
    QAction *actionClearLeft;
    QAction *actionClearRight;
    QAction *actionClearAll;
    QAction *actionReverseLeft;
    QAction *actionReverseRight;
    QAction *actionReverseAll;
    QAction *actionCopyLeftToRight;
    QAction *actionCopyRightToLeft;
    QAction *actionMoveLeftToRight;
    QAction *actionMoveRightToLeft;
    QAction *actionSwap;
    QAction *actionConcatLeftRight;
    QAction *actionConcatRightLeft;
};

#endif // MAINWINDOW_H
