#include "EntryStore.h"

EntryStore::EntryStore() 
{
	_entries = new Vector <Entry*>();
};

EntryStore::~EntryStore()
{
	if (_entries != NULL) { delete _entries; }
	if (_entryBuilder != NULL) { delete _entryBuilder;  }
	_entries = NULL;
	_entryBuilder = NULL;
}

int EntryStore::search(const String& entryName)
{
	int firstIndex = 0;
	int lastIndex = ((*_entries).size() - 1);
	return binarySearch(entryName, firstIndex, lastIndex);
};

int EntryStore::binarySearch(const String& entryName, int left, int right)
{
	// return -1 if the entry is not found after performing a binary search
	if (right < left) {
		return -1;
	}
	int distance = right - left / 2;
	int midPoint = left + distance;
	String nameAtIndex = (*(*_entries)[midPoint]).getName();
	if (nameAtIndex == entryName) {
		return midPoint;
	}
	else {
		if (nameAtIndex < entryName) {
			left = midPoint + 1;
		}
		if (nameAtIndex > entryName) {
			right = midPoint - 1;
		}
		return binarySearch(entryName, left, right);
	}	
}

Entry EntryStore::findByName(const String& entryName)
{
	return (*(*_entries)[search(entryName)]);
}

void EntryStore::removeEntry(const String& entryName)
{
	(*_entries).remove(search(entryName));
};

void EntryStore::addEntry(const Entry& entry)
{
	String newEntryname = entry.getName();
	int size = (*_entries).size();
	int insertIndex = size;
	for (int i = 0; i < size; i++) {
		String entryName = (*(*_entries)[i]).getName();
		if (entryName > newEntryname) {
			insertIndex = i;
			break;
		}
	}
	if (insertIndex < size) {
		(*_entries).insert(new Entry(entry), insertIndex);
	}
	else {
		(*_entries).add(new Entry(entry));
	}
};

int EntryStore::numberOfEntries()
{
	return (*_entries).size();
}

Vector<Entry*> EntryStore::getEntries() 
{
	return (*_entries);
}

void EntryStore::loadFromFile(String& fileName)
{
	Entry * newEntry = new Entry;
	_entryBuilder = new EntryBuilder(fileName);
	while (!(*_entryBuilder).hasReachedEndOfFile()) {
		newEntry = (*_entryBuilder).getNextEntry();
		if (newEntry != NULL) {
			addEntry((*newEntry));
		}
	}
}

void EntryStore::writeToFile(String& fileName)
{
	ofstream file;
	file.open(fileName.getRawCharArray());
	int size = (*_entries).size();
	for (int i = 0; i < size; i++) {
		file << (*(*_entries)[i]) << endl;
	}
	file.close();
}