#include "Number.h"

Number::Number() : BibliographicNumber()
{
	(*_keyValuePair).setKey(_key);
}

Number::Number(const KeyValuePair& kvp) :
BibliographicNumber(kvp)
{
	(*_keyValuePair).setKey(_key);
}

Number::Number(const String& value) :
BibliographicNumber(_key, value)
{
}

Number::Number(char * value) :
BibliographicNumber(_key, value)
{
}

Number::Number(const Bibliographic& b) :
BibliographicNumber(b)
{
	(*_keyValuePair).setKey(_key);
	(*_keyValuePair).setValue(b.getValue());
}

Number::~Number()
{
}