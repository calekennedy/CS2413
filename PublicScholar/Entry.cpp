#include "Entry.h"
#include <iostream>
using namespace std;


Entry::Entry()
{
	_chunk = new String();
	_type = new String();
	_name = new String();
	_fields = new Vector<Bibliographic*>();
	
}

Entry::Entry(const Entry& e)
{
	_chunk = new String();
	(*_chunk) = e.getChunk();
	_type = new String();
	(*_type) = e.getType();
	_name = new String();
	(*_name) = e.getName();
	_fields = new Vector<Bibliographic*>();
	(*_fields) = (*e._fields);
}

Entry::~Entry()
{
	// does this call the object's destructor method?
	if (_chunk != NULL) { delete _chunk; }
	if (_type != NULL) { delete _type; }	
	if (_name != NULL) { delete _name; }	
	if (_fields != NULL) { delete _fields; }
	_chunk = NULL;
	_type = NULL;
	_name = NULL;
	_fields = NULL;
}

String Entry::getChunk() const
{
	return (*_chunk);
}

String Entry::getType() const
{
	return (*_type);
}

String Entry::getName() const
{
	return (*_name);
}

Array<Bibliographic> Entry::getFields() const
{
	Vector<Bibliographic> v;
	for (int i = 0; i < (*_fields).size(); i++) {
		v.add((*(*_fields)[i]));
	}
	return v;
}

void Entry::setChunk(const String& newChunk)
{
	(*_chunk) = newChunk;
}

void Entry::setType(const String& newType)
{
	(*_type) = newType;
}

void Entry::setName(const String& newName)
{
	(*_name) = newName;
}

void Entry::addField(const Bibliographic& b)
{
	(*_fields).add(new Bibliographic(b));
}

void Entry::removeField(int index)
{
	(*_fields).remove(index);
}

int Entry::numberOfFields()
{
	return (*_fields).size();
}

int Entry::longestFieldIndex() {
	int longestIndex = 0;
	for (int i = 1; i < (*_fields).size(); i++) {
		int current = (*(*_fields)[i]).getValue().size();
		int longest = (*(*_fields)[longestIndex]).getValue().size();
		if (current > longest) {
			longestIndex = i;
		}
	}
	return longestIndex;
}

String Entry::longestFieldName()
{
	return (*(*_fields)[longestFieldIndex()]).getKey();
}

int Entry::longestFieldLength()
{
	return (*(*_fields)[longestFieldIndex()]).size();
}

void Entry::display()
{
	cout << "\n@";
	cout << (*_type);
	cout << '{';
	cout << (*_name);
	cout << "," << endl;
	for (int i = 0; i < numberOfFields(); i++) {
		(*(*_fields)[i]).display();
		cout << endl;
	}
	displayCounts();
	cout << endl << "}";
}

Bibliographic Entry::getField(const String& key)
{
	for (int i = 0; i < (*_fields).size(); i++) {
		if ((*(*_fields)[i]).getKey() == key) {
			return (*(*_fields)[i]);
		}
	}
	return Bibliographic(); // return an empty field if we don't find it
}

// call get field and cast it to the correct type.
Author	Entry::getAuthor()	{ return getField("author");	}
Doi		Entry::getDoi()		{ return getField("doi");		}
Issn	Entry::getIssn()	{ return getField("issn");		}
Journal Entry::getJournal() { return getField("journal");	}
Month	Entry::getMonth()	{ return getField("month");		}
Number	Entry::getNumber()	{ return getField("number");	}
Pages	Entry::getPages()	{ return getField("pages");		}
Title	Entry::getTitle()	{ return getField("title");		}
Url		Entry::getUrl()		{ return getField("url");		}
UrlDate Entry::getUrlDate() { return getField("urldate");	}
Volume	Entry::getVolume()	{ return getField("volume");	}
Year	Entry::getYear()	{ return getField("year");		}

void Entry::displayCounts()
{
	cout << "\tcounts = {";
	cout << "fields: " << numberOfFields();
	cout << " authors: " << getAuthor().size();
	cout << " longest field: " << longestFieldName();
	cout << " length: " << longestFieldLength();
	cout << "}" << endl;
}

ostream& operator << (ostream& s, const Entry& e)
{
	Entry entry = Entry(e);
	int size = entry.numberOfFields();
	s << "\n@";
	s << entry.getType();
	s << '{';
	s << entry.getName();
	s << "," << endl;
	for (int i = 0; i < size; i++) {
		s << entry.getFields()[i] << endl;
	}
	s << "\tcounts = {";
	s << "fields: " << entry.numberOfFields();
	s << " authors: " << entry.getAuthor().size();
	s << " longest field: " << entry.longestFieldName();
	s << " length: " << entry.longestFieldLength();
	s << "}" << endl;
	s << "}" << endl;
	return s;
}


