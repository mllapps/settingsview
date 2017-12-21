#ifndef SETTINGSVIEW_H
#define SETTINGSVIEW_H

#include <QWidget>

class QLabel;
class QToolButton;
class QStackedWidget;

class SettingsView : public QWidget
{
    Q_OBJECT

public:
    explicit SettingsView(QWidget *parent = 0);
    ~SettingsView();

    void push(QWidget * page);
    void pop();

public slots:
    void changeCenterWidget(bool);

private:
    QToolButton * createSidebarButton(const QString& iconPath, const QString& title);
    QStackedWidget * _stackedWidget;
    QToolButton * _activeButton;

};

#endif // SETTINGSVIEW_H
