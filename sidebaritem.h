/**
 * @file sidebaritem.h
 * @author fl0mll
 * @date 2016/06/07
 *
 * This document contains proprietary information belonging to mllapps.com
 * Passing on and copying of this document, use and communication of its
 * contents is not permitted without prior written authorization.
 *
 * @brief Settings view sidebar item interface
 */

#ifndef SIDEBARITEM_H
#define SIDEBARITEM_H

#include <QWidget>

class QLabel;

class SidebarItem : public QWidget
{
    Q_OBJECT
public:
    explicit SidebarItem(QWidget *parent = 0);

    void setIconLabel(const QPixmap& icon);
    void setTitleLabel(const QString& title);

signals:

public slots:

private:
    QLabel * _iconLabel;
    QLabel * _titleLabel;
};

#endif // SIDEBARITEM_H
