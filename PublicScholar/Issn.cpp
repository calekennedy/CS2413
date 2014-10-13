#include "Issn.h"

Issn::Issn() : BibliographicString()
{
	(*_keyValuePair).setKey(_key);
}

Issn::Issn(const KeyValuePair& kvp) :
BibliographicString(kvp)
{
	(*_keyValuePair).setKey(_key);
}

Issn::Issn(const String& value) :
BibliographicString(_key, value)
{
}

Issn::Issn(char * value) :
BibliographicString(_key, value)
{
}

Issn::Issn(const Bibliographic& b) :
BibliographicString(b)
{
	(*_keyValuePair).setKey(_key);
}

Issn::~Issn()
{
}
