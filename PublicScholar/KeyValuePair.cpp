#include "KeyValuePair.h"

/* Definition
----------------------------------------------------------------------------- */

KeyValuePair::KeyValuePair()
{
	_key = new String();
	_value = new String();
}

KeyValuePair::KeyValuePair(const String& key, const String& value)
{
	_key = new String(key);
	_value = new String(value);
}

KeyValuePair::KeyValuePair(char * key, char * value)
{
	_key = new String(key);
	_value = new String(value);
}

KeyValuePair::KeyValuePair(const KeyValuePair& kvp)
{
	copy(kvp);
}

KeyValuePair::~KeyValuePair()
{
	if (_key != NULL) { delete _key; }
	_key = NULL;
	if (_value != NULL) { delete _value; }
	_value = NULL;
}

void KeyValuePair::copy(const KeyValuePair& kvp) 
{
	if (_key != NULL) { delete _key; }
	_key = new String((*kvp._key));
	if (_value != NULL) { delete _value;  }
	_value = new String((*kvp._value));
}

String KeyValuePair::getKey() const
{
	return (*_key);
}

String KeyValuePair::getValue() const
{
	return (*_value);
}

void KeyValuePair::setKey(const String& newKey)
{
	(*_key) = newKey;
}

void KeyValuePair::setValue(const String& newValue)
{
	(*_value) = newValue;
}

void KeyValuePair::display()
{
	cout << "\t";
	cout << *_key;
	cout << " = {";
	cout << *_value;
	cout << "},";
}

ostream& operator<< (ostream& s, const KeyValuePair& kvp)
{
	s << "\t";
	s << (*kvp._key);
	s << " = {";
	s << (*kvp._value);
	s << "},";

	return s;
}