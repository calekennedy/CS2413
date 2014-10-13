#include "BibliographicNumber.h"


BibliographicNumber::BibliographicNumber() :
Bibliographic()
{
}

BibliographicNumber::BibliographicNumber(const KeyValuePair& kvp) :
Bibliographic(kvp)
{
}

BibliographicNumber::BibliographicNumber(const String& key, const String& value) :
Bibliographic(key, value)
{
}

BibliographicNumber::BibliographicNumber(char * key, char * value) :
Bibliographic(key, value)
{
}

BibliographicNumber::BibliographicNumber(const Bibliographic& b) :
Bibliographic(b)
{
}


BibliographicNumber::~BibliographicNumber()
{
}

int BibliographicNumber::getValueAsInt() const
{
	return (*_keyValuePair).getValue().toInt();
}
