#include "EntryStoreLL.h"
#include <iostream>

using namespace std;

class UserInterface
{
private:

	// data store
	EntryStoreLL * _entryStore;

	// user input
	String * _userInput;

	// get user input for file
	void getUserInput();

	// read file into data store
	void readFileIntoDataStore();

	// search - (S)
	void search();
		// get user input for Entry Name
		// binary search data store for entry
		// if found display the entry
		// if not found inform user

	// delete - (D)
	void remove();
		// get user input for Entry Name
		// binary search data store for entry
		// if found display the entry
		// if not found inform user
		// user will confirm deletion (Y/N)

	// write - (W)
	void print();
		// get user input for Output Location
		// If file name is provided, write entire data store to that file
		// If file name is not provided, output to std out

	// merge - (M)
	void merge();
		// gets user input for location of merge file
		// If file name is provided, load contents of file into a new EntryStoreLL data structure
		// For each entry in the new ESLL object, add the file to the original ESLL
		// If the entry already exists, overwrite it with the entry in the mergefile

	// purge - (P)
	void purge();
		// gets user input for location of purge file
		// If file name is provided, load contents of file into a new EntryStoreLL data structure
		// For each entry in the new ESLL object, attempt to remove it from the origial ESLL


	// exit - (E)
	void exit();

public:
	// constructor and destructor
	UserInterface();
	~UserInterface();

	// this will load the user interface and return once the user exits.
	void run();
};
