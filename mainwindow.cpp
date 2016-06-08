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

/*------------------------------------------------------------------------------
 * CTOR / DTOR
 *----------------------------------------------------------------------------*/

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    // Create a layout for the sidebar
    QVBoxLayout * sidebarLayout = new QVBoxLayout();
    sidebarLayout->addWidget(createSidebarButton(":/icons/assets/settings.svg", tr("General") ));
    sidebarLayout->addWidget(createSidebarButton(":/icons/assets/wifi.svg", tr("Network") ));
    sidebarLayout->addWidget(createSidebarButton(":/icons/assets/pictures.svg", tr("Slideshow") ));
    sidebarLayout->addWidget(createSidebarButton(":/icons/assets/tablet-locked.svg", tr("Privacy") ));
    sidebarLayout->addWidget(createSidebarButton(":/icons/assets/attachment.svg", tr("Advanced") ));
    sidebarLayout->addWidget(createSidebarButton(":/icons/assets/cloud.svg", tr("Storage") ));
    sidebarLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Minimum, QSizePolicy::MinimumExpanding));
    sidebarLayout->setSpacing(0);
    sidebarLayout->setMargin(0);

    QWidget * sidebar = new QWidget();
    sidebar->setLayout(sidebarLayout);
    sidebar->setObjectName("sidebar");
    sidebar->setStyleSheet("QWidget#sidebar {background-color: #292929;} ");
    sidebar->setMinimumHeight(sidebarLayout->count() * 76);

    QTextBrowser *centralWidget = new QTextBrowser;
    centralWidget->setPlainText(tr("General"));
    QTextBrowser *centralWidget2 = new QTextBrowser;
    centralWidget2->setPlainText(tr("Network"));
    QTextBrowser *centralWidget3 = new QTextBrowser;
    centralWidget3->setPlainText(tr("Slideshow"));
    QTextBrowser *centralWidget4 = new QTextBrowser;
    centralWidget4->setPlainText(tr("Privacy"));
    QTextBrowser *centralWidget5 = new QTextBrowser;
    centralWidget5->setPlainText(tr("Advanced"));
    QTextBrowser *centralWidget6 = new QTextBrowser;
    centralWidget6->setPlainText(tr("Storage"));

    _stackedWidget = new QStackedWidget;
    _stackedWidget->addWidget(centralWidget);
    _stackedWidget->addWidget(centralWidget2);
    _stackedWidget->addWidget(centralWidget3);
    _stackedWidget->addWidget(centralWidget4);
    _stackedWidget->addWidget(centralWidget5);
    _stackedWidget->addWidget(centralWidget6);

    BorderLayout *layout = new BorderLayout();
    layout->addWidget(_stackedWidget, BorderLayout::Center);
    layout->addWidget(sidebar, BorderLayout::West);
    setLayout(layout);
    layout->setSpacing(0);

    setWindowTitle(tr("Settings"));
    setGeometry(0,0, 700, sidebar->minimumHeight());
}

MainWindow::~MainWindow()
{
}

/*------------------------------------------------------------------------------
 *
 *----------------------------------------------------------------------------*/

void MainWindow::changeCenterWidget(bool event)
{
    QString sender = QObject::sender()->objectName();

    if(sender.compare("General") == 0) {
        _stackedWidget->setCurrentIndex(0);
    }else if(sender.compare("Network") == 0) {
        _stackedWidget->setCurrentIndex(1);
    }else if(sender.compare("Slideshow") == 0) {
        _stackedWidget->setCurrentIndex(2);
    }else if(sender.compare("Privacy") == 0) {
        _stackedWidget->setCurrentIndex(3);
    }else if(sender.compare("Advanced") == 0) {
        _stackedWidget->setCurrentIndex(4);
    }else if(sender.compare("Storage") == 0) {
        _stackedWidget->setCurrentIndex(5);
    }
}

/*------------------------------------------------------------------------------
 *
 *----------------------------------------------------------------------------*/

QLabel *MainWindow::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setFrameStyle(QFrame::Box | QFrame::Raised);
    return label;
}

QToolButton * MainWindow::createSidebarButton(const QString& iconPath, const QString& title)
{
    QIcon icon(iconPath);

    QToolButton * btn = new QToolButton;
    btn->setIcon(icon);
    btn->setIconSize(QSize(42, 42));
    btn->setText(title);
    btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn->setFixedSize(76, 76);
    btn->setStyleSheet("QToolButton {margin: 5px; color: #ededed; background-color: #292929; border: none; font-size: 11px;} QToolButton:hover {border: 2px solid #2c92ea; border-radius: 5px;}");
    btn->setObjectName(title);
    QObject::connect(btn, SIGNAL(clicked(bool)), this, SLOT(changeCenterWidget(bool)));

    return btn;
}
