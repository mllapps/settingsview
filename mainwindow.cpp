#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "borderlayout.h"

#include <QTextBrowser>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QToolButton>
#include <QDebug>
#include <QStackedWidget>

QToolButton * MainWindow::createSidebarButton(const QString& iconPath, const QString& title)
{
    QIcon icon(iconPath);

    QToolButton * btn = new QToolButton;
    btn->setIcon(icon);
    btn->setIconSize(QSize(32, 32));
    btn->setText(title);
    btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn->setFixedSize(100, 100);
    btn->setStyleSheet("QToolButton {color: white; background-color: gray;}");
    btn->setObjectName(title);

    return btn;
}

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    setGeometry(0,0, 700, 620);

    QVBoxLayout * sidebarLayout = new QVBoxLayout();
    QToolButton * btn = createSidebarButton(":/icons/assets/add.svg", "General");
    QObject::connect(btn, SIGNAL(clicked(bool)), this, SLOT(changeCenterWidget(bool)));
    sidebarLayout->addWidget(btn);

    QToolButton * btn2 = createSidebarButton(":/icons/assets/cloud.svg", "Network");
    QObject::connect(btn2, SIGNAL(clicked(bool)), this, SLOT(changeCenterWidget(bool)));

    sidebarLayout->addWidget(btn2);

    sidebarLayout->addWidget(createSidebarButton(":/icons/assets/alarm-clock.svg", "Slideshow"));
    sidebarLayout->addWidget(createSidebarButton(":/icons/assets/bars.svg", "Privacy"));
    sidebarLayout->addWidget(createSidebarButton(":/icons/assets/attachment.svg", "Advanced"));
    sidebarLayout->addWidget(createSidebarButton(":/icons/assets/cloud.svg", "Storage"));
    sidebarLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Minimum, QSizePolicy::MinimumExpanding));

    QWidget * sidebar = new QWidget();
    sidebar->setLayout(sidebarLayout);
    sidebar->setObjectName("sidebar");
    sidebar->setStyleSheet("QWidget#sidebar {background-color: gray;} ");

    QTextBrowser *centralWidget = new QTextBrowser;
    centralWidget->setPlainText(tr("General"));
    QTextBrowser *centralWidget2 = new QTextBrowser;
    centralWidget2->setPlainText(tr("Network"));

    _stackedWidget = new QStackedWidget;
    _stackedWidget->addWidget(centralWidget);
    _stackedWidget->addWidget(centralWidget2);

    BorderLayout *layout = new BorderLayout;
    layout->addWidget(_stackedWidget, BorderLayout::Center);
    layout->addWidget(sidebar, BorderLayout::West);
    setLayout(layout);

    setWindowTitle(tr("Border Layout"));
}

MainWindow::~MainWindow()
{
}

void MainWindow::changeCenterWidget(bool event)
{
    qDebug() << "clicked" << QObject::sender()->objectName();

    QString sender = QObject::sender()->objectName();

    if(sender.compare("General") == 0) {
        _stackedWidget->setCurrentIndex(0);
    }else if(sender.compare("Network") == 0) {
        _stackedWidget->setCurrentIndex(1);
    }

}

QLabel *MainWindow::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setFrameStyle(QFrame::Box | QFrame::Raised);
    return label;
}
