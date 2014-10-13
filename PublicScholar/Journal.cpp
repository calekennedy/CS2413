#include "Journal.h"

Journal::Journal() : BibliographicString()
{
	(*_keyValuePair).setKey(_key);
}

Journal::Journal(const KeyValuePair& kvp) :
BibliographicString(kvp)
{
	(*_keyValuePair).setKey(_key);
}

Journal::Journal(const String& value) :
BibliographicString(_key, value)
{
}

Journal::Journal(char * value) :
BibliographicString(_key, value)
{
}

Journal::Journal(const Bibliographic& b) :
BibliographicString(b)
{
	(*_keyValuePair).setKey(_key);
}

Journal::~Journal()
{
}