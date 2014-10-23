#include "Year.h"

Year::Year() : BibliographicNumber()
{
	(*_keyValuePair).setKey(_key);
}

Year::Year(const KeyValuePair& kvp) :
BibliographicNumber(kvp)
{
	(*_keyValuePair).setKey(_key);
}

Year::Year(const String& value) :
BibliographicNumber(_key, value)
{
}

Year::Year(char * value) :
BibliographicNumber(_key, value)
{
}

Year::Year(const Bibliographic& b) :
BibliographicNumber(b)
{
	(*_keyValuePair).setKey(_key);
	(*_keyValuePair).setValue(b.getValue());
}

Year::~Year()
{
}