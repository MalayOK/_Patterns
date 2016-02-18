#pragma once
#include <iostream>
#include <memory>
namespace Patterns
{
	enum CannedType
	{
		_CannedFish,
		_CannedPork,
		_CannedVeal
	};

	class Canned
	{
	public:
		Canned(double _weight);
		virtual double GetWeight()const;
		virtual void info() = 0;
		virtual ~Canned();
	private:
		double weight;
	};

	class CannedFish : public Canned
	{
	public:
		CannedFish(double _weight);
		virtual double GetWeight()const;
		virtual void info();
	private:
		double weight;
	};

	class CannedPork : public Canned
	{
	public:
		CannedPork(double _weight);
		virtual double GetWeight()const;
		virtual void info();
	private:
		double weight;
	};

	class CannedVeal : public Canned
	{
	public:
		CannedVeal(double _weight);
		virtual double GetWeight()const;
		virtual void info();
	private:
		double weight;
	};

	std::shared_ptr<Canned> CreateCanned(CannedType type);



}
