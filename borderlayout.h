/**
 * @file borderlayout.h
 * @author fl0mll
 * @date 2016/06/07
 *
 * This document contains proprietary information belonging to mllapps.com
 * Passing on and copying of this document, use and communication of its
 * contents is not permitted without prior written authorization.
 *
 * @brief Interface of the border layout
 */

#ifndef BORDERLAYOUT_H
#define BORDERLAYOUT_H

#include <QLayout>
#include <QRect>

class BorderLayout : public QLayout
{
public:
    enum Position { West, North, South, East, Center };

    explicit BorderLayout(QWidget *parent, int margin = 0, int spacing = -1);
    BorderLayout(int spacing = -1);
    ~BorderLayout();

    void addItem(QLayoutItem *item) Q_DECL_OVERRIDE;
    void addWidget(QWidget *widget, Position position);
    Qt::Orientations expandingDirections() const Q_DECL_OVERRIDE;
    bool hasHeightForWidth() const Q_DECL_OVERRIDE;
    int count() const Q_DECL_OVERRIDE;
    QLayoutItem *itemAt(int index) const Q_DECL_OVERRIDE;
    QSize minimumSize() const Q_DECL_OVERRIDE;
    void setGeometry(const QRect &rect) Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;
    QLayoutItem *takeAt(int index) Q_DECL_OVERRIDE;

    void add(QLayoutItem *item, Position position);

private:
    struct ItemWrapper
    {
        ItemWrapper(QLayoutItem *i, Position p) {
            item = i;
            position = p;
        }

        QLayoutItem *item;
        Position position;
    };

    enum SizeType { MinimumSize, SizeHint };
    QSize calculateSize(SizeType sizeType) const;

    QList<ItemWrapper *> list;
};

#endif // BORDERLAYOUT_H
