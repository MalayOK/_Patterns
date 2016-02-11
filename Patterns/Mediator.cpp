#include "Mediator.h"

namespace Patterns
{
	Colegue::Colegue(const string _id) : id(_id)
	{}
	string Colegue::GetId()const
	{
		return id;
	}

	void Colegue::RegMediator(Mediator &m)
	{ 
		mediator = &m; 

	}
	void Colegue::Receive(const string & msg)
	{
		cout  << "recived by " + id + ":" +msg << endl;
	}
	void Colegue::Send(const string _id, const string _msg)
	{
		cout << "message send by " + id << endl;
		mediator->Send(_id, _msg);
	}

	void ConcreteMediator::RegColegue(Colegue* c)
	{
		if (!IsReg(c->GetId()))
		{
			c->RegMediator(*this);
			colegues[c->GetId()] = c;
		}

	}
		
	void ConcreteMediator::Send(const string& id, const string& message)
	{
		Colegue* c = colegues[id];
		c->Receive(message);
	}

	bool ConcreteMediator::IsReg(string id)
	{
		return colegues.find(id) != colegues.end();

	}
}