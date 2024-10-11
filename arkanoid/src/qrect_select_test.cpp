#include "qrect_select_test.h"

double selectTest(const QRectF& rect, QCustomPlot* parent_plot, const QPointF& pos, bool only_selectable, QVariant* details)
{
    if(rect.contains(pos))
    {
        return 0;
    }
    return -1;
}