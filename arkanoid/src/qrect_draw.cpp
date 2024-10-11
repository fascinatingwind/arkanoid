#include "qrect_draw.h"

#include "qcustomplot.h"

void draw(const QRectF& rect, QCPItemPosition* top_left, QCPPainter* painter)
{
    top_left->setCoords(rect.topLeft());
	top_left->setType(QCPItemPosition::ptPlotCoords);
	painter->translate(top_left->pixelPosition());
	painter->save();
    painter->drawRect(rect);
    painter->restore();
}