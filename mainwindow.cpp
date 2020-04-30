/*
 *   Program                :     Rich Text Editor using QWidgets
 *   Author                 :     Vishnu Kiran (CS18B067)
 *   Date of Completion     :     29/04/2020
 *   Description            :     This program creates a rich text editor with basic functionalities using QWidgets Application
 *                                of Qt. It uses the QTextEdit inbuilt class which is used for all the text operations. The UI
 *                                has been created using QtDesigner tool which enabled addition of menu bars and toolbars with
 *                                available features. QTextEdit class provides inbuilt scrollbar facility which has been utilised.
 *                                Qt Resource System(.qrc in Resources directory) has been used to manage the resources for the project(images for icons etc.)
 *                                Qt Project File(.pro) contains infomation required by qmake to build application.
 *                                qmake tool is used for building application across different platforms.
 *
 *
*/

/* Contents of project:
 *           Text_Editor_Widget.pro  -      Qt Project File for building of application
 *           Headers
 *                  mainwindow.h     -      Header file for mainwindow in our UI
 *           Forms(Sources)
 *                  main.cpp         -      Contains main program
 *                  mainwindow.cpp   -      Contains functionalities of mainwindow
 *           Resources
 *                  Resources.qrc    -      Resource file containing icons used
*/




#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QLineEdit>
#include <iostream>
#include <QListWidget>

#include <QKeyEvent>
#include <QScrollBar>
#include <QStringListModel>


using namespace std;


/*TextEdit::TextEdit(QWidget *parent)
    : QTextEdit(parent)
{
    setPlainText(tr("This TextEdit provides autocompletions for words that have more than"
                    " 3 characters. You can trigger autocompletion using ") +
                    QKeySequence("Ctrl+E").toString(QKeySequence::NativeText));
}

TextEdit::~TextEdit()
{
}

void TextEdit::setCompleter(QCompleter *completer)
{
    if (c)
        c->disconnect(this);

    c = completer;

    if (!c)
        return;

    c->setWidget(this);
    c->setCompletionMode(QCompleter::PopupCompletion);
    c->setCaseSensitivity(Qt::CaseInsensitive);
    QObject::connect(c, QOverload<const QString &>::of(&QCompleter::activated),
                     this, &TextEdit::insertCompletion);
}

QCompleter *TextEdit::completer() const
{
    return c;
}
void TextEdit::insertCompletion(const QString &completion)
{
    if (c->widget() != this)
        return;
    QTextCursor tc = textCursor();
    int extra = completion.length() - c->completionPrefix().length();
    tc.movePosition(QTextCursor::Left);
    tc.movePosition(QTextCursor::EndOfWord);
    tc.insertText(completion.right(extra));
    setTextCursor(tc);
}
QString TextEdit::textUnderCursor() const
{
    QTextCursor tc = textCursor();
    tc.select(QTextCursor::WordUnderCursor);
    return tc.selectedText();
}
void TextEdit::focusInEvent(QFocusEvent *e)
{
    if (c)
        c->setWidget(this);
    QTextEdit::focusInEvent(e);
}
void TextEdit::keyPressEvent(QKeyEvent *e)
{
    if (c && c->popup()->isVisible()) {
        // The following keys are forwarded by the completer to the widget
       switch (e->key()) {
       case Qt::Key_Enter:
       case Qt::Key_Return:
       case Qt::Key_Escape:
       case Qt::Key_Tab:
       case Qt::Key_Backtab:
            e->ignore();
            return; // let the completer do default behavior
       default:
           break;
       }
    }

    const bool isShortcut = (e->modifiers().testFlag(Qt::ControlModifier) && e->key() == Qt::Key_E); // CTRL+E
    if (!c || !isShortcut) // do not process the shortcut when we have a completer
        QTextEdit::keyPressEvent(e);
    const bool ctrlOrShift = e->modifiers().testFlag(Qt::ControlModifier) ||
                                e->modifiers().testFlag(Qt::ShiftModifier);
       if (!c || (ctrlOrShift && e->text().isEmpty()))
           return;

       static QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-="); // end of word
       const bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
       QString completionPrefix = textUnderCursor();

       if (!isShortcut && (hasModifier || e->text().isEmpty()|| completionPrefix.length() < 3
                         || eow.contains(e->text().right(1)))) {
           c->popup()->hide();
           return;
       }

       if (completionPrefix != c->completionPrefix()) {
           c->setCompletionPrefix(completionPrefix);
           c->popup()->setCurrentIndex(c->completionModel()->index(0, 0));
       }
       QRect cr = cursorRect();
       cr.setWidth(c->popup()->sizeHintForColumn(0)
                   + c->popup()->verticalScrollBar()->sizeHint().width());
       c->complete(cr); // popup it up!
   }
*/
/*
 * Mainwindow constructor
 */
MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    ui->textEdit->setFontWeight(QFont::Thin);
    /*createMenu();
    completingTextEdit = new TextEdit;
    completer = new QCompleter(this);
    completer->setModel(modelFromFile(":/resources/wordlist.txt"));
    completer->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    completer->setWrapAround(false);
    completingTextEdit->setCompleter(completer);
    setCentralWidget(completingTextEdit);
     resize(500, 300);
     setWindowTitle(tr("Completer"));*/
}

/*void MainWindow::createMenu()
{
    QAction *exitAction = new QAction(tr("Exit"), this);
    QAction *aboutAct = new QAction(tr("About"), this);
    QAction *aboutQtAct = new QAction(tr("About Qt"), this);

    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);

    QMenu *fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(exitAction);

    QMenu *helpMenu = menuBar()->addMenu(tr("About"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

QAbstractItemModel *MainWindow::modelFromFile(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly))
        return new QStringListModel(completer);

#ifndef QT_NO_CURSOR
    QGuiApplication::setOverrideCursor(QCursor(Qt::WaitCursor));
#endif
    QStringList words;

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        if (!line.isEmpty())
            words << QString::fromUtf8(line.trimmed());
    }

#ifndef QT_NO_CURSOR
    QGuiApplication::restoreOverrideCursor();
#endif
    return new QStringListModel(words, completer);
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About"), tr("This example demonstrates the "
        "different features of the QCompleter class."));
}

*/


/*
 * Mainwindow destructor
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*
 *  This function is called when New File button is pressed/selected in toolbar
*/
void MainWindow::on_actionNew_triggered()
{
    lastsaved="";
    QString current=ui->textEdit->toPlainText();
    if(current!=lastsaved) // Check if current file is saved
    {
        // Check if user wants to save the current file or discard it

        QMessageBox modified;
        modified.setText("Do you want to save this document?");
        modified.setStandardButtons(QMessageBox::Save |  QMessageBox::Discard | QMessageBox::Cancel);
        modified.setDefaultButton(QMessageBox::Save);
        int ret = modified.exec(); // ret returns the value of Standard Button pressed
        if(ret==0x00000800)
        {
            MainWindow::on_actionSave_triggered();
        }
        else if(ret==0x00800000)
        {
            currentfile.clear();
            ui->textEdit->setText(QString());
            setWindowTitle("Untitled");
        }
      }
    else
    {
        currentfile.clear();
        ui->textEdit->setText(QString());
        setWindowTitle("Untitled"); // A New File is named Untitled by default
    }

}

