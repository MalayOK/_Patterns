#pragma once
#include <exception>
#include <memory>
using namespace std;
namespace Patterns
{
	class RentAppartment
	{
	public:
		  int FlatRent(const int quantity_of_month,
			const int number_of_rooms);
	};

	class Heating
	{
	  public:
	      int PaymentForHeating(const int number_of_month);
	};

	class Service
	{
	public:
		int PaymentForService(const int quality_of_service);
	};

	class FacadeForRent
	{
	public:
		int RentYourFlat(const int quantity_of_month,
			const int number_of_rooms, const int number_of_month,
			const int quality_of_service);
	private:
		std::shared_ptr<RentAppartment> ptr_rent_app =
			std::make_shared<RentAppartment>();
		std::shared_ptr<Heating> ptr_heating =
			std::make_shared<Heating>();
		std::shared_ptr<Service> ptr_service =
			std::make_shared<Service>();
	};
}
