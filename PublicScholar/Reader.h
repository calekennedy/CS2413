#pragma once
#include <fstream>
#include <iostream>
#include "String.h"
using namespace std;

class Reader
{
private:
	char lastChar; // storage for last char read from file
	bool expectingAtSign; // used to detect end of file
	int bracketCount; // used to detect end of file
	int countSinceExpecting; // used to detect end of file
	ifstream * _file;

public:
	Reader();
	Reader(const String& fileName);
	~Reader();

	String getFileName();
	void setFileName(const String& fileName);

	bool getNextLine(const String& line); // returns the most recently stored char
};