/*
 *This function is called if open file button is pressed
*/
void MainWindow::on_actionOpen_triggered()
{
    QString current=ui->textEdit->toPlainText();
    if(current!=lastsaved) //Check current file is saved
    {
        QMessageBox modified;
        modified.setText("Do you want to save this document?");
        modified.setStandardButtons(QMessageBox::Save |  QMessageBox::Discard | QMessageBox::Cancel);
        modified.setDefaultButton(QMessageBox::Save);
        int ret = modified.exec(); // ret returns the value of Standard Button pressed
        if(ret==0x00000800)
        {
            MainWindow::on_actionSave_triggered();return;
        }
        else if(ret==0x00400000)
        {
            return;
         }
     }
        QString openfile = QFileDialog::getOpenFileName(this, "Open file"); //Get name of file to open
        QFile file(openfile);
        currentfile = openfile;
        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Unable to open file: " + file.errorString());
            return;
        }
        setWindowTitle(openfile);
        QTextStream in(&file);
        QString text = in.readAll();
        ui->textEdit->setText(text); //Get contents of file into TextEdit window
        file.close();
}

/*
 * This function is called when save button is pressed
*/
void MainWindow::on_actionSave_triggered()
{
        QString fileName = QFileDialog::getSaveFileName(this, "Save as"); //Get file name to save as
        QFile file(fileName);

        //Check if file could be opened

        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }


        currentfile = fileName;
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString text = ui->textEdit->toPlainText();
        out << text; //Write contents in QTextEdit into the file
        lastsaved=text;
        file.close();
}

/*
 *Used to cut text and save in clipboard
*/
void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

/*
 *Copy text and save in clipboard
*/
void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

/*
 * Paste text at the current cursor position
*/
void MainWindow::on_actionPaste_triggered()
{
   ui->textEdit->paste();
}

/*
 * Undo the last action
*/
void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

/*
 * Redo the last action
*/
void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

/*
 * Used to exit the application
*/
void MainWindow::on_actionExit_triggered() {
    QString current=ui->textEdit->toPlainText();
    if(current!=lastsaved) //Check if file has been saved
      {

        QMessageBox modified;
        modified.setText("The document has been modified");
        modified.setStandardButtons(QMessageBox::Save |  QMessageBox::Discard | QMessageBox::Cancel);
        modified.setDefaultButton(QMessageBox::Save);
        int ret = modified.exec(); // ret returns the value of Standard Button pressed
        if(ret==0x00000800)
           {
            MainWindow::on_actionSave_triggered(); //Call Save function if user wants to save the file before quitting
        }
        else if(ret==0x00800000)
        {
            QApplication::quit();
       }
      }
    else
    {
          QApplication::quit();
    }
}

/*
 *Turns normal characters into bold font and vice versa
*/
void MainWindow::on_actionBold_triggered()
{
    if(ui->textEdit->fontWeight()!=QFont::Bold)
    ui->textEdit->setFontWeight(QFont::Bold);
    else
    ui->textEdit->setFontWeight(QFont::Thin);
}

/*
 *  Underlines text not underline and vice-versa
*/
void MainWindow::on_actionUnderline_triggered()
{
    //fontUnderline returns true if the last character in selected string is underlined

    if(ui->textEdit->fontUnderline())
    ui->textEdit->setFontUnderline(false);
    else
    ui->textEdit->setFontUnderline(true);
}

/*
 * Turns non italised text into italics and vice-versa
*/
void MainWindow::on_actionItalics_triggered()
{
    //fontItalic returns true if the last character in selected string is italicised
    if(ui->textEdit->fontItalic())
    ui->textEdit->setFontItalic(false);
    else
    ui->textEdit->setFontItalic(true);
}

/*
 *  Opens a inputdialog to change font size of selected text
*/
void MainWindow::on_actionFont_size_triggered()
{
    bool ok;
    Qt::WindowFlags a;

    //Opens a InputDialog where font size is to be entered

    qreal i = QInputDialog::getDouble(this, tr("Font Size "),tr("Enter Font Size: "), ui->textEdit->fontPointSize(), 0, 1638, 4, &ok,a,1);
    if(ok)
    ui->textEdit->setFontPointSize(i);

}
// 0 is minimum font point size and 1638 is maximum font point size with step size=1, decimal places=4

