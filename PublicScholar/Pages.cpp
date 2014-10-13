#include "Pages.h"

Pages::Pages() : BibliographicString()
{
	(*_keyValuePair).setKey(_key);
}

Pages::Pages(const KeyValuePair& kvp) :
BibliographicString(kvp)
{
	(*_keyValuePair).setKey(_key);
}

Pages::Pages(const String& value) :
BibliographicString(_key, value)
{
}

Pages::Pages(char * value) :
BibliographicString(_key, value)
{
}

Pages::Pages(const Bibliographic& b) :
BibliographicString(b)
{
	(*_keyValuePair).setKey(_key);
}

Pages::~Pages()
{
}