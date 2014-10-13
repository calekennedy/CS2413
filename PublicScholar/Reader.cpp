#include "Reader.h"

Reader::Reader()
{
	bracketCount = 0;
	expectingAtSign = true;
	countSinceExpecting = 0;
	_file = new ifstream();
}

Reader::Reader(const String& fileName)
{
	bracketCount = 0;
	expectingAtSign = true;
	countSinceExpecting = 0;
	char * filename = fileName.getRawCharArray();
	_file = new ifstream();
}


Reader::~Reader()
{
	if (_fileName != NULL) {
		delete _fileName;
	}
	_fileName = NULL;
}

bool Reader::getNextLine()
{
	if ((*_file).is_open()) {
		char * nextLine;
		getline((*_file), nextLine);
	}
	else {
		return false;
	}
	char a = cin.get();
	int sizeOfTypeField = 20;
	if (expectingAtSign && countSinceExpecting > sizeOfTypeField) {
		lastChar = '\0';
		return false;
	}
	else {
		if (a == '{') { bracketCount++; }
		if (a == '}') { bracketCount--; }
		if (bracketCount == 0) {
			expectingAtSign = true;
			countSinceExpecting++;
		}
		if (bracketCount != 0) {
			expectingAtSign = false;
			countSinceExpecting = 0;
		}
		lastChar = a;
		return true;
	}
}

String Reader::getNextLine()
{
	return lastChar;
}