/*
 * Used to change font color
*/
void MainWindow::on_actionFont_Color_triggered()
{
    //Define some standard colours to be used

    QColor red(255,0,0);
    QColor green(0,255,0);
    QColor blue(0,0,255);
    QColor orange(255,165,0);
    QColor violet(238,130,238);
    QColor black(0,0,0);
    QColor white(255,255,255);
    QColor yellow(255,255,0);
    bool ok1,ok2,ok3,ok;
    QStringList colors;
    colors<< tr("Red") << tr("Green") << tr("Blue") << tr("Orange")<<tr("Violet")<<tr("Black")<<tr("White")<<tr("Yellow")<<tr("Custom Color");

    // A Menu dialog box with standard colors is displayed and can be chosen from

    QString item = QInputDialog::getItem(this, tr("Text Color"),tr("Select Color: "), colors, 0, false, &ok);
    string c=item.toStdString();
        if(c=="Red")
        ui->textEdit->setTextColor(red);
        else if(c=="Green")
        ui->textEdit->setTextColor(green);
        else if(c=="Blue")
        ui->textEdit->setTextColor(blue);
        else if(c=="Orange")
        ui->textEdit->setTextColor(orange);
        else if(c=="Violet")
        ui->textEdit->setTextColor(violet);
        else if(c=="Black")
        ui->textEdit->setTextColor(black);
        else if(c=="White")
        ui->textEdit->setTextColor(white);
        else if(c=="Yellow")
        ui->textEdit->setTextColor(yellow);
        else if(c=="Custom Color")
        {
            // Enables creating custom colors from RGB values. Popups dialogs for the same

            int x=QInputDialog::getInt(this,tr("Font Color"),tr("Enter R Value: "),ui->textEdit->textColor().red(),0,255,1,&ok1);
            int y=QInputDialog::getInt(this,tr("Font Color"),tr("Enter G Value: "),ui->textEdit->textColor().green(),0,255,1,&ok2);
            int z=QInputDialog::getInt(this,tr("Font Color"),tr("Enter B Value: "),ui->textEdit->textColor().blue(),0,255,1,&ok3);
            if(ok1&&ok2&&ok3)
            {
                QColor a(x,y,z);
                ui->textEdit->setTextColor(a);
            }
        }
}

/*
 * Finds occurences of an input string from current cursor position till the end of document
*/
void MainWindow::on_actionFind_triggered()
{
    bool ok,found;
    QTextCursor original=ui->textEdit->textCursor(); //Save current cursor position to be restored after string search is done
    QStringList act;QString item;string c;
    act<<tr("Find Next")<<tr("Close");

    // Dialogbox to input string to be searched

    QString p = QInputDialog::getText(this, tr("String Search"),tr("Enter String to Search:"), QLineEdit::Normal,QDir::home().dirName(), &ok);
    if(ok)
    {
        found=ui->textEdit->find(p);
        if(found)
        {
            // Lets user continue search or stop search

            item=QInputDialog::getItem(this, tr("Find"),tr("Continue Search: "), act, 0, false, &ok);
            c=item.toStdString();
        }
        else
        {
            // No string match found

            QMessageBox findend;
            findend.setText("No matching string found");
            findend.exec();
            c="Close";
        }

        //Continues search

        while(c=="Find Next")
        {
            found=ui->textEdit->find(p);
            if(found)
            {
            item=QInputDialog::getItem(this, tr("Find"),tr("Continue Search: "), act, 0, false, &ok);
            c=item.toStdString();
            }
            else
            {
                QMessageBox findend;
                findend.setText("No matching string found");
                findend.exec();
                c="Close";
            }

         }
    }
    ui->textEdit->setTextCursor(original);
}

