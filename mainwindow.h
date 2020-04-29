#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "TextEdit.h"
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QAbstractItemModel>

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
    // These functions correspond to various buttons
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionExit_triggered();

    void on_actionBold_triggered();

    void on_actionUnderline_triggered();

    void on_actionItalics_triggered();

    void on_actionFont_size_triggered();

    void on_actionFont_Color_triggered();

    void on_actionFind_triggered();

    void on_actionFind_Replace_triggered();

    void on_actionCursor_Line_Number_triggered();

private:
    Ui::MainWindow *ui;
    QString currentfile="";
    QString lastsaved;
    void createMenu();

};
#endif // MAINWINDOW_H
