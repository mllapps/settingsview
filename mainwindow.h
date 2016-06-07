#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QLabel;
class QToolButton;
class QStackedWidget;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void changeCenterWidget(bool);


private:
    QToolButton * createSidebarButton(const QString& iconPath, const QString& title);

    QLabel *createLabel(const QString &text);
    QStackedWidget * _stackedWidget;

};

#endif // MAINWINDOW_H
