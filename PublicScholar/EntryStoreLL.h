#pragma once
#include "LinkedList.h"
#include "Entry.h"
#include "EntryBuilder.h"
#include "Exception.h"
#include <fstream>
#include <iostream>

class EntryStoreException : Exception {};
class EntriesNotLoadedException : EntryStoreException {};
class EntriesNotWrittenException : EntryStoreException {};
class EntryNotFoundException : EntryStoreException {};
class EntryNotAddedException : EntryStoreException {};

using namespace std;
class EntryStoreLL
{
protected: 
	LinkedList<Entry> * _entries;
	EntryBuilder * _entryBuilder;

public:
	// Constructs an EntryStore with an underlying Linked List data structure
	EntryStoreLL();
	// Destructor
	virtual ~EntryStoreLL();
	
	// loads entries from a file into the EntryStore
	// throws EntriesNotLoadedException on error
	void loadFromFile(String& fileName);

	// writes entries in the EntryStore to a file
	// throws EntriesNotWrittenException on error
	void writeToFile(String& fileName);

	// Finds and returns by value the first entry in the EntryStore with provided name.
	// Throws EntryNotFoundException if no matches are found.
	Entry findByName(const String& entryName);

	// Finds and returns by value the first entry in the EntryStore to pass equality.
	// Throw EntryNotFoundException if no matches are found
	Entry find(const Entry& e);

	// Removes the first entry in the EntryStore with provided name.
	// Throws EntryNotFoundException if no matches are found.
	void removeEntryByName(const String& entryName);

	// Removes the first entry in the EntryStore to pass equality.
	// Throws EntryNotFoundException if no matches are found.
	void removeEntry(const Entry& e);

	// Adds an entry to EntryStore
	// throw EntryNotAddedException on error
	void addEntry(const Entry& entry);

	// Returns the number of entries in the EntryStore
	int numberOfEntries();

	// Returns a LinkedList<Entry> * object containing the entries.
	LinkedList<Entry> * getEntries();
};