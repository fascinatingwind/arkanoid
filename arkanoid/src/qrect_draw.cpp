#include "qrect_draw.h"

#include "qcustomplot.h"

void draw(const QRectF& rect, QCPItemPosition* topLeft, QCPPainter* painter)
{
    topLeft->setCoords(rect.topLeft());
	topLeft->setType(QCPItemPosition::ptPlotCoords);
	painter->translate(topLeft->pixelPosition());
	painter->save();
    painter->drawRect(rect);
    painter->restore();
}