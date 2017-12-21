/**
 * @file sidebaritem.cpp
 * @author fl0mll
 * @date 2016/06/07
 *
 * This document contains proprietary information belonging to mllapps.com
 * Passing on and copying of this document, use and communication of its
 * contents is not permitted without prior written authorization.
 *
 * @brief Settings view sidebar item implementation
 */
#include "sidebaritem.h"

#include <QLayout>
#include <QLabel>


SidebarItem::SidebarItem(QWidget *parent) : QWidget(parent)
{

    _iconLabel = new QLabel;
    _titleLabel = new QLabel;

    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(_iconLabel);
    layout->addWidget(_titleLabel);
    setLayout(layout);
}
void SidebarItem::setIconLabel(const QPixmap& icon)
{
    _iconLabel->setPixmap(icon);
}
void SidebarItem::setTitleLabel(const QString& title)
{
    _titleLabel->setText(title);
}



