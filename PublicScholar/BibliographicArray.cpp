#include "BibliographicArray.h"

BibliographicArray::BibliographicArray() :
Bibliographic()
{
}

BibliographicArray::BibliographicArray(const KeyValuePair& kvp) :
Bibliographic(kvp)
{
}

BibliographicArray::BibliographicArray(const String& key, const String& value) :
Bibliographic(key, value)
{
}

BibliographicArray::BibliographicArray(char * key, char * value) :
Bibliographic(key, value)
{
}

BibliographicArray::BibliographicArray(const Bibliographic& b) :
Bibliographic(b)
{
}


BibliographicArray::~BibliographicArray()
{
}

int BibliographicArray::size() 
{
	return getValueAsArray().size();
}

Vector<String> BibliographicArray::getValueAsArray() const
{
	return (*_keyValuePair).getValue().split(" and ");
}
