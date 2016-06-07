#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "borderlayout.h"

#include <QTextBrowser>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout * sidebarLayout = new QVBoxLayout();
    sidebarLayout->addWidget(new QPushButton("General"));
    sidebarLayout->addWidget(new QPushButton("Network"));
    sidebarLayout->addWidget(new QPushButton("Slideshow"));
    sidebarLayout->addWidget(new QPushButton("Privacy"));
    sidebarLayout->addWidget(new QPushButton("Advanced"));
    sidebarLayout->addSpacerItem(new QSpacerItem(0,0,QSizePolicy::Minimum, QSizePolicy::MinimumExpanding));

    QWidget * sidebar = new QWidget();
    sidebar->setLayout(sidebarLayout);

    QTextBrowser *centralWidget = new QTextBrowser;
    centralWidget->setPlainText(tr("Central widget"));

    BorderLayout *layout = new BorderLayout;
    layout->addWidget(centralWidget, BorderLayout::Center);
    layout->addWidget(sidebar, BorderLayout::West);
    setLayout(layout);

    setWindowTitle(tr("Border Layout"));
}

MainWindow::~MainWindow()
{
}

QLabel *MainWindow::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setFrameStyle(QFrame::Box | QFrame::Raised);
    return label;
}
