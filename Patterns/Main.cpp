#include <exception>
#include <memory>
#include <iostream>
#include "Facade.h"
#include "MyException.h"
#include "Mediator.h"
#include "Adapter.h"
#include "Factory.h"
using namespace Patterns;

int main()
{
	/*try 
	{
		std::shared_ptr<FacadeForRent> f1 =
			std::make_shared <FacadeForRent>();
		int x = f1->RentYourFlat(12, 4, 5, 6);
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
		PolarSystem p(10,80);

		Adapter adapter(&p) ;
		std::shared_ptr<Point2d> p2 =
			adapter.GetCoordinate();*/

		try
		{
			std::shared_ptr<Canned> newCanned;

				newCanned=CreateCanned(CannedType::_CannedPork);
			newCanned->info();
			cout<<newCanned->GetWeight();
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