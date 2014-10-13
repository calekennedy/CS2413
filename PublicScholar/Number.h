#pragma once
#include "BibliographicNumber.h"
class Number : virtual public BibliographicNumber
{
protected:
	String _key = String("number");
public:
	// constructors
	Number();
	Number(const KeyValuePair& kvp);
	Number(const String& value);
	Number(char * value);
	Number(const Bibliographic& b);

	//destructor
	virtual ~Number();
};

