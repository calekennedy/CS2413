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

bool Entry::operator==(const String& name)
{
	return (*_name) == name;
}

bool Entry::operator==(const Entry& entry)
{
	return Entry::operator==((*entry._name));
}

bool Entry::operator< (const String& name)
{
	return (*_name) < name;
}

bool Entry::operator< (const Entry& entry)
{
	return Entry::operator<((*entry._name));
}

bool Entry::operator> (const String& name)
{
	return (*_name) > name;
}

bool Entry::operator> (const Entry& entry)
{
	return Entry::operator>((*entry._name));
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
		String fieldName = (*(*_fields)[i]).getKey();
		if (fieldName == key) {
			return (*(*_fields)[i]);
		}
	}
	throw FieldNotFound();
}

// call get field and cast it to the correct type.
Author	Entry::getAuthor()	{ return getField(String("author"));	}
Doi		Entry::getDoi()		{ return getField(String("doi"));		}
Issn	Entry::getIssn()	{ return getField(String("issn"));		}
Journal Entry::getJournal() { return getField(String("journal"));	}
Month	Entry::getMonth()	{ return getField(String("month"));		}
Number	Entry::getNumber()	{ return getField(String("number"));	}
Pages	Entry::getPages()	{ return getField(String("pages"));		}
Title	Entry::getTitle()	{ return getField(String("title"));		}
Url		Entry::getUrl()		{ return getField(String("url"));		}
UrlDate Entry::getUrlDate() { return getField(String("urldate"));	}
Volume	Entry::getVolume()	{ return getField(String("volume"));	}
Year	Entry::getYear()	{ return getField(String("year"));		}

void Entry::displayCounts()
{
	cout << "\tcounts = {";
	cout << "fields: " << numberOfFields();
	try { cout << " authors: " << getAuthor().size(); }
	catch (FieldNotFound) { cout << " authors: " << 0; }
	cout << " longest field: " << longestFieldName();
	cout << " length: " << longestFieldLength();
	cout << "}" << endl;
}

ostream& operator << (ostream& s, const Entry& e)
{
	int size = (*e._fields).size();
	s << "\n@";
	s << (*e._type);
	s << '{';
	s << (*e._name);
	s << "," << endl;
	for (int i = 0; i < size; i++) {
		Bibliographic field = (*(*e._fields)[i]);
		s << field << endl;
	}
	s << "\tcounts = {";
	s << "fields: " << size;
	try { s << " authors: " << ((Entry)e).getAuthor().size(); }
	catch (FieldNotFound e) { s << " authors: " << 0; }	
	s << " longest field: " << ((Entry)e).longestFieldName();
	s << " length: " << ((Entry)e).longestFieldLength();
	s << "}" << endl;
	s << "}" << endl;
	return s;
}


