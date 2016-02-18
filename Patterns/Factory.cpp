#include "Factory.h"

namespace Patterns
{
	Canned::Canned(double _weight) : weight(_weight){}
	
	Canned::~Canned(){}

	double Canned::GetWeight()const
	{
		return weight;
	}
	CannedFish::CannedFish(double _weight) : Canned(_weight) {}

	double CannedFish::GetWeight()const
	{
		return this->weight;
	}

	void CannedFish::info()
	{
		std::cout << "CannedFish, weight : " << this->weight << std::endl;
	}

	CannedPork::CannedPork(double _weight) : Canned(_weight) {}

	double CannedPork::GetWeight()const
	{
		return weight;
	}

	void CannedPork::info()
	{
		std::cout << "CannedPork, weight : " << weight << std::endl;
	}

	CannedVeal::CannedVeal(double _weight) : Canned(_weight) {}

	double CannedVeal::GetWeight()const
	{
		return weight;
	}

	void CannedVeal::info()
	{
		std::cout << "CannedVeal, weight : " << weight << std::endl;
	}

	std::shared_ptr<Canned> CreateCanned(CannedType type)
	{
		std::shared_ptr<Canned> newCanned;
		switch (type)
		{
		case CannedType::_CannedFish:
			newCanned = std::make_shared <CannedFish>(500.1);
			break;
		case CannedType::_CannedPork:
			newCanned = std::make_shared <CannedPork>(470.5);
			break;
		case CannedType::_CannedVeal:
			newCanned = std::make_shared <CannedVeal>(420.12);
			break;
		default :
				throw std::runtime_error("Canned not created");
			break;
		}
		return newCanned;
	}
}