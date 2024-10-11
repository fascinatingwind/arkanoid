#pragma once
#ifndef QRECT_DRAW_H
#define QRECT_DRAW_H

#include <QRectF>

class QCPItemPosition;
class QCPPainter;

void draw(const QRectF& rect, QCPItemPosition* top_left, QCPPainter* painter);

#endif