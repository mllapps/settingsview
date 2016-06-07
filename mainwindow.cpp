#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "borderlayout.h"

#include <QTextBrowser>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)
{
    QTextBrowser *centralWidget = new QTextBrowser;
    centralWidget->setPlainText(tr("Central widget"));

    BorderLayout *layout = new BorderLayout;
    layout->addWidget(centralWidget, BorderLayout::Center);
    layout->addWidget(createLabel("North"), BorderLayout::North);
    layout->addWidget(createLabel("West 1"), BorderLayout::West);
    layout->addWidget(createLabel("West 200000000"), BorderLayout::West);
    layout->addWidget(createLabel("West 3"), BorderLayout::West);
    layout->addWidget(createLabel("East 1"), BorderLayout::East);
    layout->addWidget(createLabel("East 2") , BorderLayout::East);
    layout->addWidget(createLabel("East 3") , BorderLayout::East);
    layout->addWidget(createLabel("South"), BorderLayout::South);
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
