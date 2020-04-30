# TextEditor-in-Qt

Title                   :         Rich Text Editor using Qt Widgets
Author                  :         Vishnu Kiran
Date                    :         30/04/2020
Description             :         This repository consists of an Rich Text Editor created using Qt Widget Application.
                                  It uses the TextEdit(subclass of QTextEdit which is an inbuilt class used for text operations). The UI
                                  has been created using QtDesigner tool which enabled addition of menu bars and toolbars with
                                  available features. QTextEdit class provides inbuilt scrollbar facility which has been utilised.
                                  Qt Resource System(.qrc in Resources directory) has been used to manage the resources for the project(images for icons etc.)
                                  Qt Project File(.pro) contains infomation required by qmake to build application.
                                  qmake tool is used for building application across different platforms.

Contents                :         .png files - These files are icons used for buttons in toolbar
                                  Text_Editor_Widget.pro  -      Qt Project File for building of application
                                  Headers
                                      mainwindow.h     -      Header file for mainwindow in our UI
                                      TextEdit.h       -      Definition of TextEdit class which is the central Widget
                                  Forms(Sources)
                                      main.cpp         -      Contains main program
                                      mainwindow.cpp   -      Contains functionalities of mainwindow
                                  Resources
                                      Resources.qrc    -      Resource file containing icons used
                                      
Check https://github.com/nvvishnu/TextEditor-Application for the application.
