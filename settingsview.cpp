/**
 * @file settingsview.cpp
 * @date 2016/06/07
 * @author fl0mll
 *
 * This document contains proprietary information belonging to mllapps.com
 * Passing on and copying of this document, use and communication of its
 * contents is not permitted without prior written authorization.
 */
#include <QTextBrowser>
#include <QLabel>
#include <QPushButton>
#include <QSpacerItem>
#include <QToolButton>
#include <QDebug>
#include <QStackedWidget>

#include "settingsview.h"
#include "borderlayout.h"

#include "ui_generalview.h"

/*------------------------------------------------------------------------------
 * CTOR / DTOR
 *----------------------------------------------------------------------------*/
/**
 * @brief Create a instance of the settings widget
 *
 * @param parent
 */
SettingsView::SettingsView(QWidget *parent) :
    QWidget(parent),
    _stackedWidget(nullptr),
    _activeButton(nullptr)
{
    /* Create a layout for the sidebar */
    QWidget * sidebar = new QWidget();
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
    /* Add the sidebar layout to the sidebar widget container */
    sidebar->setLayout(sidebarLayout);
    sidebar->setObjectName("sidebar");
    sidebar->setMinimumHeight(sidebarLayout->count() * 76);

    /* Create the stacked widget */
    _stackedWidget = new QStackedWidget;

    /* Create the board layout */
    BorderLayout *layout = new BorderLayout();
    layout->addWidget(_stackedWidget, BorderLayout::Center);
    layout->addWidget(sidebar, BorderLayout::West);
    setLayout(layout);
    layout->setSpacing(0);

    setWindowTitle(tr("Settings"));
    setGeometry(0,0, 700, sidebar->minimumHeight());
}

/**
 * @brief Free allocated memory
 */
SettingsView::~SettingsView()
{
    delete _stackedWidget; _stackedWidget = nullptr;
}

/*------------------------------------------------------------------------------
 *
 *----------------------------------------------------------------------------*/
/**
 * @brief Slot to change the center widget
 *
 * @param event True if touched and false if released.
 */
void SettingsView::changeCenterWidget(bool event)
{
    Q_UNUSED(event);
    QString sender = QObject::sender()->objectName();

    if(_activeButton != nullptr) {
        _activeButton->setChecked(false);
    }

    _activeButton = static_cast<QToolButton*>(QObject::sender());
    _activeButton->setChecked(true);

    /* Remove all views from the stack if something is available */
    while(_stackedWidget->count() > 0)
    {
        pop();
    }

    if(sender.compare("General") == 0) {
        QWidget *widget = new QWidget;
        Ui::GeneralView ui;
        ui.setupUi(widget);
        push(widget);
    }else if(sender.compare("Network") == 0) {
        QTextBrowser *widget = new QTextBrowser;
        widget->setText(tr("Network"));
        push(widget);
    }else if(sender.compare("Slideshow") == 0) {
        QTextBrowser *widget = new QTextBrowser;
        widget->setText(tr("Slideshow"));
        push(widget);
    }else if(sender.compare("Privacy") == 0) {
        QTextBrowser *widget = new QTextBrowser;
        widget->setText(tr("Privacy"));
        push(widget);
    }else if(sender.compare("Advanced") == 0) {
        QTextBrowser *widget = new QTextBrowser;
        widget->setText(tr("Advanced"));
        push(widget);
    }else if(sender.compare("Storage") == 0) {
        QTextBrowser *widget = new QTextBrowser;
        widget->setText(tr("Storage"));
        push(widget);
    }
}

/*------------------------------------------------------------------------------
 *
 *----------------------------------------------------------------------------*/

/**
 * @brief Create a button for the sidebar
 *
 * @param iconPath Path to the icon
 * @param title Tile to display under the icon
 *
 * @return A new instance of a button for the sidebar
 */
QToolButton * SettingsView::createSidebarButton(const QString& iconPath, const QString& title)
{
    QIcon icon(iconPath);

    QToolButton * btn = new QToolButton;
    btn->setIcon(icon);
    btn->setIconSize(QSize(42, 42));
    btn->setText(title);
    btn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn->setFixedSize(76, 76);
    btn->setObjectName(title);
    btn->setCheckable(true);
    QObject::connect(btn, SIGNAL(clicked(bool)),
                     this, SLOT(changeCenterWidget(bool)));

    return btn;
}

/**
 * @brief Push the widget on the stack and set it active
 *
 * @param page Widget to push
 */
void SettingsView::push(QWidget *page)
{
    _stackedWidget->addWidget(page);
    _stackedWidget->setCurrentWidget(page);
}

/**
 * @brief Remove the current widget from the stack and switch to the previous
 */
void SettingsView::pop()
{
    QWidget * currentWidget = _stackedWidget->currentWidget();
    _stackedWidget->removeWidget(currentWidget);

    delete currentWidget; currentWidget = nullptr;
}
