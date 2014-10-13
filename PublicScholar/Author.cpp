#include "Author.h"

Author::Author() : BibliographicArray()
{
	(*_keyValuePair).setKey(_key);
}

Author::Author(const KeyValuePair& kvp) :
BibliographicArray(kvp)
{
	(*_keyValuePair).setKey(_key);
}

Author::Author(const String& value) : 
BibliographicArray(_key, value)
{
}

Author::Author(char * value) : 
BibliographicArray(_key, value)
{
}

Author::Author(const Bibliographic& b) : 
BibliographicArray(b)
{
	(*_keyValuePair).setKey(_key);
}

Author::~Author()
{
}