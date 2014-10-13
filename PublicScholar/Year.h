#pragma once
#include "BibliographicNumber.h"
class Year : public BibliographicNumber
{
protected:
	String _key = String("year");
public:
	// constructors
	Year();
	Year(const KeyValuePair& kvp);
	Year(const String& value);
	Year(char * value);
	Year(const Bibliographic& b);

	//destructor
	virtual ~Year();
};