/*
 * Provides text replacement locally and globally
*/
void MainWindow::on_actionFind_Replace_triggered()
{

    bool ok,found,ok1,ok2;
    QTextCharFormat form;
    QTextCursor original=ui->textEdit->textCursor();
    QStringList act,repl;QString item,replaceoption;string c,d;

    //Declaration of lists for user options

    act<<tr("Find Next")<<tr("Close");
    repl<<tr("Replace all future occurences")<<tr("Replace current occurence")<<tr("Cancel");

    //String to be searched

    QString p = QInputDialog::getText(this, tr("String Search"),tr("Enter String to Search:"), QLineEdit::Normal,QDir::home().dirName(), &ok1);

    if(ok1)
    {
        //String to be replaced with

        QString q = QInputDialog::getText(this, tr("String Replace"),tr("Enter String to Replace:"), QLineEdit::Normal,QDir::home().dirName(), &ok2);
        if(ok2)
        {
            found=ui->textEdit->find(p);

            if(found)
            {
                replaceoption=QInputDialog::getItem(this, tr("Replace String"),tr("Replace Option: "), repl, 0, false, &ok);
                d=replaceoption.toStdString();
            }
            else
            {
                QMessageBox findend;
                findend.setText("No matching string found");
                findend.exec();
                c="Close";
            }
            while(d=="Replace current occurence"||d=="Replace all future occurences")
            {
                if(d=="Replace all future occurences")
                {
                    QString str;
                    while(found==true) // Replacement occurs as long as a new occurence is found
                    {

                        QTextCursor orign=ui->textEdit->textCursor();QString str;                        
                        QTextCursor *c = new QTextCursor(orign);

                        // Select the current occurence of the string and remove it

                        form=c->charFormat(); //Store formatting of the last character in string
                        c->movePosition(QTextCursor::NextCharacter,QTextCursor::KeepAnchor,p.size());                        
                        str=c->selectedText();
                        c->removeSelectedText();                        

                        str.replace(str.indexOf(p), p.size(), q); //Replace first occurence of string to be searched for by string to be replaced.
                        orign.setCharFormat(form); //Restore formatting

                        orign.insertText(str); //Insert the modified text at the current position
                        ui->textEdit->setTextCursor(orign);
                        found=ui->textEdit->find(p);
                    }
                    return;
                }
                else if(d=="Replace current occurence")
                {
                    QTextCursor orign=ui->textEdit->textCursor();QString str;
                    QTextCursor *c = new QTextCursor(orign);
                    c->movePosition(QTextCursor::NextCharacter,QTextCursor::KeepAnchor,p.size());
                    str=c->selectedText();
                    c->removeSelectedText();
                    str.replace(str.indexOf(p), p.size(), q);
                    orign.insertText(str);
                    ui->textEdit->setTextCursor(orign);
                    found=ui->textEdit->find(p);
                }
                if(found)
                {
                    replaceoption=QInputDialog::getItem(this, tr("Replace String"),tr("Replace Option: "), repl, 0, false, &ok);
                    d=replaceoption.toStdString();
                }
                else
                {
                    QMessageBox findend;
                    findend.setText("No matching string found");
                    findend.exec();
                    d="Close";
                }

             }
        }
        ui->textEdit->setTextCursor(original);
   }
}
//Note that string formatting may not be reflected properly in text to be replaced in certain cases.

/*
 * Position cursor based on line number
*/
 void MainWindow::on_actionCursor_Line_Number_triggered()
{
    bool ok;

    // Dialog box to enter line number to be moved to

    int x=QInputDialog::getInt(this,tr("Cursor Positioning"),tr("Enter Line Number: "),ui->textEdit->textCursor().blockNumber(),1,ui->textEdit->toPlainText().split("\n" ).size(),1,&ok);
    if(ok)
    {
        ui->textEdit->moveCursor(QTextCursor::Start);
        for(int i=1;i<x;i++)
        ui->textEdit->moveCursor(QTextCursor::Down);
    }
    // Maximum Line Number allowed is the number of lines in the document
}
