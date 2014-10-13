#pragma once
#include "BibliographicString.h"
class Url : public BibliographicString
{
protected:
	String _key = String("url");
public:
	// constructors
	Url();
	Url(const KeyValuePair& kvp);
	Url(const String& value);
	Url(char * value);
	Url(const Bibliographic& b);

	//destructor
	virtual ~Url();
};

