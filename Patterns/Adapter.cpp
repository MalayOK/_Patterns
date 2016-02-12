#define _USE_MATH_DEFINES // for PI
#include <iostream>
#include <cmath>
#include "Adapter.h"
#include <memory>

namespace Patterns
{
	Point2d::Point2d()
	{

		std::cout << "In Point2d Constructor\n";
	}

	Point2d::Point2d(double X, double Y) :x(X), y(Y)
	{
		std::cout << "In Point2d Constructor\n";
	}

	Point2d::~Point2d()
	{
		std::cout << "In Point2d Destructor\n";
	}

	PolarSystem::PolarSystem()
	{
		 r = 7;
		 angle = 90;
	}
	PolarSystem::PolarSystem(float _r, float _angle)
	{
		 r = _r;
		 angle = _angle;
	}
	float PolarSystem::GetR()
	{
		return r;
	}

	float PolarSystem::GetAngle()
	{
		return angle;
	}

	Coordinate::~Coordinate()
	{}

	Adapter::Adapter(PolarSystem* polar)
	{
		adaptee = polar;
	}

	std::shared_ptr<Point2d> Adapter::GetCoordinate()
	{
		return PolarToDecart();
	}

	std::shared_ptr<Point2d> Adapter::PolarToDecart()
	{
		double r = adaptee->GetR();
		double angle = adaptee->GetAngle();
		double	x = r*cos(angle*M_PI / 180);
		double  y = r*sin(angle*M_PI / 180);
		std::shared_ptr<Point2d> point =
			std::make_shared<Point2d>(x, y);

		return point;
	}
}