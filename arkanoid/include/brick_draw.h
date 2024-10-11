#pragma once
#ifndef BRICK_DRAW_H
#define BRICK_DRAW_H

#include "brick.h"

class QCPItemPosition;
class QCPPainter;

void draw(const Brick& brick, QCPItemPosition* top_left, QCPPainter* painter);

#endif