#include "EntryStoreLL.h"


EntryStoreLL::EntryStoreLL()
{
	_entries = new LinkedList<Entry>();
};

EntryStoreLL::~EntryStoreLL()
{
	if (_entries != NULL) {
		delete _entries; 
		_entries = NULL;
	}
	if (_entryBuilder != NULL) { 
		delete _entryBuilder;
		_entryBuilder = NULL;
	}	
}

Entry EntryStoreLL::findByName(const String& entryName)
{
	Entry temp = Entry();
	temp.setName(entryName);
	return find(temp);
}

Entry EntryStoreLL::find(const Entry& e)
{
	LinkedList<Entry> * node = _entries->find(e);
	if (node != NULL) {
		try {
			return (*node).getContents();
		}
		catch (GetNullContentsException e) {
			throw EntryNotFoundException();
		}
	}
	else {
		throw EntryNotFoundException();
	}
}

void EntryStoreLL::removeEntryByName(const String& entryName)
{
	Entry temp = Entry();
	temp.setName(entryName);
	removeEntry(temp);
};

void EntryStoreLL::removeEntry(const Entry& e)
{
	LinkedList<Entry> * node = _entries->find(e);
	if (node) {
		try {
			node->remove();
		}
		catch (Exception e) {
			throw EntryStoreException();
		}
	}
	else {
		throw EntryNotFoundException();
	}

};

void EntryStoreLL::addEntry(const Entry& entry)
{
	if (_entries->isEmpty()) {
		_entries->setContents(entry);
	}
	else {
		LinkedList<Entry> * node = _entries;
		bool stop = false;
		while (node != NULL && !stop) {
			if (node->getContents() == entry) {
				node->setContents(entry);
				stop = true;
			}
			else if ((node->getContents()) > entry) {
				node->prepend(entry);
				stop = true;
			} 
			else if (node->getTail() == NULL) {
				node->append(entry);
				stop = true;
			}
			else {
				node = node->getTail();
			}
		} 
	}
};

int EntryStoreLL::numberOfEntries()
{
	return _entries->length();
}

LinkedList<Entry> * EntryStoreLL::getEntries()
{
	return _entries;
}

void EntryStoreLL::loadFromFile(String& fileName)
{
	Entry * newEntry = new Entry;
	_entryBuilder = new EntryBuilder(fileName);
	while (!(*_entryBuilder).hasReachedEndOfFile()) {
		newEntry = (*_entryBuilder).getNextEntry();
		if (newEntry != NULL) {
			addEntry((*newEntry));
		}		
	}
	delete _entryBuilder;
	_entryBuilder = NULL;
	delete newEntry;
	newEntry = NULL;
}

void EntryStoreLL::writeToFile(String& fileName)
{
	ofstream file;
	file.open(fileName.getRawCharArray());
	LinkedList<Entry> * node = _entries;
	while (node != NULL) {
		file << (*node).getContents();
		node = node->getTail();
	}
	file.close();
}