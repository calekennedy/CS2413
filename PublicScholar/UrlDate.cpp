#include "UrlDate.h"

UrlDate::UrlDate() : BibliographicString()
{
	(*_keyValuePair).setKey(_key);
}

UrlDate::UrlDate(const KeyValuePair& kvp) :
BibliographicString(kvp)
{
	(*_keyValuePair).setKey(_key);
}

UrlDate::UrlDate(const String& value) :
BibliographicString(_key, value)
{
}

UrlDate::UrlDate(char * value) :
BibliographicString(_key, value)
{
}

UrlDate::UrlDate(const Bibliographic& b) :
BibliographicString(b)
{
	(*_keyValuePair).setKey(_key);
}

UrlDate::~UrlDate()
{
}