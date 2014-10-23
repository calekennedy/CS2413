/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Dr. Hougen's CS 2413 Lecture Slides
	Description: Base class implementation of string
*/

#pragma once
#include "Vector.h"
#include <cstring>


/* Declaration
----------------------------------------------------------------------------- */

class String : virtual public Vector<char>
{

friend ostream& operator << (ostream& s, const String& str);

public:

	// constructors
	String();
	String(int n);
	String(const String& str);
	String(char * s); // new!

	// virtual destructor 
	virtual ~String();

	// overloaded operators.
	void operator= (const String& str);
	virtual bool operator== (const String& str) const;
	virtual bool operator< (const String& str) const;
	virtual bool operator> (const String& str) const;
	virtual String operator+ (const String& str);
	virtual void operator+= (const String& str);

	// method for case insensitive comparison
	virtual bool equalsIgnoreCase(const String& str);

	// gets the length of the string
	virtual int length() const;

	// appends a string onto this string, if there is capacity
	virtual void concatenate(const String& str);
	// first index of char c after start index
	virtual int index(char c, int start) const;
	// first index of c in the array
	virtual int index(char c) const;
	// get the substring starting from the left index going len characters.
	virtual String substring(int left, int len) const;

	// splits the string into an array of strings
	virtual Vector<String> split(const String& s) const;
	// casts the value of the string as an integer
	virtual int toInt() const;

	virtual char * getRawCharArray();
	
};


