#include "brick_draw.h"

#include "qcustomplot.h"
#include <qnamespace.h>

void draw(const Brick& brick, QCPItemPosition* top_left, QCPPainter* painter)
{
    top_left->setCoords(brick.bound.topLeft());
	top_left->setType(QCPItemPosition::ptPlotCoords);
	painter->translate(top_left->pixelPosition());
	painter->save();
    painter->setBrush(brick.color);
    painter->setPen(Qt::NoPen);
    painter->drawRect(brick.bound);
    painter->restore();
}