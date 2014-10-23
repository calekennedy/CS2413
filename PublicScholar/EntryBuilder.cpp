#include "EntryBuilder.h"
#include <iostream>
using namespace std;

EntryBuilder::EntryBuilder()
{
	endOfFile = false;
	_entry = new Entry();
	_file = new ifstream();
}

EntryBuilder::EntryBuilder(String fileName)
{
	endOfFile = false;
	_file = new ifstream(fileName.getRawCharArray());
}



EntryBuilder::~EntryBuilder()
{
	if (_entry != NULL) { delete _entry; }
	if (_file != NULL) { delete _file; }
	_entry = NULL;
	_file = NULL;
}

Entry * EntryBuilder::getNextEntry()
{
	if (endOfFile) {
		return NULL;
	}
	else {
		clearState();
		createChunk();
		handleInput();
		return _entry;
	}
}

void EntryBuilder::createChunk()
{
	bool stop = false;
	bool countStarted = false;

	if ((*_file).is_open()) {
		int maxSize = 20000;
		char * line = new char[maxSize];
		while (!stop && (*_file).getline(line, maxSize)) {
			_chunk += line;
			int count = bracketCount();
			if (countStarted && count == 0) {
				stop = true;
			}
			if (!countStarted && count > 0) {
				countStarted = true;
			}
		}
		if ((*_file).eof()) {
			endOfFile = true;
			(*_file).close();
		}
		else {
			(*_entry).setChunk(_chunk);
		}
	}
	else {
		endOfFile = true;
	}
}

int EntryBuilder::bracketCount()
{
	int count = 0;
	int chunkSize = _chunk.size();
	for (int i = 0; i < chunkSize; i++) {
		char charAtIndex = _chunk[i];
		if (charAtIndex == '{') {
			count++;
		}
		if (charAtIndex == '}') {
			count--;
		}
	}
	return count;
}

void EntryBuilder::handleInput() 
{
	if (!endOfFile) {
		buildType();
		buildName();
		buildFields();
	}	
	else {
		_entry = NULL;
	}
}

void EntryBuilder::buildType() 
{
	Vector<String> arr1 = _chunk.split("@");  
	String afterAtSign = arr1[1];
	Vector<String> arr2 = afterAtSign.split("{");
	String beforeFirstBracket = arr2[0];
	String type = beforeFirstBracket;
	(*_entry).setType(type);
}

void EntryBuilder::buildName()
{
	int nameStart = _chunk.index('{', 0) + 1; // don't include the bracket
	int nameEnd = _chunk.index(',', nameStart); // don't include the comma
	int length = nameEnd - nameStart;
	String name = _chunk.substring(nameStart, length);
	(*_entry).setName(name);
}

void EntryBuilder::buildFields()
{
	FieldBuilder fieldBuilder = FieldBuilder();
	Array<String> fields = _chunk.split("\t");
	for (int i = 1; i < fields.size(); i++)
	{
		String field = fields[i];
		if (field.size() != 0) {
			Array<String> arr = field.split(" = ");
			String key = arr[0];
			String value = arr[1];
			int lastCommaIndex = value.index(',', value.length() - 4);

			if (lastCommaIndex > 0) { // the last field in each entry may not have a trailing comma
				value = value.substring(0, lastCommaIndex);
			}
			if (lastCommaIndex < 0) { // the lack of trailing comma can make things WEIRD
				int lastIndex = value.index('\0');
				value = value.substring(0, lastIndex);
			}
			// if the field is wrapped in brackets, remove them
			if (value[0] == '{') {
				value = value.substring(1, value.length() - 1);
			}
			if (value[value.length() - 1] == '}') {
				value = value.substring(0, value.length() - 1);
			}

			KeyValuePair kvp = KeyValuePair(key, value);
			(*_entry).addField(Bibliographic(kvp));
		}
	}
}

void EntryBuilder::clearState()
{
	// chunk reset
	_chunk = String();
	if (_entry != NULL) {
		delete _entry;
	}
	_entry = new Entry();
}

bool EntryBuilder::hasReachedEndOfFile()
{
	return endOfFile;
}