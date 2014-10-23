#include "Month.h"

Month::Month() : BibliographicString()
{
	(*_keyValuePair).setKey(_key);
}

Month::Month(const KeyValuePair& kvp) :
BibliographicString(kvp)
{
	(*_keyValuePair).setKey(_key);
}

Month::Month(const String& value) :
BibliographicString(_key, value)
{
}

Month::Month(char * value) :
BibliographicString(_key, value)
{
}

Month::Month(const Bibliographic& b) :
BibliographicString(b)
{
	(*_keyValuePair).setKey(_key);
	(*_keyValuePair).setValue(b.getValue());
}

Month::~Month()
{
}