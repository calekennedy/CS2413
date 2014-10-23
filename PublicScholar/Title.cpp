#include "Title.h"

Title::Title() : BibliographicString()
{
	(*_keyValuePair).setKey(_key);
}

Title::Title(const KeyValuePair& kvp) :
BibliographicString(kvp)
{
	(*_keyValuePair).setKey(_key);
}

Title::Title(const String& value) :
BibliographicString(_key, value)
{
}

Title::Title(char * value) :
BibliographicString(_key, value)
{
}

Title::Title(const Bibliographic& b) :
BibliographicString(b)
{
	(*_keyValuePair).setKey(_key);
	(*_keyValuePair).setValue(b.getValue());
}

Title::~Title()
{
}