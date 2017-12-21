/**
 * @file generalview.cpp
 * @author fl0mll
 * @date 2017/12/21
 *
 * This document contains proprietary information belonging to mllapps.com
 * Passing on and copying of this document, use and communication of its
 * contents is not permitted without prior written authorization.
 *
 * @brief General view implementation
 */
#include "generalview.h"
#include "ui_generalview.h"

GeneralView::GeneralView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeneralView)
{
    ui->setupUi(this);
}

GeneralView::~GeneralView()
{
    delete ui;
}
