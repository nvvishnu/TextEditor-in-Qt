#ifndef TEXTEDIT_H
#define TEXTEDIT_H
#include <QTextEdit>
#include <QCompleter>

/*
 *  TextEdit class is a subclass of QTextEdit. keyPressEvent and focusInEvent functions has been reimplemented to support autocompletion
 *   of words.
 *
*/
class TextEdit : public QTextEdit
{
    Q_OBJECT

public:
    TextEdit(QWidget *parent = nullptr);
    ~TextEdit();

    void completeword(QCompleter *c);
    QCompleter *completer() const;

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void focusInEvent(QFocusEvent *e) override;

private slots:
    void insertword(const QString &completion);

private:
    QString currText() const;

private:
    QCompleter *word = nullptr;
};

#endif // TEXTEDIT_H
