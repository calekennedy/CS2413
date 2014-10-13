#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include "Entry.h"
#include "KeyValuePair.h"
#include "FieldBuilder.h"
using namespace std;

class EntryBuilder
{
private:

	Entry * _entry;
	
	int bracketCount(); // keep track of open and close brackets

	String _chunk; // the entry as one giant chunk

	void createChunk(); // reads the file and produces a single char array for the entry

	void handleInput(); // takes the chunk and turns it into an Entry

	void buildType(); // reads the chunk and builds the type field on the entry

	void buildName(); // reads the chunk and builds the name field on the entry

	void buildFields(); // reads the chunks and adds the "fields" (kvp's) on the entry.

	void clearState(); // clears the state of the class instance.

	bool endOfFile; // flag used to indicate end of file

	ifstream * _file;

public:
	// constructor and destructor
	EntryBuilder();
	EntryBuilder(String fileName);
	~EntryBuilder();

	// public method that reads the file and builds the components for an entry
	Entry * getNextEntry();

	// bool indicating when end of file is reached, used in PublicScholar.cpp (main)
	bool hasReachedEndOfFile();
};

