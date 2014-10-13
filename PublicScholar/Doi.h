#pragma once
#include "BibliographicString.h"
class Doi : virtual public BibliographicString
{
protected:
	String _key = String("doi");
public:
	// constructors
	Doi();
	Doi(const KeyValuePair& kvp);
	Doi(const String& value);
	Doi(char * value);
	Doi(const Bibliographic& b);

	//destructor
	virtual ~Doi();
};

