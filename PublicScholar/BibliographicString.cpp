#include "BibliographicString.h"

BibliographicString::BibliographicString() :
Bibliographic()
{
}

BibliographicString::BibliographicString(const KeyValuePair& kvp) :
Bibliographic(kvp)
{
}

BibliographicString::BibliographicString(const String& key, const String& value) :
Bibliographic(key, value)
{
}

BibliographicString::BibliographicString(char * key, char * value) :
Bibliographic(key, value)
{
}

BibliographicString::BibliographicString(const Bibliographic& b) :
Bibliographic(b)
{
}


BibliographicString::~BibliographicString()
{
}
