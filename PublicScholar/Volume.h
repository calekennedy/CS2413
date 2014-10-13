#pragma once
#include "BibliographicNumber.h"
class Volume : public BibliographicNumber
{
protected:
	String _key = String("volume");
public:
	// constructors
	Volume();
	Volume(const KeyValuePair& kvp);
	Volume(const String& value);
	Volume(char * value);
	Volume(const Bibliographic& b);

	//destructor
	virtual ~Volume();
};

