/**
 * @file generalview.h
 * @author fl0mll
 * @date 2017/12/21
 *
 * This document contains proprietary information belonging to mllapps.com
 * Passing on and copying of this document, use and communication of its
 * contents is not permitted without prior written authorization.
 *
 * @brief General view interface
 */
#ifndef GENERALVIEW_H
#define GENERALVIEW_H

#include <QWidget>

namespace Ui {
class GeneralView;
}

class GeneralView : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralView(QWidget *parent = 0);
    ~GeneralView();

private:
    Ui::GeneralView *ui;
};

#endif // GENERALVIEW_H
