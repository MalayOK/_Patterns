#include <exception>
#include <memory>
#include <iostream>
#include "Facade.h"
#include "MyException.h"
#include "Mediator.h"
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
		Colegue a("a");
		Colegue b("b");
		Colegue c("c");
		ConcreteMediator m;
		m.RegColegue(&a);
		m.RegColegue(&b);
		m.RegColegue(&c);

		c.Send("a", "hello");
		a.Send("b", "hi");
	return 0;
}

