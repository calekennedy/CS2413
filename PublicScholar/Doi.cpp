#include "Doi.h"

Doi::Doi() : BibliographicString()
{
	(*_keyValuePair).setKey(_key);
}

Doi::Doi(const KeyValuePair& kvp) :
BibliographicString(kvp)
{
	(*_keyValuePair).setKey(_key);
}

Doi::Doi(const String& value) :
BibliographicString(_key, value) 
{
}

Doi::Doi(char * value) :
BibliographicString(_key, value)
{
}

Doi::Doi(const Bibliographic& b) :
BibliographicString(b)
{
	(*_keyValuePair).setKey(_key);
}

Doi::~Doi()
{
}