#include <exception>
#include "Facade.h"
#include "MyException.h"
using namespace std;
namespace Patterns
{
	 
	int RentAppartment::FlatRent(const int quantity_of_month,
		const int number_of_rooms)
	{
		if (quantity_of_month<1 )
			throw std::runtime_error("Wrong quantity of months");
		if (number_of_rooms>5 || number_of_rooms<1)
			throw std::runtime_error("Wrong quantity of rooms");
		switch (number_of_rooms)
		{
		case 1:
			return quantity_of_month * 1000;
			break;
		case 2:
			return quantity_of_month * 1500;
			break;
		case 3:
			return quantity_of_month * 2000;
			break;
		case 4:
			return quantity_of_month * 2500;
			break;
		case 5:
			return quantity_of_month * 3000;
			break;
		}
	}

	int Heating::PaymentForHeating(const int number_of_month)
	{
		if (number_of_month < 1 || number_of_month>12)
			throw std::runtime_error("Wrong  month");
		return (number_of_month > 3 && number_of_month < 10) ? 0 : 400;
	}

	int Service::PaymentForService(const int quality_of_service)
	{
		if (quality_of_service < 1 || quality_of_service>3)
			throw std::runtime_error("Wrong  quality of service");
		switch (quality_of_service)
		{
		case 1:
			return 200;
			break;
		case 2:
			return 300;
			break;
		case 3:
			return 400;
			break;
		}

	}

	int FacadeForRent::RentYourFlat(const int quantity_of_month,
		const int number_of_rooms, const int number_of_month,
		const int quality_of_service)
	{
		int	rent_price = ptr_rent_app->FlatRent(quantity_of_month, number_of_rooms);
		int heting_price = ptr_heating->PaymentForHeating(number_of_month);
		int service_price = ptr_service->PaymentForService(quality_of_service);
		return rent_price + heting_price + service_price;

	}
	
}