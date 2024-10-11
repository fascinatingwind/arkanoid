#include "qrect_select_test.h"

double selectTest(const QRectF& rect, QCustomPlot* parentPlot, const QPointF& pos, bool onlySelectable, QVariant* details)
{
    if(rect.contains(pos))
    {
        return 0;
    }
    return -1;
}