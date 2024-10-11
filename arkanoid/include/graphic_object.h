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
			AbstractItem(QCustomPlot* parentPlot) : QCPAbstractItem(parentPlot) {}
			virtual ~AbstractItem() = default;

			virtual double selectTest(const QPointF& pos, bool onlySelectable, QVariant* details = 0) const = 0;
			virtual void draw(QCPPainter* painter) = 0;
		};

		template <typename T>
		struct Model final : public AbstractItem
		{
			T mData;
			QCPItemPosition* mTopLeft;

			Model(T x, QCustomPlot* plot)
				: AbstractItem(plot)
				, mData(std::move(x))
				, mTopLeft(createPosition("topLeft"))
			{
				setSelectable(false);
			}

			~Model() = default;

			void draw(QCPPainter* painter) override
			{
				::draw(mData, mTopLeft, painter);
			}

			double selectTest(const QPointF& pos, bool onlySelectable, QVariant* details = 0) const override
			{
				return ::selectTest(mData, parentPlot(), pos, onlySelectable, details);
			}

		};

		QPointer<AbstractItem> mObject;

	public:
		template<typename T> GraphicObject(T x, QCustomPlot* plot)
			: mObject(new Model<T>(std::move(x), plot))
		{
		}

		GraphicObject(GraphicObject&& x) noexcept = default;
		GraphicObject(const GraphicObject& x) noexcept = default;

		GraphicObject& operator=(GraphicObject x) noexcept
		{
			mObject = x.mObject;
			return *this;
		}

		friend void draw(const GraphicObject& obj, QCPPainter* painter)
		{
			obj.mObject->draw(painter);
		}
	};

	using GraphicObjects = std::vector<GraphicObject>;
}
#endif