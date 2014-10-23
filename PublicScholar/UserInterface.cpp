#include "UserInterface.h"

UserInterface::UserInterface()
{
	_entryStore = new EntryStoreLL();
	_userInput = new String();
}

UserInterface::~UserInterface()
{
	if (_entryStore != NULL) { delete _entryStore; }
	if (_userInput != NULL) { delete _userInput; }
	_entryStore = NULL;
	_userInput = NULL;
}

// get user input for file
void UserInterface::getUserInput()
{
	char * input = new char[200];
	cout << ">";
	cin >> input;
	delete _userInput;
	_userInput = new String(input);
	delete input;
};

// read file into data store
void UserInterface::readFileIntoDataStore()
{
	cout << "--------------------------------------------------------------------------------";
	cout << "\nPlease enter the name of the file from which you wish to read.\n\n";
	getUserInput();
	cout << "\n loading...";
	(*_entryStore).loadFromFile((*_userInput));
	cout << "\n " << (*_entryStore).numberOfEntries() << " entries were loaded.\n\n";
}

// search - (S)
void UserInterface::search() 
{
	cout << "\nEnter the name of the entry for which you wish to search.\n";
	getUserInput();
	try {
		Entry entry = (*_entryStore).findByName((*_userInput));
		entry.display();
		cout << endl << endl;
	}
	catch (EntryNotFoundException e) {
		cout << "\nNo entry was found with that name.\n";
		cout << endl << endl;
		return;
	}	
}

// delete - (D)
void UserInterface::remove()
{
	cout << "\nEnter the name of the entry you wish to delete.\n";
	getUserInput();
	try {
		Entry entry = (*_entryStore).findByName((*_userInput));
		entry.display();
		cout << endl << endl;
		cout << "\nDo you wish to delete this entry? (Y/N)\n";
		getUserInput();
		if ((*_userInput).equalsIgnoreCase("Y")) {
			cout << "\nDeleting " << entry.getName() << "...";
			_entryStore->removeEntry(entry);
			cout << "\nEntry Deleted.";
			cout << endl << endl;
		}
		else {
			cout << "\nDeletion Aborted.";
			cout << endl << endl;
			return;
		}
	}
	catch (EntryNotFoundException e) {
		cout << "\nNo entry was found with that name.\n";
		cout << endl << endl;
		return;
	}
}

// write - (W)
void UserInterface::print() 
{
	cout << "\nEnter the filename to which we will write (press ENTER to output to console).\n>";
	cin.sync();
	bool stop = false;
	char * userInput = new char[200];
	int index = 0;
	while (!stop) {
		char c;
		cin.get(c);
		userInput[index++] = c;
		if (c == '\n') { 
			stop = true; 
			userInput[--index] = '\0';
		}
	}
	if (userInput[0] == '\0') {
		LinkedList<Entry> * entries = (*_entryStore).getEntries();
		int size = entries->length();
		for (int i = 0; i < size; i++) {
			(*entries)[i].display();
		}
		cout << endl << endl;
	}

	else {		
		_userInput = new String(userInput);
		cout << "Writing to " << (*_userInput) << "...\n";
		(*_entryStore).writeToFile((*_userInput));
		cout << "Write Successful!";
		cout << endl << endl;
	}
}

// merge - (M)
void UserInterface::merge()
{
	// read file into a store
	cout << "\nEnter the filename from which we will merge.\n>";
	getUserInput();
	cout << "\n loading...";
	EntryStoreLL temp = EntryStoreLL();
	temp.loadFromFile((*_userInput));
	cout << "\n " << temp.numberOfEntries() << " entries were loaded from merge file.\n\n";
	LinkedList<Entry> * node = temp.getEntries();
	while (node != NULL) {
		try {
			_entryStore->addEntry(node->remove());
		}
		catch (OutOfBoundsException e) {
			break;
		}
	}
	cout << "\n " << (*_entryStore).numberOfEntries() << " entries in entry store after merge.\n\n";
}

// purge - (P)
void UserInterface::purge()
{
	// read file into a store
	if (_entryStore->numberOfEntries() == 0) {
		cout << "\nNothing to purge." << endl;
		return;
	}
	cout << "\nEnter the filename from which we will purge.\n>";
	getUserInput();
	cout << "\n loading...";
	EntryStoreLL temp = EntryStoreLL();
	temp.loadFromFile((*_userInput));
	cout << "\n " << temp.numberOfEntries() << " entries were loaded from purge file.\n\n";
	LinkedList<Entry> * node = temp.getEntries();
	while (node != NULL) {
		try {
			_entryStore->removeEntry(node->remove());
		}
		catch (OutOfBoundsException e) {
			break;
		}
		catch (EntryNotFoundException e) {
			continue;
		}
	}
	cout << "\n " << (*_entryStore).numberOfEntries() << " entries in entry store after purge.\n\n";
}


// this will load the user interface and return once the user exits.
void UserInterface::run() {
	cout << "Welcome to Public Scholar v1.0\n";
	readFileIntoDataStore();
	bool exit = false;
	while (!exit) {
		cout << "--------------------------------------------------------------------------------";
		cout << "\nPlease choose from one of the following options.\n";
		cout << "(S) Search, (D) Delete, (W) Write, (M) Merge, (P) Purge, (E) Exit\n";
		getUserInput();
		String input = (*_userInput);
		if (input.equalsIgnoreCase("E")) {
			exit = true;
		}
		else if (input.equalsIgnoreCase("S")) {
			search();
		}
		else if (input.equalsIgnoreCase("W")) {
			print();
		}
		else if (input.equalsIgnoreCase("D")) {
			remove();
		}
		else if (input.equalsIgnoreCase("M")) {
			merge();
		}
		else if (input.equalsIgnoreCase("P")) {
			purge();
		}
		else {
			cout << "\nChoice not supported. Please choose from one of the supported options. \n";		
		}
	}
	return;
}