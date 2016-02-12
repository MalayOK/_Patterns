#pragma once
#include <memory>
 namespace Patterns
{
	class Point2d
	{
	public:

		Point2d();
		Point2d(double X, double Y);
		~Point2d();
	private:
		double x, y;
	};
	class PolarSystem
	{
	public:
		PolarSystem();
		PolarSystem(float _r,float _angle);
		float GetR();
		float GetAngle();
	private:
		float angle;
		float r;
	};

	class Coordinate
	{
	public:
		virtual ~Coordinate();
		virtual std::shared_ptr <Point2d> GetCoordinate() = 0;
	};

	class Adapter : public Coordinate
	{
	public:
		Adapter(PolarSystem* polar);
		std::shared_ptr<Point2d> GetCoordinate();
	private:
		std::shared_ptr<Point2d> PolarToDecart();
		PolarSystem* adaptee;
	};
}