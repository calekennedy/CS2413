#include "Bibliographic.h"

Bibliographic::Bibliographic()
{
	_keyValuePair = new KeyValuePair();
}

Bibliographic::Bibliographic(const KeyValuePair& kvp)
{
	_keyValuePair = new KeyValuePair(kvp);
}

Bibliographic::Bibliographic(const String& key, const String& value)
{
	_keyValuePair = new KeyValuePair(key, value);
}

Bibliographic::Bibliographic(char * key, char * value)
{
	_keyValuePair = new KeyValuePair(key, value);
}

Bibliographic::Bibliographic(const Bibliographic& b)
{
	copy(b);
}

void Bibliographic::copy(const Bibliographic& b)
{
	_keyValuePair = new KeyValuePair(b.getKey(), b.getValue());
}


Bibliographic::~Bibliographic()
{
	if (_keyValuePair != NULL) {
		delete _keyValuePair;
		_keyValuePair = NULL;
	}	
}

String Bibliographic::getKey() const
{
	return (*_keyValuePair).getKey();
}

String Bibliographic::getValue() const
{
	return (*_keyValuePair).getValue();
}

void Bibliographic::setKey(const String& newKey)
{
	(*_keyValuePair).setKey(newKey);
}

void Bibliographic::setValue(const String& newValue)
{
	(*_keyValuePair).setValue(newValue);
}

void Bibliographic::display()
{
	(*_keyValuePair).display();
}

int Bibliographic::size()
{
	return (*_keyValuePair).getValue().length();
}

ostream& operator << (ostream& s, const Bibliographic& b)
{
	s << (*b._keyValuePair);
	return s;
}