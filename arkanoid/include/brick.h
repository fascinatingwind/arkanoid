#pragma once
#ifndef BRICK_H
#define BRICK_H

#include <QRectF>
#include <QColor>

struct Brick
{
    size_t hits = 1;
    QRectF bound;
    QColor color;
};

#endif