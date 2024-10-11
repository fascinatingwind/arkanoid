#pragma once
#ifndef GRAPHIC_OBJECT_H
#define GRAPHIC_OBJECT_H

#include "qcustomplot.h"
#include "functions_draw.h"
#include "functions_select_test.h"

#include <QObject>
#include <QPalette>
#include <QPointer>

namespace Concept
{
	class GraphicObject
	{
		struct AbstractItem : public QCPAbstractItem
		{
			AbstractItem(QCustomPlot* parent_plot) : QCPAbstractItem(parent_plot) {}
			virtual ~AbstractItem() = default;

			virtual double selectTest(const QPointF& pos, bool only_selectable, QVariant* details = 0) const = 0;
			virtual void draw(QCPPainter* painter) = 0;
		};

		template <typename T>
		struct Model final : public AbstractItem
		{
			T data;
			QCPItemPosition* top_left;

			Model(T x, QCustomPlot* plot)
				: AbstractItem(plot)
				, data(std::move(x))
				, top_left(createPosition("topLeft"))
			{
				setSelectable(false);
			}

			~Model() = default;

			void draw(QCPPainter* painter) override
			{
				::draw(data, top_left, painter);
			}

			double selectTest(const QPointF& pos, bool only_selectable, QVariant* details = 0) const override
			{
				return ::selectTest(data, parentPlot(), pos, only_selectable, details);
			}

		};

		QPointer<AbstractItem> object;

	public:
		template<typename T> GraphicObject(T x, QCustomPlot* plot)
			: object(new Model<T>(std::move(x), plot))
		{
		}

		GraphicObject(GraphicObject&& x) noexcept = default;
		GraphicObject(const GraphicObject& x) noexcept = default;

		GraphicObject& operator=(GraphicObject x) noexcept
		{
			object = x.object;
			return *this;
		}

		friend void draw(const GraphicObject& obj, QCPPainter* painter)
		{
			obj.object->draw(painter);
		}
	};

	using GraphicObjects = std::vector<GraphicObject>;
}
#endif