#pragma once
#ifndef QRECT_SELECT_TEST_H
#define QRECT_SELECT_TEST_H

#include <QRectF>
#include <QPointF>
#include <QVariant>

class QCustomPlot;

double selectTest(const QRectF& rect, QCustomPlot* parentPlot, const QPointF& pos, bool onlySelectable, QVariant* details);

#endif