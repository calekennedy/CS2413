#pragma once
#include "Vector.h"
#include "String.h"
#include "Bibliographic.h"
#include "Author.h"
#include "Doi.h"
#include "Issn.h"
#include "Journal.h"
#include "Month.h"
#include "Number.h"
#include "Pages.h"
#include "Title.h"
#include "Url.h"
#include "UrlDate.h"
#include "Volume.h"
#include "Year.h"

#include "Exception.h"
class EntryException : Exception {};
class FieldNotFound : EntryException {};

class Entry
{
friend ostream& operator << (ostream& s, const Entry& e);

private:
	void displayCounts(); // used to display counts by public display method

protected:
	String * _chunk; // the whole entry as it was read in from the file
	String * _type; // the entry's type
	String * _name; // the entry's name
	Vector<Bibliographic*> * _fields; // the collection of fields on the entry

	// method used internally
	int longestFieldIndex();

	// method used internally
	Bibliographic getField(const String& key);

public:
	// constructor and destructor
	Entry();
	Entry(const Entry& e);
	virtual ~Entry();

	virtual bool operator== (const String& name);
	virtual bool operator== (const Entry& entry);

	virtual bool operator< (const String& name);
	virtual bool operator< (const Entry& entry);

	virtual bool operator> (const String& name);
	virtual bool operator> (const Entry& entry);

	

	// accessors
	virtual String getChunk() const;
	virtual String getType() const;
	virtual String getName() const;

	// mutators
	virtual void setChunk(const String& chunk);	
	virtual void setType(const String& type);	
	virtual void setName(const String& newName);


	virtual Array<Bibliographic> getFields() const;
	virtual void addField(const Bibliographic& b);
	virtual void removeField(int index);

	// project spec'd accessors for specific fields
	virtual Author getAuthor();
	virtual Doi getDoi();
	virtual Issn getIssn();
	virtual Journal getJournal();
	virtual Month getMonth();
	virtual Number getNumber();
	virtual Pages getPages();
	virtual Title getTitle();
	virtual Url getUrl();
	virtual UrlDate getUrlDate();
	virtual Volume getVolume();
	virtual Year getYear();

	// gets the number of fields on the entry
	virtual int numberOfFields();

	// gets the name of the longest field
	virtual String longestFieldName();

	// gets the length of the longest field
	virtual int longestFieldLength();

	// displays the entry
	virtual void display();

};

