/*
	Author: Cale Kennedy
	Date: 2014 Sep 28
	Crediting: Dr. Hougen's CS 2413 Lecture Slides
	Description: definition for string class
*/

#include "String.h"

/* Definition
----------------------------------------------------------------------------- */

String::String() : Vector<char>(), Array<char>()
{
	paObject[0] = '\0';
}

String::String(int n) : Vector<char>(n+1), Array<char>(n+1)
{
	paObject[n] = '\0';
}

String::String(const String& str) : Vector<char>(str), Array<char>(str)
{
}

String::String(char* s) : Vector<char>(strlen(s) + 1), Array<char>(strlen(s) + 1)
{
	strcpy(paObject, s);
	_currSize = strlen(s);
	if (paObject[_currSize] != '\0') {
		paObject[_currSize] = '\0';
	}
}

String::~String()
{
}

void String::operator= (const String& str)
{
	Vector<char>::operator= (str);
	return;
}

int String::length() const
{
	return _currSize;
}

bool String::operator== (const String& str) const
{
	return (strcmp(paObject, str.paObject) == 0);
}

bool String::operator< (const String& str) const
{
	return (strcmp(paObject, str.paObject) < 0);
}

bool String::operator> (const String& str) const
{
	return (strcmp(paObject, str.paObject) > 0);
}

bool String::equalsIgnoreCase(const String& str)
{
	return (_stricmp(paObject, str.paObject) == 0);
}

void String::concatenate(const String& str)
{
	// add other string
	for (int i = 0; i < str.length(); i++) {
		add(str.paObject[i]);
	}
	// add null terminator
	if (str.length() > 0) {
		add('\0');
	}	
}

String String::operator+ (const String& str) {
	String temp(length() + str.length());
	temp = (*this);
	temp.concatenate(str);
	return temp;
}

void String::operator+= (const String& str) {
	(*this).concatenate(str);
}

int String::index(char c, int start) const
{
	// if start is past the end, obviously character isn't present
	if (start >= length()) { return -1; }

	// pointer arithmetic. only work if underlying data structure uses contiguous memory
	char* pc = strchr(paObject + start, c);
	if (pc == NULL) { return -1; }
	return (pc - paObject);
}

String String::substring(int left, int len) const
{
	// a negative index is illegal
	if (left < 0)
	{
		throw ArrayBoundsException();
	}
	// no need to throw exception if left is at least legal, in not actually in bounds
	String sub(len);
	if (left > length() || len == 0)
	{
		return sub;
	}

	int max = len;
	if (max + left > length()) // keep strncpy from going out of bounds
	{
		max = length() - left;
	}

	strncpy(sub.paObject, &paObject[left], max);
	sub.paObject[max] = '\0';
	sub._currSize = max; // have to set vector field since we're using strncpy
	return sub;
}

Vector<String> String::split(const String& s) const
{
	Vector<String> v = Vector<String>();
	int left = 0;

	String compareString = s;
	bool isMatch = false;

	for (int i = 0; i < size(); i++) {

		char charAtIndex = paObject[i];

		if (charAtIndex == compareString[0]) {
			isMatch = true;
			// look ahead for match
			// don't reevaluate 0 index, we already know it matches.
			int size = compareString.size();
			for (int j = 1; j < size; j++)
			{
				if (paObject[i + j] != compareString[j]) {
					isMatch = false;
					break;
				}
				else {
					continue;
				}
			}

			if (isMatch) {
				// split string
				int len = i - left;
				String subString = substring(left, len);
				v.add(subString);
				left = i + compareString.length();
				i = left; // skip ahead
			}
		}
		else {
			continue;
		}
	}

	if (left < size()) {
		int len = size() - left;
		String subString = substring(left, len);
		v.add(subString);
	}
	return v;
}

int String::toInt() const
{
	return atoi(paObject);
}

ostream& operator<< (ostream& s, const String& str)
{
	s << str.paObject;
	return s;
}

int String::index(char c) const
{
	return index(c, 0);
}

char * String::getRawCharArray() {
	return paObject;
}
