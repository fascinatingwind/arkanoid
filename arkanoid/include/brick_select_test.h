#pragma once
#ifndef BRICK_SELECT_TEST_H
#define BRICK_SELECT_TEST_H

#include <QRectF>
#include <QPointF>
#include <QVariant>

#include "brick.h"

class QCustomPlot;

double selectTest(const Brick& rect, QCustomPlot* parent_plot, const QPointF& pos, bool only_selectable, QVariant* details);

#endif