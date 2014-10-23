#include "Url.h"

Url::Url() : BibliographicString()
{
	(*_keyValuePair).setKey(_key);
}

Url::Url(const KeyValuePair& kvp) :
BibliographicString(kvp)
{
	(*_keyValuePair).setKey(_key);
}

Url::Url(const String& value) :
BibliographicString(_key, value)
{
}

Url::Url(char * value) :
BibliographicString(_key, value)
{
}

Url::Url(const Bibliographic& b) :
BibliographicString(b)
{
	(*_keyValuePair).setKey(_key);
	(*_keyValuePair).setValue(b.getValue());
}

Url::~Url()
{
}