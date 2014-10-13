#pragma once
#include "String.h"

/* Declaration
----------------------------------------------------------------------------- */

class KeyValuePair
{

friend ostream& operator << (ostream& s, const KeyValuePair& kvp);

protected: 
	String * _key;
	String * _value;
	void copy(const KeyValuePair& kvp);

public:

	// constructors
	KeyValuePair(); 
	KeyValuePair(const String& key, const String& value);
	KeyValuePair(char * key, char * value);
	KeyValuePair(const KeyValuePair& kvp);

	// destructor
	virtual ~KeyValuePair();

	// accessors
	virtual String getKey() const; 
	virtual String getValue() const;

	// mutators
	virtual void setKey(const String& newKey); 
	virtual void setValue(const String& newValue); 

	virtual void display(); // display

};
