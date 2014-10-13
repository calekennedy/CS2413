#include "UserInterface.h"

UserInterface::UserInterface()
{
	_entryStore = new EntryStore();
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
	catch (ArrayBoundsException e) {
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
			cout << "\Deleting " << entry.getName() << "...";
			(*_entryStore).removeEntry(entry.getName());
			cout << "\nEntry Deleted.";
			cout << endl << endl;
		}
		else {
			cout << "\nDeletion Aborted.";
			cout << endl << endl;
			return;
		}
	}
	catch (ArrayBoundsException e) {
		cout << "\nNo entry was found with that name.\n";
		cout << endl << endl;
		return;
	}
}

// print - (P)
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
		Vector<Entry*> entries = (*_entryStore).getEntries();
		int size = entries.size();
		for (int i = 0; i < size; i++) {
			(*entries[i]).display();
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


// this will load the user interface and return once the user exits.
void UserInterface::run() {
	cout << "Welcome to Public Scholar v1.0\n";
	readFileIntoDataStore();
	bool exit = false;
	while (!exit) {
		cout << "--------------------------------------------------------------------------------";
		cout << "\nPlease choose from one of the following options.\n";
		cout << "(S) Search, (D) Delete, (P) Print, (E) Exit\n";
		getUserInput();
		String input = (*_userInput);
		if (input.equalsIgnoreCase("E")) {
			exit = true;
		}
		else if (input.equalsIgnoreCase("S")) {
			search();
		}
		else if (input.equalsIgnoreCase("P")) {
			print();
		}
		else if (input.equalsIgnoreCase("D")) {
			remove();
		}
		else {
			cout << "\nChoice not supported. Please choose from one of the supported options. \n";		
		}
	}
	return;
}