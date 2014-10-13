#pragma once
#include "BibliographicString.h"
class UrlDate : public BibliographicString
{
protected:
	String _key = String("urldate");
public:
	// constructors
	UrlDate();
	UrlDate(const KeyValuePair& kvp);
	UrlDate(const String& value);
	UrlDate(char * value);
	UrlDate(const Bibliographic& b);

	//destructor
	virtual ~UrlDate();
};

