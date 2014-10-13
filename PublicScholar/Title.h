#pragma once
#include "BibliographicString.h"
class Title : public BibliographicString
{
protected:
	String _key = String("title");
public:
	// constructors
	Title();
	Title(const KeyValuePair& kvp);
	Title(const String& value);
	Title(char * value);
	Title(const Bibliographic& b);

	//destructor
	virtual ~Title();
};

