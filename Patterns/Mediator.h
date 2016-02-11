#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <map>

using namespace std;

namespace Patterns
{
	class Mediator
	{
	public:
		virtual void Send(const string& id, const string& message) = 0;
	};

	class Colegue
	{
	public:
		Colegue(const string _id);
		string GetId()const;
		void RegMediator(Mediator &m); 
		void Receive(const string & msg);
		void Send(const string _id, const string _msg);
	private:
		Mediator* mediator;
		string id;
	};

	class ConcreteMediator : public Mediator
	{
	public:
		void RegColegue(Colegue* c);
	    void Send(const string& id, const string& message);
	private:
		bool IsReg(string id);
		map <string, Colegue*> colegues;

	};
};
