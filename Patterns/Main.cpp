#include <exception>
#include <memory>
#include <iostream>
#include "Facade.h"
#include "MyException.h"
using namespace Patterns;

int main()
{
	try 
	{
		std::shared_ptr<FacadeForRent> f1 =
			std::make_shared <FacadeForRent>();
		int x = f1->RentYourFlat(12, 4, 5, 6);
	}

		catch (myexception& ex)
	{
		std::cout << "This is my exception!" << ex.what() << std::endl; 
	}
		catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl; 
	}
		catch (...)
	{
		std::cout << "Catched exception" << std::endl; 
	}
	return 0;
}