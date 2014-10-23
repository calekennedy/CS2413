#include "Volume.h"

Volume::Volume() : BibliographicNumber()
{
	(*_keyValuePair).setKey(_key);
}

Volume::Volume(const KeyValuePair& kvp) :
BibliographicNumber(kvp)
{
	(*_keyValuePair).setKey(_key);
}

Volume::Volume(const String& value) :
BibliographicNumber(_key, value)
{
}

Volume::Volume(char * value) :
BibliographicNumber(_key, value)
{
}

Volume::Volume(const Bibliographic& b) :
BibliographicNumber(b)
{
	(*_keyValuePair).setKey(_key);
	(*_keyValuePair).setValue(b.getValue());
}

Volume::~Volume()
{
}