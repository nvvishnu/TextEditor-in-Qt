# TextEditor-in-Qt

Title                   :         Rich Text Editor using Qt Widgets

Author                  :         Vishnu Kiran

Date                    :         30/04/2020

Description             :         This repository consists of an Rich Text Editor created using Qt Widget Application.
                                  It uses the TextEdit(subclass of QTextEdit which is an inbuilt class used for text                                           operations). The UI has been created using QtDesigner tool which enabled addition of menu                                     bars and toolbars with available features. TextEdit(subclass of QTextEdit) class provides                                     inbuilt scrollbar facility which has been utilised. Qt Resource System(.qrc in Resources                                     directory) has been used to manage the resources for the project(images for icons etc.)
                                  Qt Project File(.pro) contains infomation required by qmake to build application.
                                  qmake tool is used for building application across different platforms.

Contents                :        
                          
                                  .png files - These files are icons used for buttons in toolbar

                                  Text_Editor_Widget.pro  -      Qt Project File for building of application
                                  
                                  Headers
                                  
                                      mainwindow.h     -      Header file for mainwindow in our UI
                                      
                                      TextEdit.h       -      Definition of TextEdit class which is the central Widget
                                      
                                  Forms(Sources)
                                      main.cpp         -      Contains main program
                                      
                                      mainwindow.cpp   -      Contains functionalities of mainwindow
                                      
                                  Resources
                                  
                                      Resources.qrc    -      Resource file containing icons used
Qt Framework Description:

Generally callback is used to communicate between different widgets in other frameworks.  Callback is a pointer to a function, so if you want a processing function to notify you about some event you pass a pointer to another function (the callback) to the processing function. The processing function then calls the callback when appropriate.

Qt uses Slot and Signal technique. A signal is emitted when a particular event occurs.A slot is a function that is called in response to a particular signal.Signals and slots are loosely coupled: A class which emits a signal neither knows nor cares which slots receive the signal. Qt's signals and slots mechanism ensures that if you connect a signal to a slot, the slot will be called with the signal's parameters at the right time.Signals are emitted by objects when they change their state in a way that may be interesting to other objects. Slots can be used for receiving signals, but they are also normal member functions.

QCompleter is used to provide auto completions in any Qt widget, such as QLineEdit and QComboBox. When the user starts typing a word, QCompleter suggests possible ways of completing the word, based on a word list. The word list is provided as a QAbstractItemModel.                                      

Various other classes like QTextCursor, QString, QInputDialog, QLineEdit, QScrollBar, QEvent, QStringList, QMessageBox etc. were also used. Check the code for all libraries being used.


Check https://github.com/nvvishnu/TextEditor-Application for the application.
