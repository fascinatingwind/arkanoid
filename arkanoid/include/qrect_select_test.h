#pragma once
#ifndef QRECT_SELECT_TEST_H
#define QRECT_SELECT_TEST_H

#include <QRectF>
#include <QPointF>
#include <QVariant>

class QCustomPlot;

double selectTest(const QRectF& rect, QCustomPlot* parent_plot, const QPointF& pos, bool only_selectable, QVariant* details);

#endif