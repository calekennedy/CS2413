#pragma once
#include "Vector.h"
#include "Entry.h"
#include "EntryBuilder.h"
#include <fstream>
#include <iostream>

using namespace std;

class EntryStore
{
private:

	Vector<Entry*> * _entries;
	EntryBuilder * _entryBuilder;

protected:
	virtual int search(const String& entryName);
	virtual int binarySearch(const String& entryName, int left, int right);

public:
	EntryStore();
	virtual ~EntryStore();

	void loadFromFile(String& fileName);
	void writeToFile(String& fileName);

	Entry findByName(const String& entryName);
	void removeEntry(const String& entryName);
	void addEntry(const Entry& entry);

	int numberOfEntries();
	Vector<Entry*> getEntries();
};