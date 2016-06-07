#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QLabel;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QLabel *createLabel(const QString &text);
};

#endif // MAINWINDOW_H
